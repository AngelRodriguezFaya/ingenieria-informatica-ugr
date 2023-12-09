/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 22/09/2022
////////////////////////////////////////////////////////////////////////////

/*
	Programa que calcula la variación porcentual de un producto introduciendóle
	el valor inicial y el valor final del producto.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	double valor_ini;	//Declarar las variables
	double valor_fi;
	double vari_porcen;
	
	cout << " Introduzca el valor inicial del producto:  ";
	cin >> valor_ini;
	cout << " Introduzca el valor final del producto: ";
	cin >> valor_fi;
	
	vari_porcen = abs(100*((valor_fi - valor_ini)/valor_ini));
	
	cout << "\nLa variación porcentual es: " << vari_porcen << "%";
	
}
