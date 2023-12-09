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

int potencia (double base, double exponente)
{
	double resultado;
	resultado = exp(exponente*log(base));
	return resultado;
}

double mediageom (double x[], double n)
{
	double base = 1,
		   resultado = 0;
	for (int i = 0; i < n; i++)
		base = base * x[i];
	resultado = potencia(base, 1/n);
	return resultado;
}

int main(){
	
	cout << "\n\tPROGRAMA: EJERCICIO 2 EXAMEN FP(P) 1ºD2. \n" << endl;
	
	// Declarar las variables, constantes y vectores.
	
	const int MAX_NUM_VECTOR = 100;
	double bas = 0,		// base
		   expo = 0; 	// exponente
	int total_nums = 0;
	double nums = 0;
	double x[MAX_NUM_VECTOR];
	
	// Entrada de datos.
	
	cout << "  ¿Cuántos números va a guardar en el vector? -> \n  ";
	cin >> total_nums;
	
	cout << "\n  De acuerdo. Ahora introduzcalos -> \n  ";
	for (int i = 0; i < total_nums; i++){
		cin >> nums;
		x[i] = nums;
	}
	
	cout << " ¡Datos guardados correctamente! ";
	
	// Cómputos -> Lo realizan las funciones.
	
	// Salida de datos.
	
	cout << " El resultado es: " << mediageom(x[], total_nums);
	
	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. \n";	
}

