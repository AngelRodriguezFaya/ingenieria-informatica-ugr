// -----------------------------------------------------------------------------
// Plantilla modificada por ÁNGEL RODRÍGUEZ FAYA.
// Se completa el problema de los lectores-escritores con monitores.
// -----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "scd.h"

using namespace std ;
using namespace scd ;

const unsigned
            ne = 3,         // número de hebras escritoras.
            nl = 2;         // número de hebras lectoras.
int valor = 0;              // para ir mostrando en pantalla el valor

mutex mtx;                  // mutex para la escritura en pantalla.
//-------------------------------------------------------------------------
// clase para monitor, semántica SU, lectores_escritores.

class LecEsc : public HoareMonitor{
    
private:
    int n_lec;      // { número de lectores leyendo }  
    bool escrib;    // { true si hay algún escritor escribiendo }
    
    CondVar         //  colas condicion:
        lectura,    //  cola donde esperan los lectores cuando hay un escritor escribiendo.
        escritura;  //  cola donde esperan los escritores cuando otros están escribiendo ->
                    //  -> escrib == true o n_lec > 0 {no hay lec. ni esc. escritura posible}
public:
    LecEsc();
    // { invocados por lectores }
    void ini_lectura();
    void fin_lectura(); 
    
    //{ invocados por escritores }
    void ini_escritura();
    void fin_escritura(); 
};

//-------------------------------------------------------------------------
LecEsc::LecEsc(){
    n_lec = 0;
    escrib = false;
    lectura = newCondVar();
    escritura = newCondVar();
}

//-------------------------------------------------------------------------
void LecEsc::ini_lectura(){
    if(escrib)  // si hay escritor.
        lectura.wait();
    n_lec++;    // registrar un lector más.
    cout << "\n Lector comienza a leer, número de lectores: " << n_lec << endl;
    lectura.signal();   // desbloqueo en cadena los posibles lectores bloqueados.
}

//-------------------------------------------------------------------------
void LecEsc::fin_lectura(){
    n_lec--;    // registro un lector menos.
    if(n_lec == 0)          // si es el último lector.
        escritura.wait();   // desbloqueo un  escritor.
}

//-------------------------------------------------------------------------
void LecEsc::ini_escritura(){
    if(n_lec > 0 || escrib) // si hay otros, esperar.
        escritura.wait();
    escrib = true;          // registrar que hay un escritor.
}

//-------------------------------------------------------------------------
void LecEsc::fin_escritura(){
    escrib = false;     // registrar que ya no hay escritor
    if(!lectura.empty()) // si hay lectores, despertar uno
        lectura.signal();
    else                 // si no hay, despertar un escritor
        escritura.signal();
}

//-------------------------------------------------------------------------
//función que ejecutan las hebras escitoras
void funcion_hebra_escritora(MRef<LecEsc> monitor, int ih){
    while( true ){
        monitor->ini_escritura();   // se inicia la escritura.
        valor++;
        mtx.lock();
        cout << "\nHebra '" << ih << "' escribe '" << valor << "'." << endl;
        mtx.unlock();
        this_thread::sleep_for((chrono::milliseconds) aleatorio<100,250>() ); // retraso aleatorio simulando escritura
        monitor->fin_escritura();   // se finaliza la escritura
        this_thread::sleep_for((chrono::milliseconds) aleatorio<30,100>() ); // retraso aleatorio
   }
}

//-------------------------------------------------------------------------
//función que ejecutan las hebras lectoras
void funcion_hebra_lectora(MRef<LecEsc> monitor, int ih){
    while( true ){
        monitor->ini_lectura();   // se inicia la lectura.
        mtx.lock();
        cout << "\nHebra '" << ih << "' lee '" << valor << "'." << endl;
        mtx.unlock();
        this_thread::sleep_for((chrono::milliseconds) aleatorio<100,250>() );// retraso aleatorio simulando lectura
        monitor->fin_lectura();   // se finaliza la lectura
        this_thread::sleep_for((chrono::milliseconds) aleatorio<30,100>() ); // retraso aleatorio
   }
}

//-------------------------------------------------------------------------
int main(){
    cout << "--------------------------------------------------------------------" << endl
        << "        Problema del los lectores-escritores (Monitor SU).           " << endl
        << "---------------------------------------------------------------------" << endl
        << flush ;
    
    // creo el monitor
    MRef<LecEsc> monitor = Create<LecEsc>();
    
    // creo y lanzo las hebras.
    thread hebra_escritora[ne], hebra_lectora[nl];
    
    for(int i = 0; i < ne; i++)
        hebra_escritora[i] = thread(funcion_hebra_escritora, monitor, i);
            
    for(int i = 0; i < nl; i++)
        hebra_lectora[i] = thread(funcion_hebra_lectora, monitor, i);
    
    // espero a que terminen las hebras.
    for(int i = 0; i < ne; i++)
        hebra_escritora[i].join();
    
    for(int i = 0; i < nl; i++)
        hebra_lectora[i].join();
}