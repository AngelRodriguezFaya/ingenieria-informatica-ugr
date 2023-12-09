/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación 
// Ingeniería Informática 1º D2
// ETSIIT (Universidad de Granada)
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 11/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 26  
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA 26. \n\n";
	
	// Declarar las variables, constantes y vectores.
	
	const int MAX_ASIGNAC = 20;
	const int MAX_COSTE = 1000;
	int num_asignac = 0;
	
	int tarifas[MAX_ASIGNAC][MAX_ASIGNAC];
	bool asignac[MAX_ASIGNAC][MAX_ASIGNAC];
	bool pedido_ya_asignado[MAX_ASIGNAC];
	
	int pos_min = 0,
		min = 0,
		costo = 0,
		pos_asigna = 0;
	
	// Entrada de datos.
	
	cout << "   Introduce el número de técnicos. Debe ser igal al número de "
		 << "pedidos y menor o igual que: " << MAX_ASIGNAC << " -> \n   ";
	cin >> num_asignac;
	
	cout << "   Ahora introduce la matriz de Tarifas (" << num_asignac << " x "
		 << num_asignac << ") elementos. -> \n   ";
	
	for (int i = 0; i < num_asignac; i++)	// Guardar los precios en la matriz.
		for (int j = 0; j < num_asignac; j++)
			cin >> tarifas[i][j];
	
	for (int i = 0; i < num_asignac; i++) // RElleno la matriz con false.
		for (int j = 0; j < num_asignac; j++)
			asignac[i][j] = false;
	
	for (int i = 0; i < num_asignac; i++) // Rellenar la matriz con false.
		pedido_ya_asignado[i] = false;
	
	// Cómputos.
	
	// t -> técnicos. Representan las filas de la matriz.
	// p -> precios o productos. Representan las columnas de la matriz.
	
	for (int t = 0; t < num_asignac; t++){
		min = MAX_COSTE + 1;
		for (int p = 0; p < num_asignac; p++){		
			if (tarifas[t][p] <= min && pedido_ya_asignado[p] == false){
				min = tarifas[t][p];
				pos_min = p;
			}
		}
		asignac[t][pos_min] = true;
		pedido_ya_asignado[pos_min] = true;
		costo += tarifas[t][pos_min];
	}

	// Salida de datos.

	cout << "\n\nMatriz de asignac:\n";
   
	for(int i = 0; i < num_asignac; i++){   	
		for(int j = 0; j < num_asignac; j++)
			cout << asignac[i][j] << "\t";
	cout << "\n";
	}

   cout << "\n\tCoste total: " << costo;



	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}

