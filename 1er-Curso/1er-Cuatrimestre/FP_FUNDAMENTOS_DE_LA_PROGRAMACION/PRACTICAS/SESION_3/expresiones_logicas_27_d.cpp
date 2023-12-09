#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 27.EXPRESIONES LÓGICAS. \n\n";

	/*
		Escriba una expresión lógica que sea verdadera si una variable 
		de tipo entero llamada adivine está entre 1 y 100 y falso en 
		otro caso.
	*/
	
	int anio;
	bool comprobar;
	
	cout << " Introduce un año: ";
	cin >> anio;
	
	comprobar = (((anio % 4) == 0) || ((anio % 400) == 0));
		
	if (comprobar){
		cout << "\n\t" << comprobar << " es bisiesto";
	}
	else{
	cout << "\n\t" << comprobar << " es bisiesto";
	}

}
