// -----------------------------------------------------------------------------
// Plantilla modificada por ÁNGEL RODRÍGUEZ FAYA.
// FECHA: 13/11/23
// Se completa el problema de las hebras fumadores y la hebra estanquero.
// -----------------------------------------------------------------------------

#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "scd.h"

using namespace std ;
using namespace scd ;

// numero de fumadores 

const int num_fumadores = 3 ;

//-------------------------------------------------------------------------
// Función que simula la acción de producir un ingrediente, como un retardo
// aleatorio de la hebra (devuelve número de ingrediente producido)

int producir_ingrediente()
{
   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_produ( aleatorio<10,100>() );

   // informa de que comienza a producir
   cout << "Estanquero : empieza a producir ingrediente (" << duracion_produ.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_produ' milisegundos
   this_thread::sleep_for( duracion_produ );

   const int num_ingrediente = aleatorio<0,num_fumadores-1>() ;

   // informa de que ha terminado de producir
   cout << "Estanquero : termina de producir ingrediente " << num_ingrediente << endl;

   return num_ingrediente ;
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;

}

//----------------------------------------------------------------------
// clase para monitor buffer, version FIFO, semántica SU, fumadores.
class Estanco : public HoareMonitor
{
 private:
    int                        // variables permanentes
        ingre_mostrador;       // número de ingrediente que hay en el mostrador
    CondVar                     // colas condicion:
        mostr_vacio,                //  cola donde espera el estanquero.
        ingr_disp[num_fumadores];   //  cola donde esperan los fumadores.

 public:                    // constructor y métodos públicos
   Estanco() ;             // constructor
   void obtenerIngrediente(int ingre);               
   void ponerIngrediente(int ingre);
   void esperarRecogidaIngrediente();
} ;

//----------------------------------------------------------------------
Estanco::Estanco(){
    ingre_mostrador = -1;
    for(int i = 0; i < num_fumadores; i++)
        ingr_disp[i] = newCondVar();
    
    mostr_vacio = newCondVar();
}

//----------------------------------------------------------------------
void Estanco::obtenerIngrediente(int ingre){
    if(ingre_mostrador != ingre)
        ingr_disp[ingre].wait();
    ingre_mostrador = -1;
    cout << "\nFumador '" << ingre << "' retira su ingrediente del mostrador\n" <<endl;
    mostr_vacio.signal();
}

//----------------------------------------------------------------------
void Estanco::ponerIngrediente(int ingre){
    if(ingre_mostrador != -1) // si el mostrador no está vacio...
        mostr_vacio.wait();
    ingre_mostrador = ingre;
    cout << "\nEstanquero produce ingrediente '" << ingre << "'." << endl;
    ingr_disp[ingre].signal();
}

//----------------------------------------------------------------------
void Estanco::esperarRecogidaIngrediente(){
    if(ingre_mostrador != -1) // si el mostrador no está vacio...
        mostr_vacio.wait();
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( MRef<Estanco> monitor, int num_fumador )
{
   while( true )
   {
       monitor->obtenerIngrediente(num_fumador);
       cout << "\nFumador '" << num_fumador << "' retira su ingrediente del mostrador\n" <<endl;
       fumar(num_fumador);
   }
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero( MRef<Estanco> monitor )
{   
    while( true )
    {
        int ingre = producir_ingrediente();
        monitor->ponerIngrediente(ingre);
        monitor->esperarRecogidaIngrediente();
    }
}

//----------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------------------" << endl
        << "        Problema del los fumadores (Monitor SU).                    " << endl
        << "--------------------------------------------------------------------" << endl
        << flush ;
   
    // crear monitor  ('monitor' es una referencia al mismo, de tipo MRef<...>)
    MRef<Estanco> monitor = Create<Estanco>() ;
    
    thread hebra_estanquero,
            hebras_fumadoras[num_fumadores];
    
    hebra_estanquero = thread(funcion_hebra_estanquero, monitor);
    
    for(int i = 0; i < num_fumadores; i++)
        hebras_fumadoras[i] = thread(funcion_hebra_fumador, monitor, i);
    
    hebra_estanquero.join();
    for(int i = 0; i < num_fumadores; i++)
        hebras_fumadoras[i].join();
}
