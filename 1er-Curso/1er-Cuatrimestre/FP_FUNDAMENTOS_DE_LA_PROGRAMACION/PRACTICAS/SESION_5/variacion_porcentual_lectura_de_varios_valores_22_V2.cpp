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
	
	V2, igual que el V1 pero hago una lectura anticipada de la variable y si 
	es positiva entro al bucle y si es negativa no entro, de esta forma me 
	ahorro utilizar el condicional if qu ehe utilizado en la V1.
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
	
	cout << "\n  Para continuar, introduzca el valor inicial del producto."
		 << " Para finalizar, introduzca un valor negativo --> ";
	cin >> valor_ini;
	
	while(valor_ini >= 0){
		cout << "  Introduzca el valor final del producto: ";
		cin >> valor_fi;
		vari_porcen = abs(100*((valor_fi - valor_ini)/valor_ini));
		cout << "\n\t  La variación porcentual es: " << vari_porcen << "%";
		cout << endl;
	}

	
	cout << "\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";		
}
