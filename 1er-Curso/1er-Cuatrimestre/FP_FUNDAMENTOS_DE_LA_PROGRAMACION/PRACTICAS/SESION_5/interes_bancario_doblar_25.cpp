/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 29/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	[7 INTERÉS BANCARIO] Programa que calcula el interés bancario a traves 
	de una fórmula dándole los valores del capital y el interés. En este nuevo
	programa (el 25) se trata de rescatar el programa 7, pero esta vez tendre-
	mos que calcular el número de años que han de pasar para doblar el capital
	inicial y el dinero total que se obtendría al final. 
	
	Para ello utilizo un bucle de tipo while en el que se sigue ejcutando cada
	vez que el valor total que vamos calculando sea menor que el doble del 
	capital inicial.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.							
using namespace std;																	
																							
int main(){																				
		
	cout << "\n\t\tPROGRAMA: 25.INTERÉS BANCARIO (DOBLAR)";
	cout << endl;	
																		
	// Declarar las variables.
	
	double capi = 0.0,	
	       inter = 0.0,
		   total = 0.0;
	int exponente = 1,
	    num_anios = 0;
	
	// Entrada de datos.
	
	cout << "\n  Introduzca su capital:  ";
	cin >> capi;
	cout << "  Introduzca el interés(sin el signo de %): ";
	cin >> inter;
		
	// Cómputos.
	
	while (total < (2 * capi)){
		total = capi * pow((1 + inter/100), exponente);
		exponente++;
		num_anios++;
	}
	
	// Salida de datos.
	
	cout << "\n\tPara doblar la cantidad inicial han de pasar "
	     << num_anios << " años." << endl 
	     << "\tAl finalizar, se obtendrá un total de "
	     << total << " euros." << endl;	
	     
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}
