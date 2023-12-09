/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 05/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa en el que introducimos un número en una variable de tipo
	"char" y nos devuelve ese mismo número en una variable de tipo "int". 
	Para ello debemos de mirar la tabla ASCII y ver la relación que existe
	entre un número literal o carácter y un número entero.
*/

/*
	int entero;
	char caracter;
	
	cin >> caracter;
	entero = caracter;

	caracter = '7';
	entero = caracter;
	
	En este código que nos proporciona el enunciado, el valor que se 
	almacenaría en la variable entero seria 55 y no 7, que es el valor que
	queremos. 55 es el valor en la tabla ASCII de '7', por lo que si 
	queremos es mostrar ese número de verdad, debemos de hacer lo 
	siguiente:
	
		55 - 7 = 48
	48 en la tabla ASCII corresponde con el '0', por lo que cada vez que 
	queramos obtener un número, almacenado en una variable de tipo literal,
	y que no se nos asigne su valor de la tabla ASCII, debemos de restarle
	48 para obtener su valor.
	
	EL EJEMPLO SE PUEDE VER EN EL SIGUIENTE PROGRAMA: 

*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 26. PASAR DE CARÁCTER A ENTERO. \n\n";
	
	int entero;
	char crter;
	
	cout << " Introduzca un número: ";
	cin >> crter;
	
	entero = crter - 0;
	
	cout << "\n\t Ha introducido: " << crter << " (cin de un char) ";
	cout << " y ha obtenido " << entero << " (cout de un int).";
	
}

