/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 25/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa 
*/

#include <iostream>
#include <cmath>
using namespace std;
	
int main(){
	
	cout << "\n\tPROGRAMA: 21.VALORES DE GAUSSIANA. " << endl;
	
	/* desviación = desv
	   esperanza = esp
	   máximo = max
	   mínimo = min
	   incremento = incr
	   CONSTANTE = CONST
	   exponente = expo
	   cociente = coci
	*/
	
	double esp, desv, max, min, incr, x;
	double resul_gaus, expo, coci;
	const double CONST = -0.5;
	double PI = 6 * asin(0.5);
	
	cout << "\n  Introduce el valor del parámetro 'esperanza': ";
	cin >> esp;
	
	do{
		cout << "  Introduce el valor (positivo) del parámetro 'desviación': ";
		cin >> desv;
	}while (desv < 0);
	
	cout << "  Introduzca un mínimo: ";
	cin >> min;

	do{
		cout << "  Introduzca un máximo mayor que el mínimo introducido: ";
		cin >> max;
	}while (max < min);
	
	do{
		cout << "  Introduzca el valor de incremento (debe ser positivo): ";
		cin >> incr;
	}while (incr < 0);
	
	for (x = min; x <= max; x += incr){
		expo = (CONST * (pow ((x - esp) / desv, 2)));
		coci = (1 / (sqrt (2 * PI) * desv));
		resul_gaus = (coci * exp(expo));
	}
	
	cout << "\n\t El valor de gaussiana es: " << resul_gaus << endl;
}
	
	
	
	
	
	
	
	
	
	
	
