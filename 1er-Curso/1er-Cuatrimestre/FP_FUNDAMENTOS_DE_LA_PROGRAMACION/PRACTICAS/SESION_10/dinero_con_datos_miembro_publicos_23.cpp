/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación 
// Ingeniería Informática 1º D2
// ETSIIT (Universidad de Granada)
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 11/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 23: Construya un programa que lea el precio de dos productos 
	(euros y céntimos de un	producto y euros y céntimos del otro) y construya 
	dos objetos de la clase Dinero para almacenar el precio de cada producto.
	A continuación, el programa principal debe recuperar las cantidades de 
	ambos precios (accediendo a los datos miembros públicos de cada objeto), 
	sumarlas (la suma de las cantidades enteras la tiene que hacer en el
	propio main) y construir un tercer objeto con el resultado de la suma. 
	Finalmente, el programa debe imprimir en pantalla el número de euros y 
	céntimos del tercer objeto.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

class Dinero{
	
	//Atributos.
	public:
		int euros, centimos;
	
	//Métodos.
	public:
		void SetEurCent(int _euros, int _centimos);
};

void Dinero::SetEurCent(int _euros, int _centimos){
	centimos = _centimos;
	while (centimos >= 100){
		euros = _euros + 1;
		centimos = _centimos - 100;
	}
}


int main(){
	
	cout << "\n\tPROGRAMA: 23. DINERO CON DATOS MIEMBRO PÚBLICOS. \n\n";

	// Declarar las variables.
	
	int suma_euros = 0, 
		suma_centimos = 0;
	
	Dinero dinero1, dinero2, dinero_suma;
	
	// Entrada de datos.
	
	cout << "   Introduzca el precio del primer producto en euros y céntimos ->"
		 << "\n   ";
	cin >> dinero1.euros >> dinero1.centimos;
	dinero1.SetEurCent(dinero1.euros, dinero1.centimos);
	
	cout << "   Introduzca el precio del segundo producto en euros y céntimos ->"
		 << "\n   ";
	cin >> dinero2.euros >> dinero2.centimos;
	dinero2.SetEurCent(dinero2.euros, dinero2.centimos);

	// Cómputos.
	
	suma_euros = dinero1.euros + dinero2.euros;
	suma_centimos = dinero1.centimos + dinero2.centimos;
	
	dinero_suma.SetEurCent(suma_euros, suma_centimos);
	
	// Salida de datos.
	
	cout << "\n   Total: ";
	cout << "\n\t Euros: " << dinero_suma.euros;
	cout << " \n\t Céntimos: " << dinero_suma.centimos;


	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}

