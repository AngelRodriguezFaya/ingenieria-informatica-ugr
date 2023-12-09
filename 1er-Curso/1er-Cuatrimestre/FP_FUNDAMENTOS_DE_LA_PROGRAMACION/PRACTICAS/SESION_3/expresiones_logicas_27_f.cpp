#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 27.EXPRESIONES LÓGICAS. \n\n";

	/*
		Escriba una expresión lógica que sea verdadera si un carácter 
		es una vocal (sólo se consideran vocales las minúsculas sin 
		acentos) y falso en otro caso.
	*/
	
	char cter = ('a', 'e', 'i', 'o', 'u');
	char letra2;
	bool comprobar;
	
	cout << " Introduce una letra: ";
	cin >> letra2;
	
	comprobar = (letra2 == cter);
		
	if (comprobar){
		cout << "\n\t VERDADERO" << comprobar;
	}
	else{
		cout << "\n\t FALSO" << comprobar;
	}

}
