/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022
////////////////////////////////////////////////////////////////////////////

//Programa para ver el orden de una letra may�scula.

#include <iostream>
using namespace std;

int main(){
	cout << "\n\tPROGRAMA: ORDEN DE UNA MAY�SCULA. \n\n";

	char letra_mayus;
	int ord_letra;
	
	cout << "  Introduce la letra may�scula: ";
	cin >> letra_mayus;
	
	ord_letra = letra_mayus - 'A';
	
	cout << "\n\t La may�scula " << letra_mayus;
	cout << " est� en la posici�n: " << ord_letra;
	
}
