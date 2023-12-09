/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 15/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa en el que introducimos el número de votos de cada partido y nos
	muestra si ha habido una mayoria absoluta en algún partido, o en su 
	defecto, si se consigue una mayoría absoluta al sumar los votos de de los
	partidos (en parejas).
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 11. MAYORÍA ABSOLUTA. \n\n";
	
	int votos_pre_A = 0, votos_co_A = 0,
		votos_pre_B = 0, votos_co_B = 0,
		votos_pre_C = 0, votos_co_C = 0,
		votos_AB = 0, votos_AC = 0,
		votos_BC = 0, total_votos = 0;
	

	bool mayoria_A = 0,
		 mayoria_B = 0,
		 mayoria_C = 0,
		 mayoria_AB = 0,
		 mayoria_AC = 0,
		 mayoria_BC = 0;
	
	string resul = "";
		
	cout << " Introduzca los votos presenciales obtenidos por el partido A: ";
	cin >> votos_pre_A;
	cout << " Introduzca los votos por correo obtenidos por el partido A: ";
	cin >> votos_co_A;
	
	cout << "\n Introduzca los votos presenciales obtenidos por el partido B ";
	cin >> votos_pre_B;
	cout << " Introduzca los votos por correo obtenidos por el partido B: ";
	cin >> votos_co_B;
	
	cout << "\n Introduzca los votos presenciales obtenidos por el partido C: ";
	cin >> votos_pre_C; 
	cout << " Introduzca los votos por correo obtenidos por el partido C: ";
	cin >> votos_co_C;

	total_votos = votos_pre_A + votos_co_A +
				  votos_pre_B + votos_co_B +
				  votos_pre_C + votos_co_C;
	
	votos_AB = votos_pre_A + votos_co_A + votos_pre_B + votos_co_B;
	votos_AC = votos_pre_A + votos_co_A + votos_pre_C + votos_co_C;
	votos_BC = votos_pre_B + votos_co_B + votos_pre_C + votos_co_C;

	mayoria_A = (votos_pre_A + votos_co_A) > (total_votos/2);
	mayoria_B = (votos_pre_B + votos_co_B) > (total_votos/2);
	mayoria_C = (votos_pre_C + votos_co_C) > (total_votos/2);
	
	mayoria_AB = votos_AB > (total_votos/2);
	mayoria_AC= votos_AC > (total_votos/2);
	mayoria_BC = votos_BC > (total_votos/2);

	if (mayoria_A){
		resul = 'A';
	}
	else if (mayoria_B){
		resul = 'B';
	}
	else if (mayoria_C){
		resul = 'C';
	}
	else{
		if (mayoria_AB){
			resul = " AB ";
		}
		if (mayoria_AC){
			resul = resul + " AC ";
		}
		if (mayoria_BC){
			resul = resul + " BC ";
		}
		else{
			cout << "\n\t ERROR EN LOS DATOS.";
			resul = 'X';
		}
	}
	
	resul = "\n\t Mayoría absoluta: " + resul;
	cout << resul << endl;

}

