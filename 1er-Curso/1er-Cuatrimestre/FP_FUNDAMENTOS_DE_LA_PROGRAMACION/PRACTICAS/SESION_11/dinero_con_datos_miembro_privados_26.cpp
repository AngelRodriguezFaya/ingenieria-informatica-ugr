/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación 
// Ingeniería Informática 1º D2
// ETSIIT (Universidad de Granada)
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 25/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 26. Es lo mismo que el programa 23.[Dinero con datos miembro 
	públicos] pero esta vez con datos de miembro privado.
	
	En este programa, se tienen que crear dos funciones dentro de la clase que 
	me muestren los valores que tienen guardados los atributos privados de la 
	clase, por lo que ahora tengo que crear las variables dentro del main, y
	se las paso como parámetros a la función de convertir los céntimos en euros,
	y esa función además de convertir los valores, me va actualizando mis 
	atributos de la parte privada.
	
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

class Dinero{
	
	//Atributos.
	private:
		int euros, centimos;
	
	//Métodos.
	public:
		int Euros (){
			return euros;
		}
		int Centimos(){
			return centimos;
		}
		void SetEurCent(int euros_intr, int centimos_intr);
};

void Dinero::SetEurCent(int euros_intr, int centimos_intr){
	centimos = centimos_intr;
	while (centimos >= 100){
		euros = euros_intr + 1;
		centimos = centimos_intr - 100;
	}
}


int main(){
	
	cout << "\n\tPROGRAMA: 26. DINERO CON DATOS MIEMBRO PRIVADOS. \n\n";

	// Declarar las variables.
	
	int euros1 = 0,
		euros2 = 0,
		centimos1 = 0,
		centimos2 = 0; 
	int suma_euros = 0, 
		suma_centimos = 0;
	
	Dinero dinero1, dinero2, dinero_suma;
	
	// Entrada de datos.
	
	cout << "   Introduzca el precio del primer producto en euros y céntimos ->"
		 << "\n   ";
	cin >> euros1 >> centimos1;
	dinero1.SetEurCent(euros1, centimos1);
	
	cout << "   Introduzca el precio del segundo producto en euros y céntimos ->"
		 << "\n   ";
	cin >> euros2 >> centimos2;
	dinero2.SetEurCent(euros2, centimos2);

	// Cómputos.
	
	suma_euros = dinero1.Euros() + dinero2.Euros();
	suma_centimos = dinero1.Centimos() + dinero2.Centimos();
	
	dinero_suma.SetEurCent(suma_euros, suma_centimos);
	
	// Salida de datos.
	
	cout << "\n   Total: ";
	cout << "\n\t Euros: " << dinero_suma.Euros();
	cout << " \n\t Céntimos: " << dinero_suma.Centimos();


	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}

