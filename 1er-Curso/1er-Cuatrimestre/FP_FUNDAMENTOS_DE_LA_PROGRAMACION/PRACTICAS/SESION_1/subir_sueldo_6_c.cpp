////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 22/09/2022
////////////////////////////////////////////////////////////////////////////

/*
	Programa en el que nos muestro un salario final después de haber
	introducido el salario base e haberlo incrementado un 2%.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	double salario_base;	//Declarar las variables
	
	cout << " Introduzca el salario_base:  ";
	cin >> salario_base;
	
	salario_base = 1.02*salario_base;
	
	cout << "\nEl salario final es: " << salario_base;
	
}
