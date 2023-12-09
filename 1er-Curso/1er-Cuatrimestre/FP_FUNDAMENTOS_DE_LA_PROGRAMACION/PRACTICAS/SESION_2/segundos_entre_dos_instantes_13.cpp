/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 28/09/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que nos calcula la diferencia de tiempo (en segundos) entre dos
	instantes.
*/

#include <iostream>
using namespace std;

	
int main(){
	cout << "\n\tPROGRAMA: SEGUNDOS ENTRE DOS INSTANTES. \n\n";
	
	// 1 hora -> 60 min. -> 3600 seg = (60^2)seg.
	
	const int CONVERSION = 60;
	int hora_i, hora_f, min_i, min_f, seg_i, seg_f, tm_total_i, tm_total_f;
	
	cout << "  Introduzca la hora inicial: ";
	cin >> hora_i;
	cout << "  Introduzca los minutos iniciales: ";
	cin >> min_i;
	cout << "  Introduzca los segundos iniciales: ";
	cin >> seg_i;
	
	cout << "\n  Introduzca la hora final: ";
	cin >> hora_f;
	cout << "  Introduzca los minutos finales: ";
	cin >> min_f;
	cout << "  Introduzca los segundos finales: ";
	cin >> seg_f;
	
	tm_total_i = hora_i * (CONVERSION*CONVERSION)+ min_i * CONVERSION + seg_i;
	tm_total_f = hora_f * (CONVERSION*CONVERSION)+ min_f * CONVERSION + seg_f;
	
	cout << "\n\tLa diferencia en segundos, entre ambos, es: ";
	cout << tm_total_f - tm_total_i;
	
}
