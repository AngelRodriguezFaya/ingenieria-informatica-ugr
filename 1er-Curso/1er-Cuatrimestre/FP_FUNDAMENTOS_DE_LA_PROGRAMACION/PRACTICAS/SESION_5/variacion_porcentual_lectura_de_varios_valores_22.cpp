/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 26/10/2022
////////////////////////////////////////////////////////////////////////////

/*
	ESTE EJERCICIO ES UNA AMPLIACIÓN DEL EJER 7.[VARIACIÓN PORCENTUAL]
	Programa que calcula la variación porcentual de un producto introduciendóle
	el valor inicial y el valor final del producto. Además, en este programa 
	podremos calcular la variación porcentual de todos los pares que queramos
	hasta que le introduzcamos un valor negativo en la variable: valor_ini.
	
	V1. Para hacer esto último, inicializo la variable para que entre en el 
	bucle y una vez dentro actualizo de nuevo la variable. Si el valor 
	introducido	es negativo no continua, si por el contrario, el valor es 
	positivo, se mete dentro del if y continua con el resto del programa.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 22. VARIACIÓN PORCENTUAL: LECTURA DE VARIOS VALORES";
	cout << endl;	
	
	// Declarar las variables.
	
	double valor_ini;	
	double valor_fi = 0.0;
	double vari_porcen = 0.0;
	
	// Entrada de datos, cómputos y salida de datos.
	while(valor_ini >= 0){
		cout << "\n  Para continuar, introduzca el valor inicial del producto."
			 << " Para finalizar, introduzca un valor negativo --> ";
		cin >> valor_ini;
		if (valor_ini >= 0){
			cout << "  Introduzca el valor final del producto: ";
			cin >> valor_fi;
			vari_porcen = abs(100*((valor_fi - valor_ini)/valor_ini));
			cout << "\n\t  La variación porcentual es: " << vari_porcen << "%";
			cout << endl;
		}
	}
	
	cout << "\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";		
}
