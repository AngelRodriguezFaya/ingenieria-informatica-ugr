/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 16/11/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 5. Dado un vector de enteros v y dado un número T, se quiere ver 
	si hay una serie consecutiva de elementos del vector que sume T. 
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA 9: SUMATORIA  \n" << endl;
	
	// Declarar las variables, vectores y constantes.
	
	const int LONGITUD_MIN = 0;
	const int LONGITUD_MAX = 100;	
	
	int	alturas[LONGITUD_MAX];
	
	int longitud_v = 0,
		alt_rest = 0,			// alturas restantes (para la entrada de datos)
		diferen = 0,
		diferen_ante = 0,
		max_desni = 0,
		desni_acum_positi = 0;
	
	bool suficientes_datos = false;
			
	// Entrada de datos.
		
	do{
		cout << "  ¿Cuántas alturas va a introducir? -> ";
		cin >> longitud_v;
	}while (longitud_v < LONGITUD_MIN || longitud_v > LONGITUD_MAX );
	
	cout << "\n";
	alt_rest = longitud_v;
	for (int i = 0; i < longitud_v; i++){
		cout << "  Ahora introdúcelas una a una. Quedan: "
		 	 << alt_rest << " -> ";            
		alt_rest--;
		cin >> alturas[i];
	}	
		
	// Cómputos.
		
	if (longitud_v > 1){        // Si > 1 continua. Si < 1,va al final y termina
	suficientes_datos = true;
		// Máximo desnivel.
		for (int i = 0; i < longitud_v; i++){
			diferen = 0;
			for (int j = i + 1; j < longitud_v; j++){
				diferen = alturas[j] - alturas[i];
				diferen = abs(diferen);
				if (diferen > diferen_ante){
					max_desni = diferen;
				}
				diferen_ante = diferen;
				break;
			}	
		}
			// Desnivel acumulado positivo.	
		for (int i = 0; i < longitud_v; i++){
			diferen = 0;
			for (int j = i + 1; j < longitud_v; j++){
				diferen = alturas[j] - alturas[i];
				if (diferen > 0){
					desni_acum_positi = desni_acum_positi + diferen;
				}
				break;
			}	
		}
	}
	
	// Salida de datos.
	
	switch (suficientes_datos){
		case false:
			cout << "\n\t error: no hay suficientes datos.";
		break;
		case true:
			cout << "\n\t El mayor desnivel es " << max_desni  
				 << " y el desnivel acumulado positivo es " 
				 << desni_acum_positi;
		break;
	}
	
	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}

