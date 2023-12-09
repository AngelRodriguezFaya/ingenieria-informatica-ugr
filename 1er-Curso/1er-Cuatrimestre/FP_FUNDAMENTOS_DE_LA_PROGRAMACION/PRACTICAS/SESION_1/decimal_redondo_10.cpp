/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 23/09/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que redondea un número real a cualquier cifra decimal.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.							
using namespace std;																	
																							
int main(){																				
																				
	double num_real;	//Declarar las variables
	double n;
	double redon_real;
	
	cout << " Introduzca el número real que desee redondear:  ";
	cin >> num_real;
	cout << " Introduzca el número de cifra decimal a la que desea redondear: ";
	cin >> n;
	
	redon_real = (round(num_real*pow(10, n))/ pow(10, n));

	cout << "\n\tEl resultado de redondear " << num_real << " a la " << n;
	cout << "º cifra decimal es: " << redon_real;
	
}
