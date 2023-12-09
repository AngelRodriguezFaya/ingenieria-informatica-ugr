// Frecuencias

#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR = '@';
   const int NUM_CARACT_ASCII = 256;
   const int MAX_NUM_CARACT = 1e4;  // diez mil
   
   char a_buscar[NUM_CARACT_ASCII];
   int frecuencias[NUM_CARACT_ASCII];
   char texto[MAX_NUM_CARACT];

   char car;
   int longitud_a_buscar, longitud_texto;
   
   cout << "Frecuencias\n"
        << "Introduzca los caracteres del vector a buscar, con terminador "
        << TERMINADOR << "\n"
        << "A continuación introduzca  los caracteres del texto,"
        << " usando el mismo terminador.\n\n";

   // Lectura

   car = cin.get();
   longitud_a_buscar = 0;

   while (car != TERMINADOR && longitud_a_buscar < NUM_CARACT_ASCII){
      a_buscar[longitud_a_buscar] = car;
      car = cin.get();
      longitud_a_buscar++;
   }

   car = cin.get();
   longitud_texto = 0;

   while (car != TERMINADOR && longitud_texto < MAX_NUM_CARACT){
      texto[longitud_texto] = car;
      car = cin.get();
      longitud_texto++;
   }


   ///////////////////////////////////////////////////////////
   // Incluya aquí el código para realizar la búsqueda 
   ///////////////////////////////////////////////////////////
   
   for(int j=0; j<longitud_a_buscar; j++){
      frecuencias[j] = 0;
      for(int i=0; i<longitud_texto; i++){
        if(texto[i]==a_buscar[j])
            frecuencias[j]++;
      }
   }
   
   ///////////////////////////////////////////////////////////
   // Imprima en pantalla los valores del vector frecuencias
   ///////////////////////////////////////////////////////////

   for(int j=0; j<longitud_a_buscar; j++){
      cout << "Carácter " << a_buscar[j] << ": " 
           << frecuencias[j] << endl;
   }

    cout << "\n\n";

   /*
   axz@abcdaspfxxap@ 

   a: 3
   x: 2
   z: 0 
   */
}

