/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 05/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa en el que tenemos que resolver mini-problemas utilizando
	expresiones lógicas.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 27.EXPRESIONES LÓGICAS. \n\n";

	/*
		Escriba una expresión lógica que sea verdadera si una variable 
		de tipo entero llamada edad es menor de 18 o mayor de 65 
		y falso en otro caso.
	*/
	
	int edad = 0;
	bool comprobar;
	
	cout << " Introduce tu edad: ";
	cin >> edad;
	
	comprobar = edad < 18 || edad > 65;
	
	if (comprobar){
		cout << "\n\t VERDADERO";
	}
	else{
		cout << "\n\t FALSO";
	}

}
