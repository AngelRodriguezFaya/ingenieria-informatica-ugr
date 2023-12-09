/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 08/11/2022
////////////////////////////////////////////////////////////////////////////

/*
	30. [Aproximación de p por Gregory-Leibniz] 
	b) Calculo (-1)^i con un bucle.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 30. APROXIMACIÓN DE PI POR GREGORY-LEIBNIZ. "
		 << " APARTADO b) \n";
	cout << endl;	
	
	// Declarar las variables.
	
	const double TOPE_MAX = 100000; /*Lo he pusto ya que así es mas visual a la
									  hora de corregir errores en el código, 
								      porque me puedo equivocar y poner o 
									  quitar algún cero.
									*/
	double tope = 0,
		   suma = 0,
		   pi_aprox = 0,
		   potencia = -1.0,
		   base = -1.0;
	
	// Entrada de datos.
		
	do{
		cout << "  Introduzca el índice de la última interacción"
			 << "(debe estar entre 1 y 100 mil) -> ";
		cin >> tope;
	}while ((tope < 1) || (tope > TOPE_MAX));
	
	
	/* La aproximación de pi por Gregrory-Leibniz es: 
	
		Pi				(-1)^i
	----------  = 	-------------------
		4				2 * i + 1 
	
	*/
	
	// Cómputos.
	
	for (int i = 0; i <= tope; i++){
		potencia = potencia * base;
		suma = suma + (potencia/(2 * i + 1));
	}
	
	pi_aprox = 4 * suma;
	
	// Salida de datos.
	
	cout.precision(15);		// Nos muestra sólo 15 decimales.
	
	cout << "\n\t El valor aproximado de PI por Gregory-Leibniz es: "
		 << pi_aprox << endl;
		 
		
	cout << "\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";		
}
