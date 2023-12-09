/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 22/09/2022
////////////////////////////////////////////////////////////////////////////

/*
	Programa que transforma una cantidad de grados en radianes.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	double grado_1;	//Declarar las variables
	double grado_2;
	double radianes_1;
	double radianes_2;
	
	const double PI = 6 * asin(0.5);
	
	cout << " Introduzca los primeros grados:  ";
	cin >> grado_1;
	cout << " Introduzca los segundos grados ";
	cin >> grado_2;
	
	radianes_1 = grado_1*(PI/180);
	radianes_2 = grado_2*(PI/180);

	cout << "\n Los primeros grados en radianes son: " << radianes_1;
	cout << "\n Los segundos grados en radianes son: " << radianes_2;
	
}
