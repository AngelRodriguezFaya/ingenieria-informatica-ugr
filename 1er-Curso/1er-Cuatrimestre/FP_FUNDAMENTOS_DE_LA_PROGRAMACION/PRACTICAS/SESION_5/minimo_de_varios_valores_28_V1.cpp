////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 30/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	(V1)	28. [Mínimo de varios valores]. En este programa se pide que se 
	vayan leyendo varios números enteros desde el teclado y que finalice 
	cuando se introduzca 0. Al final muestra el número en total de números 
	introducidos y el mínimo de ellos.
	
	Para ello, he utilizado un bucle while que finalizará cuando introduz-
	camos 0 y un condicional if dentro por si el número que acabamos de 
	introducir es menor que el minimo que ya habíamos guardado antes, se 
	actualize y sea ese el nuevo mínimo.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.							
using namespace std;																	
																							
int main(){																				
		
	cout << "\n\t\tPROGRAMA: 28. MÍNIMO DE VARIOS VALORES. (V1)";
	cout << endl;	
																		
	// Declarar las variables.
	
	int num, 
		min, 
		cont = 0;

	// Entrada de datos.
	
	cout << "\n  Introduzca un número entero negativo. "
		 << "Para finalizar introduzca un número entero positivo -> ";
	cin >> num;
	
	min = num;
		
	// Cómputos.
	
	while (num < 0 ){
		cont++;
		if (num < min){
			min = num;
		}
		cout << "\n  Introduzca un número entero negativo. "
		 	 << "Para finalizar introduzca un número entero positivo -> ";
		cin >> num;
	}
	
	// Salida de datos.
	
	cout << "\n\t Ha introducido " << cont 
		 << " numeros en total y el menor ha sido " << min;
	
		     
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}
