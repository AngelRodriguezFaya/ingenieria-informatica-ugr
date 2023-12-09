/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 03/10/2022
////////////////////////////////////////////////////////////////////////////

/*
	Programa que a través de la siguiente fórmula, imprime el valor de pi.
*/


#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	const double PI = 6 * asin(0.5);
	
	cout << "\nEl valor de pi es: " << PI;
	
}

