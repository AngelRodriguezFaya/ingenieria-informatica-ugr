/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 25/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que compara dos instantes,
*/

#include <iostream>
using namespace std;
	
int main(){
	
	cout << "\n\tPROGRAMA: 14.COMPARACIÓN DE DOS INSTANTES. ";
	
	int hora1, hora2, min1, min2, seg1, seg2;
	bool h1_men, h1_igu;
	bool m1_men, m1_igu;
	bool s1_men, s1_igu;
		
	cout << "\n\n  Introduzca el primer instante: ";
	cin >> hora1 >> min1 >> seg1;
	cout << "\n  Introduzca el segundo instante: ";
	cin >> hora2 >> min2 >> seg2;
	
	h1_men = hora1 < hora2;
	h1_igu = hora1 == hora2;
	m1_men = min1 < min2;
	m1_igu = min1 == min2;
	s1_men = seg1 < seg2;
	s1_igu = seg1 == seg2;
	
	if (h1_men){
		cout << "\n\t El primer instante es anterior. ";
	}
	else if (h1_igu){
		if (m1_men){
			cout << "\n\t El primer instante es anterior. ";
		}
		else if (m1_igu){
			if (s1_men){
				cout << "\n\t El primer instante es anterior. ";
			}
			else if (s1_igu){
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
