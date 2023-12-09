/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 29/11/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 17:Recupere la solución del ejercicio 16. Se pide que:
	
	- Resuelva el mismo problema pero de una forma eficiente.
	
	- El texto del Quijote viene preparado para que la lectura de datos sea tal 
	  y como se indica en el ejercicio 16. 
	  
	- Como va a almacenar todo el texto del Quijote en un vector de caracteres, 
	  debe dimensionar éste con una constante grande, por ejemplo 2e7. 
	  
	- Al ser un vector muy grande, recuerde compilar el programa con las 
	  instrucciones detalladas en la página Problemas-68.
	  
	- Tendrá que redirigir la entrada de datos para que el programa lea los 
	  valores del fichero. También debe redirigir la salida de datos para que 
	  el programa construya un fichero nuevo.
	
	- Para resolver eficientemente este problema se propone utilizar dos 
	  variables, pos_lectura y pos_escritura que nos vayan indicando, en cada 
	  momento, la componente que se está leyendo y el sitio dónde tiene que 
	  escribirse.
	
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA 17: ELIMINE LAS OCURRENCIAS DE UNA COMPONENTE. " 
		 << "(VERSIÓN EFICIENTE)"<< endl;
	
	// Declarar las variables, constantes y vectores.
	
	const char TERMINADOR = '#';
	const int MAX_NUM_CARACT = 3e6; // Compilar con la opción, -Wl,--stack,21000000
	char v[MAX_NUM_CARACT];
	char v_aux[MAX_NUM_CARACT];
	char a_borrar, caract;
	int i = 0,
		util = 0,
		pos_lectura = 0,
		pos_escritura = 0;
	
	// Entrada de datos.
	
	caract = cin.get();
	
	while (caract != TERMINADOR){
		v[i] = caract;
		caract = cin.get();
		i++;
	}
	
	util = i;
	a_borrar = cin.get();	// Este es el caracter que debemos eliminar.
	
	// Cómputos. 
	
	while (pos_lectura < util){
		if (v[pos_lectura] == a_borrar){
			pos_lectura++;
		}else{
			v_aux[pos_escritura]= v[pos_lectura];
			pos_escritura++;
			pos_lectura++;
		}
	}
	
	cout << "<";
	   
   for (int i = 0; i < util; i++)
      cout << v[i] ;
      
   cout << ">";
	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. \n";	
}

