/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 30/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	7. [Tarifa aérea con descuentos] Recupere la solución del ejercicio 
	4 [Tarifa aérea] de esta Relación de Problemas. Una vez se ha obtenido 
	el precio del billete (con el incremento de 10 céntimos por km recorrido, 
	en su caso), se quieren aplicar varios descuentos acumulativos. En este 
	ejercicio (el 26) es aplicar solamente un filtro de entrada de datos para
	que si el cliente introduce un número incorrecto de kilometros o puntos, 
	pide que introduzca datos que sean coherentes y así a la hora de seguir con
	el programa, no de error.
	
	En este ejercicio el filtro de datos lo he hecho mediante un do while.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 26 TARIFA AÉREA CON FILTRO DE ENTRADA DE DATOS \n\n";
		
	// Declarar las constantes, ordenadas según se van utilizando.
	const float TRF_BASE = 150.0;
	const float RECARGO_KM = 0.1;
	const float DTO_700_KMS = 0.02; 
	const float DTO_100_PUNTOS = 0.03;
	const float DTO_200_PUNTOS = 0.04;

	// Declarar las variables, ordenadas según se van utilizando.	
	float dist, ptos,
	      recar_300 = 0,
		  precio = 0,
          dto_700 = 0,
          precio_fin = 0;

	//Introducción de datos.
	
	do{
		cout << "  Introduzca la distancia a su destino (en kilometros): ";
		cin >> dist;
	}while (dist < 0);
	
	cout << endl;
	
	do{
		cout << "  Introduzca el número de puntos que tiene: ";
		cin >> ptos;
	}while ((ptos < 0) || (ptos > 400)); 	
	
	//Cómputos:
	
	//Descuento de Kilómetros.
	if (dist <=300){
		precio = TRF_BASE;
	} else {
		recar_300 = TRF_BASE + ((dist - 300) * RECARGO_KM);
		precio = recar_300;
		if (dist > 700){
			dto_700 = recar_300 - (recar_300 * DTO_700_KMS);
			precio = dto_700;
		}
	}
	
	//Descuentos de puntos.
		if (ptos <=100){       
		precio_fin = precio;
	}
	
	if (ptos > 100){
		precio_fin = precio - (precio * DTO_100_PUNTOS);
	}
	
	if (ptos > 200){
		precio_fin = precio - (precio * DTO_200_PUNTOS); 	
	}
	
	//Salida de datos.
	
	cout << "\n\t El precio final de su billete es: " << precio_fin;
	cout << endl;


	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}

