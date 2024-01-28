// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 3. Implementación de algoritmos distribuidos con MPI
//
// Archivo: filosofos-plantilla.cpp
// Implementación del problema de los filósofos (sin camarero).
// Plantilla para completar.
//
// Historial:
// Actualizado a C++11 en Septiembre de 2017
// -----------------------------------------------------------------------------
// Plantilla modificada por ÁNGEL RODRÍGUEZ FAYA.
// Implementar una solución distribuida al problema de los filósofos de basado
// en un proceso camarero con espera selectiva. La espera selectiva se consigue 
// con el uso de etiquetas.
// -----------------------------------------------------------------------------

#include <mpi.h>
#include <thread> // this_thread::sleep_for
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include <iostream>

using namespace std;
using namespace std::this_thread ;
using namespace std::chrono ;

const int
    num_filosofos = 5 ,              // número de filósofos 
    num_filo_ten  = 2*num_filosofos, // número de filósofos y tenedores 
    num_procesos  = num_filo_ten + 1,// número de procesos total (filo, ten y cam)
    // Añadido a la plantilla:
    etiq_fi_coge = 0,                // etiqueta de que el filosofo coge el tenedor
    etiq_fi_suelta = 1,              // etiqueta de que el filosofo suelta el tenedor
    // Añadido a la solución con el camarero
    etiq_sentarse = 2,               // etiqueta de que el filosofo se sienta en la mesa
    etiq_levantarse = 3,             // etiqueta de que el filosofo se levanta de la mesa
    id_camarero = 10;                // identificador del camarero.

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

// ---------------------------------------------------------------------

void funcion_filosofos( int id )
{
  int id_ten_izq = (id+1)              % num_filo_ten, //id. tenedor izq.
      id_ten_der = (id+num_filo_ten-1) % num_filo_ten, //id. tenedor der.
      valor;

  while ( true ){ 
      // 1
      
      cout <<"Filósofo " <<id << " solicita sentarse."<<endl;
      // Solicitar si puede sentarse en la mesa.
      MPI_Ssend( &valor, 1, MPI_INT, id_camarero, etiq_sentarse, MPI_COMM_WORLD);
      
      // 2
      
      cout <<"Filósofo " <<id << " solicita ten. izq." <<id_ten_izq <<endl;
      // ... solicitar tenedor izquierdo (completar)
      MPI_Ssend( &valor, 1, MPI_INT, id_ten_izq, etiq_fi_coge, MPI_COMM_WORLD);

      cout <<"Filósofo " <<id <<" solicita ten. der." <<id_ten_der <<endl;
      // ... solicitar tenedor derecho (completar)
      MPI_Ssend( &valor, 1, MPI_INT, id_ten_der, etiq_fi_coge, MPI_COMM_WORLD);
      
      // 3
      
      cout <<"Filósofo " <<id <<" comienza a comer" <<endl ;
      sleep_for( milliseconds( aleatorio<10,100>() ) );
      
      // 4
      
      cout <<"Filósofo " <<id <<" suelta ten. izq. " <<id_ten_izq <<endl;
      // ... soltar el tenedor izquierdo (completar)
      MPI_Ssend( &valor, 1, MPI_INT, id_ten_izq, etiq_fi_suelta, MPI_COMM_WORLD);

      cout<< "Filósofo " <<id <<" suelta ten. der. " <<id_ten_der <<endl;
      // ... soltar el tenedor derecho (completar)
      MPI_Ssend( &valor, 1, MPI_INT, id_ten_der, etiq_fi_suelta, MPI_COMM_WORLD);
      
      // 5
      
      cout <<"Filósofo " <<id << " solicita levantarse."<<endl;
      // Solicitar si puede levantarse de la mesa.
      MPI_Ssend( &valor, 1, MPI_INT, id_camarero, etiq_levantarse, MPI_COMM_WORLD);
      
      // 6
      
      cout << "Filosofo " << id << " comienza a pensar" << endl;
      sleep_for( milliseconds( aleatorio<10,100>() ) );
   }
}
// ---------------------------------------------------------------------

void funcion_tenedores( int id )
{
  int valor, id_filosofo ;  // valor recibido, identificador del filósofo
  MPI_Status estado ;       // metadatos de las dos recepciones

  while ( true )
  {
    // ...... recibir petición de cualquier filósofo (completar)
    MPI_Recv( &valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_fi_coge, MPI_COMM_WORLD, &estado );
    
    // ...... guardar en 'id_filosofo' el id. del emisor (completar)
    id_filosofo = estado.MPI_SOURCE;
    cout <<"Ten. " <<id <<" ha sido cogido por filo. " <<id_filosofo <<endl;
    
    // ...... recibir liberación de filósofo 'id_filosofo' (completar)
    MPI_Recv( &valor, 1, MPI_INT, id_filosofo, etiq_fi_suelta, MPI_COMM_WORLD, &estado);
    cout <<"Ten. "<< id<< " ha sido liberado por filo. " <<id_filosofo <<endl ;
  }
}
// ---------------------------------------------------------------------

void funcion_camarero()
{   
    int etiq_puede = 999;   // etiqueta de lo que puede hacer el filosofo
    int s = 0,  // numero de filosofos sentados.
        valor,  // valor recibido
        id_filo;//id del filosofo que llama al camarero
    MPI_Status estado ;       // metadatos de las dos recepciones

  while ( true )
  {
      if(s == num_filosofos-1)   // si s == 4, sólo puede levantarse
          etiq_puede = etiq_levantarse;
      else if (s == 0)                  // si s == 0, solo puede sentarse
          etiq_puede = etiq_sentarse;
      else                              // si no, puede las dos
          etiq_puede = MPI_ANY_TAG;
      
    // ...... recibir petición de cualquier filósofo
    MPI_Recv( &valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_puede, MPI_COMM_WORLD, &estado );
    
    id_filo = estado.MPI_SOURCE;
    
    if(estado.MPI_TAG == etiq_sentarse){
        s++;
        cout <<"Filósofo " <<id_filo << " se ha sentado."<<endl;
    } else if (estado.MPI_TAG == etiq_levantarse){
        s--;
        cout <<"Filósofo " <<id_filo << " se ha levantado."<<endl;
    }
  }
}
// ---------------------------------------------------------------------ç

int main( int argc, char** argv )
{
   int id_propio, num_procesos_actual ;

   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &id_propio );
   MPI_Comm_size( MPI_COMM_WORLD, &num_procesos_actual );


   if ( num_procesos == num_procesos_actual )
   {
      // ejecutar la función correspondiente a 'id_propio'
       if( id_propio == 10)                    // si es 10   
           funcion_camarero();                 // es el camarero
       else if ( id_propio % 2 == 0 )          // si es par
           funcion_filosofos( id_propio );     //   es un filósofo
       else                                    // si es impar
           funcion_tenedores( id_propio );     //   es un tenedor
   }
   else
   {
      if ( id_propio == 0 ) // solo el primero escribe error, indep. del rol
      { cout << "el número de procesos esperados es:    " << num_procesos << endl
             << "el número de procesos en ejecución es: " << num_procesos_actual << endl
             << "(programa abortado)" << endl ;
      }
   }

   MPI_Finalize( );
   return 0;
}

// ---------------------------------------------------------------------
