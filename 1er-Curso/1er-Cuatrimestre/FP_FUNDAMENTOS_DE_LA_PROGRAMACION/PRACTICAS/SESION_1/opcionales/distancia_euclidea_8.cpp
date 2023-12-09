/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que calcula la distancia entre dos puntos.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){

	double x1;
	double x2;
	double y1;
	double y2;
	double dist;
	
	cout << "Introduzca el valor de la primera coordenada del 1er punto: ";
	cin >> x1;
	cout << "Introduzca el valor de la segunda coordenada del 1er punto: ";
	cin >> x2;
	cout << "Introduzca el valor de la primera coordenada del 2º punto: ";
	cin >> y1;
	cout << "Introduzca el valor de la segunda coordenada del 2º punto: ";
	cin >> y2;
	
	dist = sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
	
	cout << "\n\tLa distancia entre los puntos es: " << dist;
	
}
