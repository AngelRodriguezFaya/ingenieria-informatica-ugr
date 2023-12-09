/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 19/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa en el que introducimos una velocidad y dependiendo del tipo de
	radar nos calcula la velocidad imputada, ya que cada tipo de radar tiene 
	un margen de error. 
*/

#include <iostream>
using namespace std;

int main(){

	cout << "\n\tPROGRAMA: 12.VELOCIDAD IMPUTADA";

	double velo_cap = 0.0, //Es double y no int porque tiene que ser un nº real
		velo_imp = 0.0;
	char letra_radar;
	string tipo_radar;

	
	cout << "\n  Introduzca el tipo de radar "
		 << "('F' para fijo y 'cualquier otra letra' para el móvil): ";
	cin >> letra_radar;
	
	cout << "  Introduzca su velocidad captada: ";
	cin >> velo_cap;
	
	if ((letra_radar == 'F') || (letra_radar == 'f')){
		tipo_radar = "fijo";
		if (100 >= velo_cap){
			velo_imp = velo_cap - 5;
		}
		else{
			velo_imp = velo_cap - ((velo_cap * 5)/100);
		}
	}
	else{
		tipo_radar = "movil";
		if (100 >= velo_cap){
			velo_imp = velo_cap - 7;
		}
		else{
			velo_imp = velo_cap - ((velo_cap * 7)/100);
		}
	}

	cout << "\n\t Un radar de tipo " << tipo_radar 
		 << " le ha pillado a " << velo_imp << " km/h.";
}
