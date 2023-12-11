// -----------------------------------------------------------------------------
// Examen resuelto por ÁNGEL RODRÍGUEZ FAYA.
// FECHA: 13/11/23
// Se completa el problema planteado en el Simulacro/Examen de la P1 de SCD.
// Se trata de añadir una hebra sanitaria al problema que interactua con los demás.
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

Semaphore
    mostr_vacio = 1,    // 1 si mostrador está vacío, 0 si no. {0 <= 1 + #Ri - #Pi}
    ingr_disp[num_fumadores] = {0, 0, 0}, // 1 si ingrediente está disponible, 0 si no. {#Pi - #Ri}
    sanitaria = 0,      // Hebra sanitaria.
    puede_fumar = 0;    // Dar paso o no al fumador. 

int
    numero_cigarrillos[num_fumadores] = {0, 0, 0}, // contador de cigarrillos por cada fumador.
    fumador_vicioso;                               // fumador que despierta a la hebra sanitaria.
//-------------------------------------------------------------------------
// Función que simula la acción de producir un ingrediente, como un retardo
// aleatorio de la hebra (devuelve número de ingrediente producido)

int producir_ingrediente()
{
   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_produ( aleatorio<10,100>() );

   // informa de que comienza a producir
   cout << "Estanquero : empieza a producir ingrediente (" << duracion_produ.count() << " milisegundos)\n" << endl;

   // espera bloqueada un tiempo igual a ''duracion_produ' milisegundos
   this_thread::sleep_for( duracion_produ );

   const int num_ingrediente = aleatorio<0,num_fumadores-1>() ;

   // informa de que ha terminado de producir
   cout << "Estanquero : termina de producir ingrediente " << num_ingrediente << endl << endl;

   return num_ingrediente ;
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(  )
{   
    while( true )
    {
        int i;
        i = producir_ingrediente();
        sem_wait(mostr_vacio);
        cout << "\nEstanquero produce ingrediente '" << i << "'.\n" << endl;
        sem_signal(ingr_disp[i]);
    }
}

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)\n" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente.\n" << endl;

}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( int num_fumador )
{
   while( true )
   {    
       sem_wait(ingr_disp[num_fumador]);
       
       if(numero_cigarrillos[num_fumador] == 5){
           fumador_vicioso = num_fumador;
           sem_signal(sanitaria);   // Desbloqueo a la hebra sanitaria.
           sem_wait(puede_fumar);   // Bloqueo al fumador hasta que la hebra sanitaria termine y lo desbloquee.

           cout << "\n\n\t\tSoy el fumador'" << fumador_vicioso << "' y me han llamado vicioso.\n" << endl;
           numero_cigarrillos[num_fumador] = 0; //reinicio el contador de cigarros a 0.
       }
       
       cout << "\nFumador '" << num_fumador << "' retira su ingrediente del mostrador\n" <<endl;
       sem_signal(mostr_vacio);
       
       fumar(num_fumador);
       numero_cigarrillos[num_fumador]++; //Un cigarrillo fumado más
       cout << "\n\t\tFumador " << num_fumador << "  : ha fumado " << numero_cigarrillos[num_fumador] << " cigarrillos seguidos\n\n" << endl;
   }
}

//----------------------------------------------------------------------
// función que ejecuta la hebra sanitaria.
void funcion_hebra_sanitaria()
{
    sem_wait(sanitaria);        // Bloqueo a la hebra sanitaria.
    cout << "\n\n\t\tFUMAR MATA: ya lo sabes, fumador'" << fumador_vicioso << "'.\n" << endl;
    sem_signal(puede_fumar);    // Desbloqueo al fumador para que siga fumando.
}


//----------------------------------------------------------------------

int main()
{   
    //Declaro las hebras.
    thread hebra_estanquero(funcion_hebra_estanquero),
           hebra_sanitaria(funcion_hebra_sanitaria),
           hebras_fumadoras[num_fumadores];
    
    //Pongo en marcha las hebras fumadoras.
    for(int i = 0; i < num_fumadores; i++)
        hebras_fumadoras[i] = thread(funcion_hebra_fumador, i);
    
    //Finalizo las hebras
    hebra_estanquero.join();
    hebra_sanitaria.join();
    for(int i = 0; i < num_fumadores; i++)
        hebras_fumadoras[i].join();
}
