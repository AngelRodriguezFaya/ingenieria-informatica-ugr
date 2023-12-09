/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022
////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022
////////////////////////////////////////////////////////////////////////////

//Programa para hacer conversiones de una distancia en metros a varias unidades.

/*
	1 pulgada = 25,4 milímetros
	1 pie = 30,48 centímetros
	1 yarda = 0,9144 metros
	1 milla = 1609,344 metros
	1 milla marina = 1852 metros

	1 pulgada = 25.4 mm 
	-> 1mm = 1 / 25.4 pulgadas
	-> 1m = 1000 / 25.4 pulgadas
*/

#include <iostream>
using namespace std;

int main(){
	cout << "\n\tPROGRAMA: SISTEMA MÉTRICO. \n\n";
	
	const double PULGADAS_POR_METRO		= 1000 / 25.4;
	const double PIES_POR_METRO			= 100 / 30.48;
	const double YARDAS_POR_METRO		= 1 / 0.9144;
	const double MILLAS_POR_METRO		= 1 / 1609.344;
	const double MILLAS_MARINAS_POR_METRO = 1 / 1852.0;
	double longtd, pulgad, pies, yardas, mill, mill_mar;
	
	cout << "  Introduce la longitud en metros: ";
	cin >> longtd;
	
	pulgad = PULGADAS_POR_METRO * longtd;
	pies = PIES_POR_METRO * longtd;
	yardas = YARDAS_POR_METRO * longtd;
	mill = MILLAS_POR_METRO * longtd;
	mill_mar = MILLAS_MARINAS_POR_METRO * longtd;
	
	cout << "\n\t" << longtd << " metros en pulgadas son " << pulgad;
	cout << "\n\t" << longtd << " metros en pies son " << pies;
	cout << "\n\t" << longtd << " metros en yardas son " << yardas;
	cout << "\n\t" << longtd << " metros en millas son " << mill;
	cout << "\n\t" << longtd << " metros en millas marinas son " << mill_mar;
	
}
