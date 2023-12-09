/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 11/11/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	40. [Muy divisible] El programa imprimirá por pantalla aquellos números en 
	el rango [min, max] que tienen k o más divisores (es decir, los números muy 
	divisibles dado el valor de k)	
	
	SI ME FIJO, SIEMPRE SE CUMPLE QUE EL ÚLTIMO DIVISOR DE UN NÚMERO ES MENOR
	O IGUAL QUE LA MITAD DE ESE NÚMERO.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 40. MUY DIVISIBLE \n\n";
	
	// Declarar las variables.
	
	int min = 0,
		max = 0,
		k = 0,
		num_divis = 0;	// numeros de divisores
	
	// Entrada de datos.
	
	cout << "  Introduce el mínimo -> ";
	cin >> min;
	
	do{
		cout << "  Introduce el máximo -> ";
		cin >> max;
	}while (max < min);
	
	do{
		cout << "  Introduce un número entero 'k'"
			 << " (que determinará el número de divisores). -> ";
		cin >> k;
	}while (k < 1);

	
	// Cómputos.
		
	cout << "\n Los números que están en el rango" 
		 << " [" << min << " , " << max << "]"
		 << " y tienen " << k << " o más divisores (son muy divisibles) "
		 << "son: \n" << endl; 
	                               

			// Busqueda de números muy divisibles en [min,max]
	for (int n = min; n <= max; n++){
		num_divis = 0;
			//Busco los divisores de n.
        for (int i = 2; i <= n/2; i++){   		// i = 2 --> Divisor
        	if(n%i==0){ 						// ultimo divisor = n/2
				num_divis++;
        	}
    	}
    	if(num_divis >= k){
        	cout << "\t" << n << endl;
    	}
	}


	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}

