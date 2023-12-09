#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 27.EXPRESIONES LÓGICAS. \n\n";

	/*
		Escriba una expresión lógica que sea verdadera si un dato 
		de velocidad es mayor o igual que 100 kilómetros por hora 
		y falso en otro caso.
	*/
	
	int vel = 0;
	bool comprobar;
	
	cout << " Introduce una velocidad (en km/h): ";
	cin >> vel;
	
	comprobar = 100 <= vel;
	
	if (comprobar){
		cout << "\n\t VERDADERO";
	}
	else{
		cout << "\n\t FALSO";
	}

}
