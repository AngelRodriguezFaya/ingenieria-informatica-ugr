/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 09/11/2022
////////////////////////////////////////////////////////////////////////////

/*
	32. [Aproximación de p por Madhava sin usar pow]
	Importante: En la implementación de esta solución NO puede usar la función 
	pow ni ningún condicional if. Se le pide expresamente que para el cómputo
	de cada término, intente aprovechar los cómputos realizados en la iteración 
	anterior.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	/* 
	                                            signo
	                                              |
	                                            ------
	 pi                                         (-1)^i	*	a^(2i+1)
	--- (APRÓX)= sumatoria de tope en i=0  *  ----------------------
	 6										         2*i + 1
	
	
	En la siguiente línea, sustituyo en el i del exponente, i+1:
	
	num = a^2*(i+1)+1 = a^(2i+1+2) = a^(2i+1) * a^2    --> num * a^2
			------					    ----
			   ^		                 ^	
			   |					     |
			Iteración i+1			Iteración i
	
	dem = (2*i+1)+1	 =  2i+1+2    --> dem + 2
						----
	                      ^
	                      |
	                Iteración i
	
	*/
	
	cout << "\n\tPROGRAMA: 32. APROXIMACIÓN DE PI POR MADHAVA. \n";
	cout << endl;	
	
	// Declarar las variables.
	
	const double TOPE_MAX = 100000; /*Lo he pusto ya que así es mas visual a la
									  hora de corregir errores en el código, 
								      porque me puedo equivocar y poner o 
									  quitar algún cero.
									*/
	int tope = 0,
		signo = 1;		// Inicializo a 1 porque i=0, entonces (-1)^i => 1
	double a = 0.0,
		   num = 0.0,
		   dem = 1.0,
		   suma = 0.0,
		   pi_aprox = 0.0;
	
	// Entrada de datos.
	
	a = 1/sqrt(3);
	num = a;
	
	do{
		cout << "  Introduzca el índice de la última interacción"
			 << "(debe estar entre 1 y 100 mil) -> ";
		cin >> tope;
	}while ((tope < 1) || (tope > TOPE_MAX));
	
	// Cómputos.
	
	for (int i=0; i<= tope; i++){
		suma = suma + signo * (num/dem);
		num = num * a * a;
		dem = dem + 2;
		signo = -signo;		
	} 
	
	pi_aprox = suma * 6;
	
	// Salida de datos.
	
	cout.precision(15);		// Nos muestra sólo 15 decimales.
	
	cout << "\n\t El valor aproximado de PI por Madhava es: "
		 << pi_aprox << endl;
		 
	cout << "\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";		
}




