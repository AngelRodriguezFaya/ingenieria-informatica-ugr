/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 31/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	Programa que te indica como actuar ante el COVID-19 en función de
	los sintomas o enfermedades que tengamos.
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

int main(){
	
	cout << "\n\tPROGRAMA: 16. CORONAVIRUS \n\n";
	
	// Declarar las variables.
	
	int bodyTemp;			// bodyTemperature
	
	char diffiBreath,		// difficultyBreathing
		diabetes,
		cancer;
	
	// Entrada de datos.
	
	cout << "  Introduzca su temperatura corporal en grados Celsius -> ";
	cin >> bodyTemp;
	
	cout << "\n  A continuación, responda a las siguientes preguntas con: "
		 << "Sí (S) o No (N)." << endl;
	
	cout << "  ¿Tiene dificultad para respirar? -> ";
	cin >> diffiBreath;
		
	cout << "  ¿Padece de diabetes? -> ";
	cin >> diabetes;
	
	cout << "  ¿Padece algún tipo de cáncer? -> ";
	cin >> cancer;

	// Cómputos.
	
	if (bodyTemp >= 38){
		if (diffiBreath == 'S' || 's'){
			if ((diabetes == 'S' || 's') || (cancer == 'S' || 's' )){
				cout << "\n\t Resultado: Consulte a las autoridades locales.";			
			}
		}
		else if (diabetes == 'S' || 's'){
			cout << "\n\t Resultado: Consulte a las autoridades locales.";			
		}
		else if (cancer == 'S' || 's' ){
			cout << "\n\t Resultado: Consulte a las autoridades locales.";				
		}
		else{
			cout << "\n\t Resultado: Cuarentena en su casa. ";
		}
	}
	else{
		cout << "\n\t Resultado: Test negativo.";
	}

	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}
