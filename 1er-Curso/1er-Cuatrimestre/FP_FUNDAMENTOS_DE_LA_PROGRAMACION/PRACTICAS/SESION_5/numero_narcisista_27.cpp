/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 30/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	27. [Número Narcisista] Un número entero de n dígitos se dice que es 
	narcisista si se puede obtener como la suma de las potencias n-ésimas 
	de cada uno de sus dígitos.
	
	Para realizarlo creo las siguientes estructuras:
	
		- un bucle while -> para averiguar el número de digitos.
		- un bucle for -> donde saco la última cifra, realizo la suma de cada
			cifra elevada al número de dígitos, y por último quita la última 
			cifra para cuando se vuelva a realizar el bucle siga con la 
			siguiente cifra.
		- un condicional if -> para mostar si es o no narcisista.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.							
using namespace std;	

int main(){
	
	cout << "\n\t\tPROGRAMA: 27. NÚMERO NARCISISTA." << endl;
	
	// Declarar las variables.
	
	int num = 0,
		num_digitos = 1,
		cifra_ult = 0,			// Última cifra
		total = 0,
		aux = 0;				// Variable auxiliar
		
	bool num_narcisista;
		
	
	// Entrada de datos.
	
	cout << "\n Introduce el número que desea comprobar -> ";
	cin >> num;
	
	aux = abs(num);		/* La variable aux es una copia de num para no 
							 	perder su valor original. */

	// Cómputos.
	
	while (aux > 9){		// Sirve para averiguar el numero de dígitos.
		aux = aux/10;
		num_digitos++;
	}

	aux = abs(num);
	
	for (int i=0; i < num_digitos; i++){
		cifra_ult = aux % 10;						// Sacar la última cifra.
		total += pow(cifra_ult, num_digitos);   // -> total = total + pow(...)
		aux /= 10;		// -> aux = aux/10  	    // Quitar la última cifra.
	}

	num_narcisista = (total == num);
	

	// Salida de datos.
	
	if (num_narcisista){
		cout << "\n\t El número " << num << " es narcisista";
	}
	else{
		cout << "\n\t El número " << num << " no es narcisista";
	}	


	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";		
}
