/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 05/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que opera expresiones lógicas en distintos casos.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 27.EXPRESIONES LÓGICAS. \n\n";

	/*
		Escriba una expresión lógica que sea verdadera si una variable
		de tipo carácter llamada letra es una letra minúscula y falso 
		en otro caso.
	*/	
	
	char letra;
	bool resul_a;
	
	cout << " Introduce una letra: ";
	cin >> letra;
	
	resul_a = (('a' <= letra) && (letra <= 'z'));
	
	if (resul_a){
		cout << "\t Resultado: " << resul_a << "\n\n";
	}
	else{
		cout << "\t Resultado: " << resul_a << "\n\n";
	}


	/*
		Escriba una expresión lógica que sea verdadera si una variable 
		de tipo entero llamada edad es menor de 18 o mayor de 65 
		y falso en otro caso.
	*/
	
	int edad = 0;
	bool resul_b;
	
	cout << " Introduce tu edad: ";
	cin >> edad;
	
	resul_b = ((edad < 18) || (edad > 65));
	
	if (resul_b){
		cout << "\t Resultado: " << resul_b << "\n\n";
	}
	else{
		cout << "\t Resultado: " << resul_b << "\n\n";
	}

	/*
		Escriba una expresión lógica que sea verdadera si una variable 
		de tipo entero llamada adivine está entre 1 y 100 y falso en 
		otro caso.
	*/
	
	int adivine = 0;
	bool resul_c;
	
	cout << " Introduce un número: ";
	cin >> adivine;
	
	resul_c = ((1 < adivine) && (adivine < 100));
	
	if (resul_c){
		cout << "\t Resultado: " << resul_c << "\n\n";
	}
	else{
		cout << "\t Resultado: " << resul_c << "\n\n";
	}

	/*
		Escriba una expresión lógica que sea verdadera si un año es bisiesto 
		y falso en otro caso. Los años bisiestos son aquellos que o bien son 
		divisibles por 4 pero no por 100, o bien son divisibles por 400. 
	*/
	
	int anio;
	bool resul_d;
	
	cout << " Introduce un año: ";
	cin >> anio;
	
	resul_d = (((anio % 4) == 0) || ((anio % 400) == 0));
		
	if (resul_d){
		cout << "\t Resultado: " << resul_d << "\n\n";
	}
	else{
		cout << "\t Resultado: " << resul_d << "\n\n";
	}

	/*
		Escriba una expresión lógica que sea verdadera si un dato 
		de velocidad es mayor o igual que 100 kilómetros por hora 
		y falso en otro caso.
	*/
	
	int vel = 0;
	bool resul_e;
	
	cout << " Introduce una velocidad (en km/h): ";
	cin >> vel;
	
	resul_e = (100 <= vel);
	
	if (resul_e){
		cout << "\t Resultado: " << resul_e << "\n\n";
	}
	else{
		cout << "\t Resultado: " << resul_e << "\n\n";
	}

	/*
		Escriba una expresión lógica que sea verdadera si un carácter 
		es una vocal (sólo se consideran vocales las minúsculas sin 
		acentos) y falso en otro caso.
	*/
	
	char vocal = (('a') || ('e') || ('i') || ('o') || ('u')); 
	char letra2;	// letra ya se ha utilizado antes, por eso es letra2
	bool resul_f;
	
	cout << " Introduce una letra: ";
	cin >> letra2;
	
	resul_f = (letra2 == vocal);
		
	if (resul_f){
		cout << "\t Resultado: " << resul_f << "\n\n";
	}
	else{
		cout << "\t Resultado: " << resul_f << "\n\n";
	}

}

