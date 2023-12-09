/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
////////////////////////////////////////////////////////////////////////////

/*
	Programa simple para el cálculo del voltaje cprrespondiente mediante
	la Ley de Ohm
*/

#include <iostream>   
#include <cmath>      
using namespace std;

int main(){
	double intensidad;
	double resistencia;
	double voltaje;
	
	cout << "Introduzca el valor de la intensidad: ";
	cin >> intensidad;
	cout << "Introduzca el valor de la resistencia: ";
	cin >> resistencia;
	
	voltaje = intensidad*resistencia;

	cout << "\nEl voltaje es: " <<voltaje;

}
