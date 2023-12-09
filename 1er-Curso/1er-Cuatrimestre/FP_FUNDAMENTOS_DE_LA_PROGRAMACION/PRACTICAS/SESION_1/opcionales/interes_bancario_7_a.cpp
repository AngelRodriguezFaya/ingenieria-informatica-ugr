/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que calcula el interés bancario a traves de una fórmula dándole
	los valores del capital y el interés.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.							
using namespace std;																	
																							
int main(){																				
																				
	double capi;	//Declarar las variables
	double inter;
	double total;
	
	cout << " Introduzca su capital:  ";
	cin >> capi;
	cout << " Introduzca el interés(sin el signo de %): ";
	cin >> inter;
	
	total = capi+capi*(inter/100);
	
	cout << "\n\tEl total es: " << total;
	
}
