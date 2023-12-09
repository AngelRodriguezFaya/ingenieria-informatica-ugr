/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación.
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// DNI: 21037906-J
// Correo: arf04@correo.ugr.es
// Fecha de creación: 30/11/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	------------------------------------------------------------------------
		    EXAMEN FP(P) 1º INGENIERÍA INFORMÁTICA GRUPO D2
	------------------------------------------------------------------------  
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: EJERCICIO 3 EXAMEN FP(P) 1ºD2. \n" << endl;
	
	// Declarar las variables, constantes y vectores.
	
	const int MAX_NUM_VECTOR = 100;
	int conjunto[MAX_NUM_VECTOR];
	int num = 0,
		util_conjunto = 0,
		antiguo_max = 0, // diez mil
		total_series = 0, 
		pos_recorrida = 0;
	
	// Entrada de datos
	
	cout << "\n  Introduzca los números que componen el vector. "
		 << "Para finalizar introduzca -1. -> \n  ";
	num = cin.get();
	while (num != -1){
		conjunto[util_conjunto] = num;
		cin.get();
		util_conjunto ++;
	}

	// Cómputos.
	
	for (int i = 0; i < util_conjunto; i++)
		posiciones_fin_serie[i] = 0;
	
	for (int i = 0; i < 7; i++){
		if (conjunto[i] > antiguo_max){
			antiguo_max = conjunto[i];
		}else{
			total_series++;
			antiguo_max = 0;
		}
	}
	
	cout << " En total hay " << total_series << " series" << endl;
	
	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. \n";	
}

