/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación 
// Ingeniería Informática 1º D2
// ETSIIT (Universidad de Granada)
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 30/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	
	  
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

class Instante{
	
	//Atributos.
	private:
		int num_horas = -1,
		    num_min = -1,
		    num_seg = -1;
	
	//Métodos.
	public:
		static const int HORA_A_MIN = 60,
						 HORA_A_SEG = 3600,
						 MIN_A_SEG = 60;
		void SetHoraMinutoSegundo(int hora, int minuto, int segundo);
		double SegundosTranscurridos();
		double MinutosTranscurridos();
		
		

};


void Instante::SetHoraMinutoSegundo(int hora, int minuto, int segundo){
	num_horas = hora;
	num_min = minuto;
	num_seg = segundo;
}

double Instante::SegundosTranscurridos(){
	int horas = num_horas, 
		minutos = num_min, 
		segundos = num_seg, 
		segundos_totales;
	while(horas > 0){
		horas--;
		segundos_totales += HORA_A_SEG;
	}
	while(minutos > 0){
		minutos --;
		segundos_totales += MIN_A_SEG;
	}
	while(segundos > 0){
		segundos--;
		segundos_totales++;
	}
	return segundos_totales;
}

double Instante::MinutosTranscurridos(){
	int horas = num_horas, 
		minutos = num_min, 
		segundos = num_seg, 
		minutos_totales;
	while(horas > 0){
		horas--;
		minutos_totales += HORA_A_MIN;
	}
	while(minutos > 0){
		minutos --;
		minutos_totales++;
	}
	while(segundos >= 60){
		segundos -= 60;
		minutos_totales++;
	}
	return minutos_totales;
}
		








int main(){
	
	cout << "\n\tPROGRAMA 32: DISEÑO DE LA INTERFAZ DE LA CLASE INSTANTE. \n\n";


















	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}

