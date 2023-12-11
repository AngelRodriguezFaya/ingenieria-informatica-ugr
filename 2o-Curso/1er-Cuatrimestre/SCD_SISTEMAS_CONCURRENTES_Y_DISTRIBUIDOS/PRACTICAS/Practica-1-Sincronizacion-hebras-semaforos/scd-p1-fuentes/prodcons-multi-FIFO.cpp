// -----------------------------------------------------------------------------
// Plantilla modificada por ÁNGEL RODRÍGUEZ FAYA.
// FECHA: 12/11/23
// Se completa el problema de los múltiples productores-consumidores con un 
// buffer para guardar los datos. Se realiza mediante FIFO(primero en entrar es 
// el primero en salir).
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
    num_items   = 40 ,          // número de items
    tam_vec     = 10 ,          // tamaño del buffer
    np          = 4  ,          // número de hebras productoras
    nc          = 4  ,          // número de hebras consumidoras
    p           = num_items/np, // número de items a producir por cada hebra
    c           = num_items/nc; // número de items a consumir por cada hebra
unsigned  
    cont_prod[num_items] = {0}, // contadores de verificación: para cada dato, número de veces que se ha producido.
    cont_cons[num_items] = {0}, // contadores de verificación: para cada dato, número de veces que se ha consumido.
    siguiente_dato       = 0  , // siguiente dato a producir en 'producir_dato' (solo se usa ahí)
    vec[tam_vec]              , // vector para escribir/leer los datos.
    primera_libre        = 0  , // primera celda libre del vector. ++ al escribir
    primera_ocupada      = 0  , // índice de primera celda ocupada del vector. ++ al leer.
    items_producidos[np] = {0}; // nº intems producidos por cada hebra productora.

Semaphore
    libres   = tam_vec, // num. entradas libres { k + #L + #E }
    ocupadas = 0;       // num. entradas ocupadas { #E + #L }

//**********************************************************************
// funciones comunes a las dos soluciones (fifo y lifo)
//----------------------------------------------------------------------

unsigned producir_dato(unsigned ind_p)
{   
    /*Cada hebra debe de producir todos los valores de un rango, que dicho rango 
     * vendrá dado por el total de items entre el número de hebras (se repartirá 
     * el trabajo). Cada hebra los calculará de forma CONTIGUA, como se vio en el
     * Seminario 1.
     * Por eso, en la constante dato_producido, en vez de ir de 1 en 1 como antes,
     * ahora se cogerá el valor anterior, que es el que está en items_producidos[ind_p]
     * (que empieza en 0, y se va incrementando de 1 en 1) y se le va sumando un 
     * valor contante que será el índice de la hebra productora por el número de 
     * items a producir por cada hebra
     * Por ejemplo, como está ahora, si el indide de la hebra es 1, y hay 8 items,
     * por lo que si hay dos hebras, cada una producira 4 items, p = 4, tenemos:
     * (Iteración 1) = dato_producido = items_producidos[ind_p](0) + ind_p(1) + p(4) = 5;
     *                 item_producidos[ind_p]++;
     * (Iteración 2) = dato_producido = items_producidos[ind_p](1) + ind_p(1) + p(4) = 6;
     *                  item_producidos[ind_p]++;
     * .
     * .
     * .
     */
    assert (ind_p < np);   // Verifico que el índice de la hebra es menor que el núm. de hebras productoras.
    this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
    const unsigned inicio = ind_p * p;  // valor inicial.
    const unsigned dato_producido = items_producidos[ind_p] + inicio;
    items_producidos[ind_p]++;
    cont_prod[dato_producido] ++ ;
    cout << "\nproducido: " << dato_producido << " por la hebra nº" << ind_p << endl << flush ;
    return dato_producido;
}
//----------------------------------------------------------------------

void consumir_dato( unsigned dato, unsigned ind_c )
{   
    assert ( ind_c < nc);
    assert( dato < num_items );
    cont_cons[dato] ++ ;
    this_thread::sleep_for( chrono::milliseconds( aleatorio<20,100>() ));
    cout << "\n                  consumido: " << dato << " por la hebra nº " << ind_c << endl ;
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

void  funcion_hebra_productora( int ind_p )
{   
    
    for( unsigned i = 0 ; i < p ; i++ ) // Condición: mientras que i no se supere el número
    // máximo de items que tiene que producir cada hebra. Si lo supera, estaría
    // calculando items que corresponden a otra hebra.
    {
      int dato = producir_dato(ind_p) ;
      // completar ......
      sem_wait(libres);
      vec[primera_libre] = dato;
      cout << "\nInsertado '" << dato << "' en el vector, por la hebra nº" << ind_p << "\n";
      primera_libre = (primera_libre + 1) % tam_vec;
      sem_signal(ocupadas);
    }
}

//----------------------------------------------------------------------

void funcion_hebra_consumidora( unsigned ind_c )
{
   for( unsigned i = 0 ; i < p ; i++ )
   {
      int dato ;
      // completar ......
      sem_wait(ocupadas);
      dato = vec[primera_ocupada];
      cout << "\n                  Extraído '" << dato << "' del vector, por la hebra nº"
              << ind_c << "\n";
      primera_ocupada = (primera_ocupada + 1) % tam_vec;
      sem_signal(libres);
      consumir_dato( dato, ind_c ) ;
    }
}
//----------------------------------------------------------------------

int main()
{
   cout << "-------------------------------------------------------------------" << endl
        << "Problema de los múltiples productores-consumidores (solución FIFO)." << endl
        << "-------------------------------------------------------------------" << endl
        << flush ;
    thread hebras_productoras[np],
            hebras_consumidoras[nc];
    for(int i = 0; i < np; i++)  // Lanzo las hebras productoras.
        hebras_productoras[i] = thread( funcion_hebra_productora, i );
   
    for(int i = 0; i < nc; i++)  // Lanzo las hebras consumidoras.
        hebras_consumidoras[i] = thread( funcion_hebra_consumidora, i);

    for(int i = 0; i < np; i++)  // Finalizo las hebras productoras.
        hebras_productoras[i].join();
    
    for(int i = 0; i < nc; i++)  // Finalizo las hebras consumidoras.
        hebras_consumidoras[i].join();

    cout << "\nFin.\n" << endl;

    test_contadores();
}
