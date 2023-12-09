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

double potencia (double base, double exponente)
{
	double resultado;
	resultado = exp(exponente*log(base));
	return resultado;
}

int main(){
	
	cout << "\n\tPROGRAMA: EJERCICIO 1 EXAMEN FP(P) 1ºD2. \n" << endl;
	
	double bas = 0,		// base
		   expo = 0; 	// exponente
	
	cout << "  Introduzca la base -> \n  ";
	cin >> bas;
	
	cout << "  Introduzca el exponente -> \n  ";
	cin >> expo;
	
	cout << "\n La potencia de " << bas << " elevado a " << expo
		 << " es " << potencia(bas, expo);

	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. \n";	
}

