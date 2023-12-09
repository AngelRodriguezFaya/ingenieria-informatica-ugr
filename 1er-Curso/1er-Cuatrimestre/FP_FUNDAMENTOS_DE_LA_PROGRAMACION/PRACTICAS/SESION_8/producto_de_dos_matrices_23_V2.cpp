/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 26/11/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 23(V2): Calcula el producto de dos matrices que se leen desde un 
	fichero llamado "ejer_23_III.txt" que se encuentra en el mismo directorio
	que este archivo(.cpp) y el archivo ejecutable (.exe).
	
	Esbozo:
	
	Matriz izquierda: A [i][k]
	Matriz derecha: B [k][j]
	Matriz producto: C [i][j]
					
			  i ---k--- j      i j	
	Ejemplo:  3x4     4x2      3x2
			   A   x   B   =   C
	i: 3
	j: 2
	k: 4	MUY IMPORTANTE ESTE VALOR

*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA 23: PRODUCTO DE DOS MATRICES.  \n" << endl;
	
	// Declarar las variables
	
	const int MAX_FIL_IZDA = 20, MAX_COL_IZDA = 20,
			  MAX_FIL_DCHA = MAX_COL_IZDA, MAX_COL_DCHA = 20;
	
	int util_fil_izda = 0, util_col_izda = 0,
		util_fil_dcha = 0, util_col_dcha = 0,
		util_fil_prod = 0, util_col_prod = 0;
	
	double matr_izda[MAX_FIL_IZDA][MAX_COL_IZDA],
		   matr_dcha[MAX_FIL_DCHA][MAX_COL_DCHA],
		   matr_prod[MAX_FIL_IZDA][MAX_COL_DCHA];
		   
	bool continuar;
		   
		   
	// Entrada de datos.
		
		
		// No etiqueto las entradas de datos porque las leo desde el fichero
		// ejer_23_III.txt que se encuentra en el mismo directorio que este .cpp
		
		// util_fil y util_col DEBEN SER MAYOR DE 0.
		// Estas dos variables indican el numero de filas y columnas de 
		// las matrices.
	
		// Matriz izquierda.
	cin >> util_fil_izda; 
	cin >> util_col_izda;
	for (int i = 0; i < util_fil_izda; i++){
		for (int j = 0; j < util_col_izda; j++)
			cin >> matr_izda[i][j];	
	}
	
		// Matriz derecha.
	cin >> util_fil_dcha; 
	cin >> util_col_dcha;
	for (int i = 0; i < util_fil_dcha; i++){
		for (int j = 0; j < util_col_dcha; j++)
			cin >> matr_dcha[i][j];
	}

	
	// Cómputos.	


	if (util_col_izda == util_fil_dcha){
		continuar = true;
		util_fil_prod = util_fil_izda;
		util_col_prod = util_col_dcha;
		for (int i = 0; i < util_fil_prod; i++){  // Recorrer las filas.
			for (int j = 0; j < util_col_prod; j++) //sólo sirve para indicar posición
				//for (int k = 0; k < util_fil_dcha; k++) ó también vale:
				for (int k = 0; k < util_col_izda; k++) 
				/* Ambos bucles iteracionan tantas veces como número de 
					columnas tenga la matriz de la izquierda o filas de la 
					matriz de la derecha 
				*/
				matr_prod[i][j] += (matr_izda[i][k] * matr_dcha[k][j]);
		}
	}else{
		continuar = false;	
	}
	// Salida de datos.
	
	switch (continuar){
		case true: // Si num de col de la izda == num de fil de la dcha
			cout << "     Matriz izquierda x Matriz derecha = Matriz producto ";
			cout << "\n\n\n";
			cout << "      Matriz izquierda: " << endl;
			for (int i = 0; i < util_fil_izda; i++){ // Recorrer las filas
				cout << "\n";
				for (int j = 0; j < util_col_izda; j++) // Recorrer las columnas
					cout << "\t" << matr_izda[i][j] << " ";
			}
	
			cout << "\n\n";
			cout << "      Matriz derecha: " << endl;
			for (int i = 0; i < util_fil_dcha; i++){	// Recorrer las filas
				cout << "\n";
				for (int j = 0; j < util_col_dcha; j++) // Recorrer las columnas
					cout << "\t" << matr_dcha[i][j] << " ";
			}
	
			cout << "\n\n";
			cout << "      Matriz producto: " << endl;
			for (int i = 0; i < util_fil_prod; i++){	// Recorrer las filas
				cout << "\n";
				for (int j = 0; j < util_col_prod; j++) // Recorrer las columnas
					cout << "\t" << matr_prod[i][j] << " ";
			}
	break;
	case false: // Si num de col de la izda != num de fil de la dcha
		cout << "  _______________________________________________________";
		cout << "\n\n\n";
		cout << " ¡¡ERROR, NO SE PUEDE REALIZAR LA OPERACIÓN!! \n" 
			 << " El número de columnas de la matriz de la izquierda no es "
			 << "igual que el número de filas de la matriz de la derecha. ";	
	break;
	}
	
	cout << "\n\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. \n";	
}

