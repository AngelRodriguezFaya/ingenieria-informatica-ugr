/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 05/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que lee dos valores enteros desde el teclado y nod dice si 
	cualquiera de ellos divide o no (de forma entera) al otro.
	
	% -> Módulo (resto de la división) 
	Para saber si un número divide al otro, el resto de la división entre ambos
	debe de ser 0, si es distinto, no se dividen.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: SE DIVIDEN. \n\n";

	int num1, num2;
	 
	cout << " Introduzca el valor de los dos números: ";
	cin >> num1 
		>> num2;
	

	if (((num1 % num2) == 0) || ((num2 % num1) == 0)){
		cout << "\n\t Un número divide al otro.";
	} else{
		cout << "\n\t Ninguno divide al otro.";
	}
}

