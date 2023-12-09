/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 27/11/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 25: Se pide que, después de leer los datos de las distancias de
	las ciudades, el programa lea los índices i y j de dos ciudades. En el caso 
	de que no exista un camino directo entre ellas (la distancia entre ellas 
	sea cero), el programa debe obtener aquella ciudad intermedia o escala z 
	que permita hacer el trayecto entre i y j de la forma más económica posible.
	
						DESTINO
					j ---------------->	
					C0  C1  C2  C3  C4
				i C0 0   50  100 0  150
                | C1 50  0   70  0   0
		 ORIGEN	| C2 100 70   0  60  80
				| C3 0   0   60  0   90
                | C4 150 0   80  90  0

*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA 25: DISTANCIA ENTRE CIUDADES (MEJOR ESCALA)" << endl;
	
	// Declarar las variables
	
	const int MAX_NUM_CIUDADES = 50; 
	double mapa[MAX_NUM_CIUDADES][MAX_NUM_CIUDADES];
	int num_ciudades = 0,
		origen = 0,
		destino = 0,
		mejor_ciudad_depaso = -1;
	double dist = 0,
		   dist_con_escala = 0,
		   min_dist = 1000*1000; // Lo inicializo así para que no de problemas.
	
	// Entrada de datos
	
	cout << "\n  Introduce el número de ciudades -> ";
	cin >> num_ciudades;
	
	for (int i = 0; i < num_ciudades; i++)	// Relleno la matriz con 0.
		for (int j = 0; j < num_ciudades; j++)
			mapa[i][j] = 0;
	
	cout << "\n  Introduzca la distancia entre ellas en forma de matriz "
		 << "diagonal superior -> \n";
	for (int i = 0; i < num_ciudades -1; i++){
		cout << "\t";
		for (int j = i + 1; j < num_ciudades; j++){
			cin >> dist;
			mapa[i][j] = mapa[j][i] = dist;	
			/* De esta forma, se guaradaria una matriz simétrica, ya que hemos 
			introducido una matriz diagonal superior y el programa también
			rellena la parte inferior. Como al principio se rellenó la matriz 
			con 0, los elementos de su diagonal principal son 0. */
		}
	}
	
	cout << "  Número de ciudad de origen -> ";
	cin >> origen;
	
	cout << "  Número de ciudad de destino -> ";
	cin >> destino;
	
	// Cómputos. 	MEJOR ESCALA ENTRE ORIGEN Y DESTINO
	
	for (int z = 0; z < num_ciudades; z++){
		dist_con_escala = 0;
		if ((mapa[origen][z] != 0) && (mapa[z][destino] != 0)){ 
			dist_con_escala = mapa[origen][z] + mapa[z][destino];
			if (dist_con_escala < min_dist && dist_con_escala != 0){
				mejor_ciudad_depaso = z;
				min_dist = dist_con_escala;
			}
		}
	}

	// Salida de datos.
	
	cout << "\n\t La mejor escala entre las ciudades " << origen  
		 << " y " << destino << " es la siguiente: " << endl		  
		 << "\n\t  Ciudad: " << mejor_ciudad_depaso << endl
		 << "\n\t  Distancia a recorrer: " << min_dist
		 << " kilómetros." << endl;
		 
	
	cout << "\n\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. \n";	
}

