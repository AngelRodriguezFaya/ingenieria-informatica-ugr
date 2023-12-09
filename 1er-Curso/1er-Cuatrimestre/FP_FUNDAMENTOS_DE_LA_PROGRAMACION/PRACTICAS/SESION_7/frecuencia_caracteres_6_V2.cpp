/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/11/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 6: En este ejercicio vamos a contar el número de ocurrencias
	de ciertos caracteres en un texto.
	
	(V2) El vector frecuencias contendrá sólo las frecuencias de los caracteres 
	de texto que están en el vector a_buscar.
	
	La entrada de caracteres se debe hacer con la instrucción: 
	caracter = cin.get() y no con cin >> caracter.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA 6 (V2): FRECUENCIA DE CARACTERES  \n" << endl;
	
	// Declarar las variables, vectores y constantes.
	
	const char TERMINADOR = '@';
	const int NUM_CARACT_ASCII = 256;
	const int MAX_NUM_CARACT = 10000; // Diez mil
	
	char a_buscar[NUM_CARACT_ASCII];
	char texto [MAX_NUM_CARACT];
	int frecuencias[NUM_CARACT_ASCII];
	
	char caract;
	int longitud_a_buscar = 0,
		longitud_texto = 0;
	
	// Entrada de datos.	

		// a_buscar
	cout << "  Introduzca la serie de caracteres del vector a buscar. "
	     << "Para terminar, introduzca " << TERMINADOR << " -> \n  ";

	caract = cin.get();
	while ((caract != TERMINADOR) && (longitud_a_buscar < NUM_CARACT_ASCII)){
	    a_buscar[longitud_a_buscar] = caract;
		caract = cin.get();
		longitud_a_buscar++;
	}
	
		// texto
	cout << "\n  Y a continuación, introduzca la serie de caracteres del texto."
	     << " Finalice con el mismo terminador -> \n  ";
	caract = cin.get();   
	while ((caract != TERMINADOR) && (longitud_texto < MAX_NUM_CARACT)){
		texto[longitud_texto] = caract;
		caract = cin.get();
		longitud_texto++;
	}

	// Cómputos.
	
	for (int i = 0; i < longitud_a_buscar; i++){
		frecuencias[i] = 0;
		for (int j = 0; j < longitud_texto; j++){
			if (texto[j] == a_buscar[i])
				frecuencias[i]++;
		}
		
	}
	
	// Salida de datos.
	
	cout << "\n";
	for (int j = 0; j < longitud_a_buscar; j++){
		cout << "  Carácter '" << a_buscar[j] << "': "
			 << frecuencias[j] << endl;
	}

	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. " ;	
}

