/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que calcula el interés bancario a traves de una fórmula (distinta 
	a la de a) dándole los valores del capital y el interés.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double capi;
	double inter;
	
	cout << "Introduzca su capital: ";
	cin >> capi;
	cout << "Introduzca el interes (en % y sin el signo): ";
	cin >> inter;
	
	capi = capi+capi*(inter/100);
	
	cout << "\n\tEl total es: " << capi;
	
	/* Ventaja de utilizar capital en vez de total:
		- Guardamos el valor en una variable que ya habiamos creado 
		  anteriormente y ya habiamos utilizado, por lo que no tendremos
		  que crear una nueva variable para almacenar el valor total, y 
		  ahorraríamos mucho código.
		  
	   Inconveniente de utilizar capital en vez de total:
	   	- Al guardar el valor total en la variable capital, perderemos su 
		  valor inicial ya que se sobreescribirá, y no podremos utilizar 
		  de ese valor más adelante en el programa.
	*/
	
}
