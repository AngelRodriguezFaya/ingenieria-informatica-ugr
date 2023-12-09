////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
////////////////////////////////////////////////////////////////////////////

/*
   Programa simple para el cálculo de la hipotenusa
   de un triángulo rectángulo, aplicando el teorema de Pitágoras
*/

#include <iostream>   // Inclusión de recursos de E/S
#include <cmath>      // Inclusión de recursos matemáticos
using namespace std;

int main(){               // Programa Principal
   double lado1;          // Declara variables para guardar
   double lado2;          // los dos lados y la hipotenusa
   double hipotenusa;
   
   cout << "Introduzca la longitud del primer cateto: ";
   cin >> lado1;
   cout << "Introduzca la longitud del segundo cateto: ";
   cin >> lado2;

   hipotenusa = sqrt(lado1*lado1 + lado2*lado2);
   
   cout << "\nLa hipotenusa vale " << hipotenusa;
}
