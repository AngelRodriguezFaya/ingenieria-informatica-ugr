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
	
	int adivine = 0;
	bool comprobar;
	
	cout << " Introduce un número: ";
	cin >> adivine;
	
	comprobar = 1 < adivine && adivine < 100;
	
	if (comprobar){
		cout << "\n\t VERDADERO";
	}
	else{
		cout << "\n\t FALSO";
	}

}
