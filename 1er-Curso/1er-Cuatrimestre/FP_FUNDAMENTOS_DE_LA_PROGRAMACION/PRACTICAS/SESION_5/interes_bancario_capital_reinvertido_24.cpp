////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 26/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	[7 INTERÉS BANCARIO] Programa que calcula el interés bancario a traves 
	de una fórmula dándole los valores del capital y el interés. En este nuevo
	programa (el 24) se trata de rescatar el programa 7, pero esta vez el dinero
	será reinvertido en otro plazo fijo de un año, y así sucesivamente hasta
	los años que desee el cliente alargar esta opción. El programa irá 
	mostrando las cantidades de dinero conforme avancen los años.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.							
using namespace std;																	
																							
int main(){		

	cout << "\n\t\tPROGRAMA: 24.INTERÉS BANCARIO (CAPITAL REINVERTIDO)";
	cout << endl;																		
																				
	// Declarar las variables.
	
	double capi = 0.0,
		   inter = 0.0,
		   total = 0.0;
	int num_anios = 0,
		exponente = 1;
	
	// Entrada de datos.
	
	cout << "\n  Introduzca su capital ->  ";
	cin >> capi;
	cout << "  Introduzca el interés (entre 0 y 100 y sin el signo de %) -> ";
	cin >> inter;
	cout << "  Introduzca el número de años durante los que quiere "
	     << "seguir reivirtiendo -> ";
	cin >> num_anios;
	
	// Cómputos y Salida de datos.
	
	for (int i=0; i<num_anios; i++){
		total = capi * pow((1 + inter/100), exponente);
		exponente++;
		cout << "\n\t El capital obtenido transcurrido el año número " 
			 << i << " es de " << total;
	}
	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";		

}
