/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 29/11/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 12: Se quiere construir un programa que lea el número total de 
	escaños a distribuir, el número de partidos que han participado en las 
	elecciones y los votos obtenidos por cada uno de ellos. El programa 
	mostrará cuántos escaños obtuvo cada partido.
		
	La asignación de los escaños se hace a través de un proceso iterativo 
	en el que en cada iteración se asigna un escaño a un partido y así 
	hasta llegar al número total deescaños a repartir. En una determinada 
	iteración, un partido se llevará un escaño si tiene el mayor cociente de 
	D’Hondt, definido éste como sigue:

				Cociente de D’Hondt = Vi/(Si + 1)

	Dónde:
	- Vi es el número total de votos obtenidos en las elecciones por el 
	  partido i. 
	- Si es el número de escaños asignados hasta esa iteración al partido i.

*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA 12: SISTEMA DE D'HONDT. " << endl;
	
	// Declarar las variables, constantes y vectores.
	
	const int MAX_NUM_PARTIDOS = 100; 
	double escanios_asignados[MAX_NUM_PARTIDOS];
	double votos[MAX_NUM_PARTIDOS];
	double hondts[MAX_NUM_PARTIDOS];
	
	int num_partidos = 0,
		num_votos = 0,
		num_escanios = 0,
		max = 0,
		pos_max = 0;

	// Entrada de datos
	
	cout << "\n  Introduce el número total de escaños a distribuir -> \n  ";
	cin >> num_escanios;
	
	do{
		cout << "  Introduce el número de partidos que han participado -> \n  ";
		cin >> num_partidos;
	}while (num_partidos < 1 || num_partidos > MAX_NUM_PARTIDOS);
	
	cout << "  Introduce el número de votos obtenido por cada partido -> \n";
	for (int v = 0; v < num_partidos; v++){
	    cout << "  Partido Nº" << v+1 << ": ";
		cin >> num_votos;
		votos[v] = num_votos;
		hondts[v] = num_votos;
	}
	
	cout << "\n ¡Datos guardados correctamente! \n" << endl;
	
	// Cómputos.
		
		// Primero inicializo a 0 el vector escanios para que no haya problemas.
		
	for (int i = 0; i < num_escanios; i++)
		escanios_asignados[i] = 0;
	 	
	for (int i = 0; i < num_escanios; i++){
		max = 0;
		pos_max = 0;
		for (int j = 0; j < num_partidos; j++){
			if (hondts[j] > max){
				pos_max = j;
				max = hondts[j];
			}
		}
		escanios_asignados[pos_max]++;
		hondts[pos_max] = votos[pos_max] / (escanios_asignados[pos_max] + 1.0);
	}
	
	// Salida de datos.
	
	for (int i = 0; i < num_partidos; i++){
		cout << "  El partido Nª" << i+1 << " con " << votos[i] 
			 << " votos, ha obtenido " << escanios_asignados [i]
			 << " escaños. " << endl;
	}
	
	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. \n";	
}

