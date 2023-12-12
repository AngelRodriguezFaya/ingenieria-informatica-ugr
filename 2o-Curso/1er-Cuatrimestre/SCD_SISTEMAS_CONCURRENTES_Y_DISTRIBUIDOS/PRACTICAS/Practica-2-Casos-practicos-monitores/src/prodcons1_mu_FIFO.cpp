// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Seminario 2. Introducción a los monitores en C++11.
//
// Archivo: prodcons1_su.cpp
//
// Ejemplo de un monitor en C++11 con semántica SU, para el problema
// del productor/consumidor, con productor y consumidor únicos.
// Opcion LIFO
//
// Historial:
// Creado el 30 Sept de 2022. (adaptado de prodcons2_su.cpp)
// 20 oct 22 --> paso este archivo de FIFO a LIFO, para que se corresponda con lo que dicen las transparencias
// -----------------------------------------------------------------------------------
// Plantilla modificada por ÁNGEL RODRÍGUEZ FAYA.
// Se realiza el problema de los múltiples productores consumidores con monitores.
// Se hace con FIFO(primero en entrar es el primero en salir).
// -----------------------------------------------------------------------------


#include <iostream>
#include <iomanip>
#include <cassert>
#include <random>
#include <thread>
#include "scd.h"

using namespace std ;
using namespace scd ;

constexpr int
    num_items = 15 ,   // número de items a producir/consumir.
    np        = 5  ,   // número de hebras productoras.
    nc        = 5  ;   // número de hebras consumidoras.
int
    siguiente_dato = 0 , // siguiente valor a devolver en 'producir_dato'
    p = num_items/np,    // número de items por cada hebra productora.
    c = num_items/nc,    // número de items por cada hebra consumidora.
    items_producidos[np] = {0};     // contador de items producidos por cada hebra
   
constexpr int               
   min_ms    = 5,     // tiempo minimo de espera en sleep_for
   max_ms    = 20 ;   // tiempo máximo de espera en sleep_for


mutex
   mtx ;                 // mutex de escritura en pantalla
unsigned
   cont_prod[num_items] = {0}, // contadores de verificación: producidos
   cont_cons[num_items] = {0}; // contadores de verificación: consumidos

//**********************************************************************
// funciones comunes a las dos soluciones (fifo y lifo)
//----------------------------------------------------------------------

int producir_dato(int ih)
{

    assert (ih < np);   // Verifico que el índice de la hebra es menor que el núm. de hebras productoras.
    this_thread::sleep_for( chrono::milliseconds( aleatorio<min_ms,max_ms>() ));
    const int inicio = ih*p;
    const int valor_producido = items_producidos[ih] + inicio;
    items_producidos[ih]++;
    mtx.lock();
    cout << "hebra productora nº'" << ih << "' produce " << valor_producido << endl << flush ;
    mtx.unlock();
    cont_prod[valor_producido]++ ;
    return valor_producido ;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned valor_consumir, int ih)
{   
    assert(ih < nc);
    if ( num_items <= valor_consumir )
    {
        cout << " valor a consumir === " << valor_consumir << ", num_items == " << num_items << endl ;
        assert( valor_consumir < num_items );
    }
    cont_cons[valor_consumir] ++ ;
    this_thread::sleep_for( chrono::milliseconds( aleatorio<min_ms,max_ms>() ));
    mtx.lock();
    cout << "                  hebra consumidora nº'" << ih << "' consume: " << valor_consumir << endl ;
    mtx.unlock();
}
//----------------------------------------------------------------------

void test_contadores()
{
   bool ok = true ;
   cout << "comprobando contadores ...." << endl ;

   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      if ( cont_prod[i] != 1 )
      {
         cout << "error: valor " << i << " producido " << cont_prod[i] << " veces." << endl ;
         ok = false ;
      }
      if ( cont_cons[i] != 1 )
      {
         cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces" << endl ;
         ok = false ;
      }
   }
   if (ok)
      cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

// *****************************************************************************
// clase para monitor buffer, version FIFO, semántica SC, multiples prod/cons

class ProdConsMu : public HoareMonitor
{
 private:
 static const int           // constantes ('static' ya que no dependen de la instancia)
   num_celdas_total = 10;   //   núm. de entradas del buffer
 int                        // variables permanentes
   buffer[num_celdas_total],//   buffer de tamaño fijo, con los datos
   primera_libre ,          //   indice de celda de la próxima inserción 
   primera_ocupada,         //   indice de celda de la próxima extracción.
   n;                       //   ( == número de celdas ocupadas)
 
 CondVar                    // colas condicion:
   ocupadas,                //  cola donde espera el consumidor (n>0)
   libres ;                 //  cola donde espera el productor  (n<num_celdas_total)

 public:                    // constructor y métodos públicos
   ProdConsMu() ;             // constructor
   int  leer();                // extraer un valor (sentencia L) (consumidor)
   void escribir( int valor ); // insertar un valor (sentencia E) (productor)
} ;
// -----------------------------------------------------------------------------

ProdConsMu::ProdConsMu(  )
{
   primera_libre = 0 ;
   ocupadas      = newCondVar();
   libres        = newCondVar();
}
// -----------------------------------------------------------------------------
// función llamada por el consumidor para extraer un dato

int ProdConsMu::leer(  )
{
   // esperar bloqueado hasta que 0 < primera_libre
   if ( n == 0 )
      ocupadas.wait();

   cout << "leer: ocup == " << n << ", total == " << num_celdas_total << endl ;
   assert( 0 < n  );

   // hacer la operación de lectura, actualizando estado del monitor
   const int valor = buffer[primera_ocupada] ;
   n--;
   primera_ocupada = (primera_ocupada+1) % num_celdas_total;
   
   // señalar al productor que hay un hueco libre, por si está esperando
   libres.signal();

   // devolver valor
   return valor ;
}
// -----------------------------------------------------------------------------

void ProdConsMu::escribir( int valor )
{
   // esperar bloqueado hasta que primera_libre < num_celdas_total
   if ( primera_libre == num_celdas_total )
      libres.wait();

   cout << "escribir: ocup == " << n << ", total == " << num_celdas_total << endl ;
   assert( primera_libre < num_celdas_total );

   // hacer la operación de inserción, actualizando estado del monitor
   buffer[primera_libre] = valor ;
   primera_libre = (primera_libre+1) % num_celdas_total ;
   n++;
   
   // señalar al consumidor que ya hay una celda ocupada (por si esta esperando)
   ocupadas.signal();
}
// *****************************************************************************
// funciones de hebras

void funcion_hebra_productora( MRef<ProdConsMu> monitor, int ih )
{
   for( unsigned i = ih*p; i < ((ih*p)+p) ; i++ )
   {
      int valor = producir_dato(ih) ;
      monitor->escribir( valor );
   }
}
// -----------------------------------------------------------------------------

void funcion_hebra_consumidora( MRef<ProdConsMu>  monitor, int ih )
{
   for( unsigned i = ih*c; i < ((ih*c)+c) ; i++ )
   {
      int valor = monitor->leer();
      consumir_dato( valor, ih ) ;
   }
}
// -----------------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------------------" << endl
        << "Problema del productor-consumidor únicos (Monitor SU, buffer LIFO). " << endl
        << "--------------------------------------------------------------------" << endl
        << flush ;

    // crear monitor  ('monitor' es una referencia al mismo, de tipo MRef<...>)
    MRef<ProdConsMu> monitor = Create<ProdConsMu>() ;
   
   
    // crear y lanzar las hebras
    thread hebras_prod[np],
          hebras_cons[nc];
    for(int i = 0; i < np; i++)
        hebras_prod[i] = thread( funcion_hebra_productora, monitor, i);
          
    for(int i = 0; i < nc; i++)
        hebras_cons[i] = thread( funcion_hebra_consumidora, monitor, i);

   // esperar a que terminen las hebras
    for(int i = 0; i < np; i++)
        hebras_prod[i].join();
    
    for(int i = 0; i < nc; i++)
        hebras_cons[i].join();

   test_contadores() ;
}
