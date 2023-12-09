/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que nos calcula el precio final de un billete de avión, habiéndo
	introducido una tarifa base e ir sumándole según la distancia al destino.
*/

#include <iostream>
using namespace std;

int main(){
	cout << "\n\tPROGRAMA: PRECIO DE UN BILLETE DE AVIÓN. \n\n";
	
	const double TARIFA_BASE = 150.0;
	double dist, tarifa_fin;
	
	cout << "  Introduce la distancia a su destino (en kilometros): ";
	cin >> dist;
	
	tarifa_fin = TARIFA_BASE + (dist * 0.1);

	cout << "\n\t El precio final del billete es: " << tarifa_fin;
	
}
