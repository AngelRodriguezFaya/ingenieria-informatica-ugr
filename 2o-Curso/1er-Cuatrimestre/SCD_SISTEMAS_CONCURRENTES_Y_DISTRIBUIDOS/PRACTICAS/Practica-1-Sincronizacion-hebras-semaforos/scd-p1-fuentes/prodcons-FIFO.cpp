// -----------------------------------------------------------------------------
// Plantilla modificada por ÁNGEL RODRÍGUEZ FAYA.
// FECHA: 12/11/23
// Se completa el problema del productor-consumidor con un buffer para guardar 
// los datos. Se realiza mediante FIFO(primero en entrar es el primero en salir).
// -----------------------------------------------------------------------------

#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random>
#include "scd.h"

using namespace std ;
using namespace scd ;

//**********************************************************************
// Variables globales

const unsigned 
   num_items = 40 ,   // número de items
   tam_vec   = 10 ;   // tamaño del buffer
unsigned  
   cont_prod[num_items] = {0}, // contadores de verificación: para cada dato, número de veces que se ha producido.
   cont_cons[num_items] = {0}, // contadores de verificación: para cada dato, número de veces que se ha consumido.
   siguiente_dato       = 0 ;  // siguiente dato a producir en 'producir_dato' (solo se usa ahí)

int 
    vec[tam_vec],
    primera_libre   = 0,  // índice de primera celda libre del vector. ++ al escribir.
    primera_ocupada = 0;  // índice de primera celda ocupada del vector. ++ al leer.
    // Al hacer el programa de modo FIFO(cola circular) hay que comprobar que 
    // no nos salimos del vector, para ello hacemos modulo tam_vec.

Semaphore
    libres   = tam_vec, // num. entradas libres { k + #L + #E }
    ocupadas = 0;       // num. entradas ocupadas { #E + #L }
//**********************************************************************
// funciones comunes a las dos soluciones (fifo y lifo)
//----------------------------------------------------------------------

unsigned producir_dato()
{
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
   const unsigned dato_producido = siguiente_dato ;
   siguiente_dato++ ;
   cont_prod[dato_producido] ++ ;
   cout << "producido: " << dato_producido << endl << flush ;
   return dato_producido ;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato )
{
   assert( dato < num_items );
   cont_cons[dato] ++ ;
   this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));

   cout << "                  consumido: " << dato << endl ;

}


//----------------------------------------------------------------------

void test_contadores()
{
   bool ok = true ;
   cout << "comprobando contadores ...." ;
   for( unsigned i = 0 ; i < num_items ; i++ )
   {  if ( cont_prod[i] != 1 )
      {  cout << "error: valor " << i << " producido " << cont_prod[i] << " veces." << endl ;
         ok = false ;
      }
      if ( cont_cons[i] != 1 )
      {  cout << "error: valor " << i << " consumido " << cont_cons[i] << " veces" << endl ;
         ok = false ;
      }
   }
   if (ok)
      cout << endl << flush << "solución (aparentemente) correcta." << endl << flush ;
}

//----------------------------------------------------------------------

void  funcion_hebra_productora(  )
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato = producir_dato() ;
      // completar ........
      sem_wait(libres);
      vec[primera_libre] = dato;
      cout << "\nInsertado '" << dato << "' en el vector. \n";
      primera_libre = (primera_libre + 1) % tam_vec;   // cola circular.
      sem_signal(ocupadas);
   }
}

//----------------------------------------------------------------------

void funcion_hebra_consumidora(  )
{
   for( unsigned i = 0 ; i < num_items ; i++ )
   {
      int dato ;
      // completar ......
      sem_wait(ocupadas);
      dato = vec[primera_ocupada];
      cout << "\n                  Extraído '" << dato << "' del vector. \n";
      primera_ocupada = (primera_ocupada + 1) % tam_vec;  // cola circular
      sem_signal(libres);
      consumir_dato( dato ) ;
    }
}
//----------------------------------------------------------------------

int main()
{
   cout << "-----------------------------------------------------------------" << endl
        << "Problema de los productores-consumidores (solución FIFO)." << endl
        << "------------------------------------------------------------------" << endl
        << flush ;

   thread hebra_productora ( funcion_hebra_productora ),
          hebra_consumidora( funcion_hebra_consumidora );

   hebra_productora.join() ;
   hebra_consumidora.join() ;

   cout << "\nFin.\n" << endl;

   test_contadores();
}
