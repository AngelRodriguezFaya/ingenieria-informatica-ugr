/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 19/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa en el quedebemos introducir un carácter y ver si está en 
	mayúscula o minúscula a través de unos condicionales. Si es mayúscula
	debemos trnasformarla a minúscula o al contrario, de minúscula a 
	mayúscula.
*/

/*
	A 65	a 97
	B 66	b 98
	C 67	c 99
	D 68	d 100
	E 69	e 101
	F 70	f 102
	G 71	g 103
	  . 	  .
	  .		  .
	  .		  .
	  
	Como vemos la diferencia entre mayúsculas y minusculas es 32, y es 
	siempre constante.
*/

#include <iostream>
using namespace std;

enum class TipoLetra
	{mayus, minus, no_alfb};
	
int main(){
	
	cout << "\n\tPROGRAMA: 18 MAYÚSCULA A MINÚSCULA Y VICEVERSA USANDO";
	cout << "UN ENUMERADO. \n\n";
	
	const int DIST_MAYUS_MINUS = 'a' - 'A';  // Su valor es 32.
	char letra_org, letra_fin;      //Las variables son char porque son letras.
	TipoLetra tipo_letra;
	
	//Entrada de datos:
	
	cout << " Introduzca la letra: ";
	cin >> letra_org;
	
	//Cómputos:
	
	if (('A' <= letra_org) && (letra_org <= 'Z')){
		letra_fin = letra_org + DIST_MAYUS_MINUS;
		tipo_letra = TipoLetra::mayus;
	}
	else if (('a' <= letra_org) && (letra_org <= 'z')){
		letra_fin = letra_org - DIST_MAYUS_MINUS;
		tipo_letra = TipoLetra::minus;
	}
	else{
		tipo_letra = TipoLetra::no_alfb;
	}
	
	//Salida de Resultados.
	
	cout << "\n\n";
	
	switch (tipo_letra){
		case TipoLetra::mayus:
			cout << "\t La letra era mayúscula. ";
			cout << "Una vez convertida es: " << letra_fin;
			break;
				
		case TipoLetra::minus:
			cout << "\t La letra era minúscula. ";
			cout << "Una vez convertida es: " << letra_fin;
			break;
				
		case TipoLetra::no_alfb:
			cout << "\t El carácter no era una letra. " << letra_fin;
			break;
	}
	
	cout << "\n";

/* ¿Cuál sería el inconveniente de usar dos variables de tipo bool?

	El inconveniente sería que con 2 variables tendríamos 4 opciones y 
	yo sólo necesito 3 opciones. Además resultaría más difícil ya que los
	valores del bool son true/false ó 0/1 ó sí/no, etc.
	
*/

}

