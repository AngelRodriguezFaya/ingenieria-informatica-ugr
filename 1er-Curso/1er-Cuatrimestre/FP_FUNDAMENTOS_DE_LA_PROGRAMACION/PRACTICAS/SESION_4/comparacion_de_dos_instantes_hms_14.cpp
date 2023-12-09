/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 25/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que compara dos instantes.
*/

#include <iostream>
using namespace std;
	
int main(){
	
	cout << "\n\tPROGRAMA: 14.COMPARACIÓN DE DOS INSTANTES. ";
	
	int hora1, hora2, min1, min2, seg1, seg2;
		
	cout << "\n\n  Introduzca el primer instante: ";
	cin >> hora1 >> min1 >> seg1;
	cout << "\n  Introduzca el segundo instante: ";
	cin >> hora2 >> min2 >> seg2;
	
	if (hora1 < hora2){
		cout << "\n\t El primer instante es anterior. ";
	}
	else if (hora1 == hora2){
		if (min1 < min2){
			cout << "\n\t El primer instante es anterior. ";
		}
		else if (min1 == min2){
			if (seg1 < seg2){
				cout << "\n\t El primer instante es anterior. ";
			}
			else if (seg1 == seg2){
				cout << "\n\t Los dos instantes son iguales. ";
			}
			else{
				cout << "\n\t El primer instante no es anterior al segundo. ";
			}
		}
		else{
			cout << "\n\t El primer instante no es anterior al segundo. ";
		}
	}
	else{
		cout << "\n\t El primer instante no es anterior al segundo. ";
	}
	
	cout << "\n";
}
