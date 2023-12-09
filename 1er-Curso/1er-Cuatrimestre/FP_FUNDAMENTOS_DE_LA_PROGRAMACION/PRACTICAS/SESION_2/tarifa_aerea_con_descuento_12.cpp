/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que nos calcula el precio de un billete de avión, que dependiendo
	de unos requisitos, se le aplica un descuento u otro.
*/

#include <iostream>
using namespace std;

int main(){
	cout << "\n\tPROGRAMA: BILLETE CON DESCUENTO. \n\n";
	
	double dto_puntos = 0.04;
	double dto_trayecto = 0.02;
	double precio_bill;
	
	cout << "  Introduzca el precio del billete: ";
	cin >> precio_bill;
	
	cout << "\n\tSi tiene un número alto de puntos, el precio del billete es: ";
	cout << precio_bill - (precio_bill * dto_puntos);
	cout << "\n\tSi el trayecto es largo, el precio del billete: ";
	cout << precio_bill - (precio_bill * dto_trayecto);
	
}
