/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación 
// Ingeniería Informática 1º D2
// ETSIIT (Universidad de Granada)
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 30/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	29. [Recta con constructor] Recupere la solución del ejercicio 24 [Recta 
	con datos miembros privados] Modifique el programa principal e imprima los 
	valores de los datos miembros de una recta, antes de asignarles los 
	coeficientes. Mostrará, obviamente, un valor indeterminado. Para evitar 
	este problema, añada un constructor a la recta para que el objeto esté en 
	un estado válido en el mismo momento de su definición. El constructor 
	deberá tener como parámetros, obligatoriamente, los tres coeficientes de la 
	recta. Tendrá que modificar convenientemente el main para tener en cuenta 
	este cambio.
	
	Vuelva a recuperar el método SetCoeficientes. Añada un método privado que
	nos indique si los coeficientes son correctos, es decir, A y B no pueden 
	ser simultáneamente nulos. Llame a este método donde sea necesario.
	  
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

class Recta{
	
	//Atributos.
	private:
		double coef_x = NAN, 
			   coef_y = NAN,
			   coef_indep = NAN;
		
		bool SonCorrectos(double coef_x, double coef_y){
			if (coef_x != 0 && coef_y != 0)
				return true;
			else
				return false;	
		}
		
	//Métodos.
	public:
		Recta(double x, double y, double indep){
			SetCoeficientes(x, y, indep);			
		}
		void SetCoeficientes(double x, double y, double indep);
		double Pendiente();
		double AnguloRadEjeHoriz();
		double Ordenada(double abcisa_intr);
		double Abcisa(double ordenada_intr);
		void EspejoAbsc();
};

void Recta::SetCoeficientes(double x, double y, double indep){
	if (SonCorrectos(x, y)){
		coef_x = x;
		coef_y = y;
		coef_indep = indep;
	}
}

double Recta::Pendiente(){
	double pendiente;
	pendiente = -coef_x/coef_y;
	return pendiente;
}

double Recta::AnguloRadEjeHoriz(){
	double angulo;
	angulo = atan(Recta::Pendiente());
	return angulo;
}

double Recta::Ordenada(double abcisa_intr){
	double y;
	y = (- coef_indep - abcisa_intr * coef_x) / coef_y;
	return y;
}

double Recta::Abcisa(double ordenada_intr){
	double x;
	x = (-coef_indep - ordenada_intr * coef_y) / coef_x;
	return x;
}

void Recta::EspejoAbsc(){
	if (coef_y != 0 && coef_x != 0)
		coef_y = -1 * coef_y;
}

int main(){
	
	cout << "\n\tPROGRAMA: 29. RECTA CON CONSTRUCTOR. \n\n";

	// Declarar las variables.
	
	double coef_x1, coef_y1, coef_indep1, pendiente1, angulo1;
	double coef_x2, coef_y2, coef_indep2, pendiente2, angulo2;
	double  ordenada_intr, ordenada, abcisa_intr, abcisa, pendiente_espejo;
	
	// Entrada de datos.
	
	coef_x1 = 0;
	coef_y1 = 0;
	coef_indep1 = 0;
	cout << "   Introduzca los tres primeros coeficientes de la Recta 1 -> "
		 << "\n   ";
	cin >> coef_x1 >> coef_y1 >> coef_indep1;

	coef_x2 = 0;
	coef_y2 = 0;
	coef_indep2 = 0;
	cout << "   Introduzca los tres primeros coeficientes de la Recta 2 -> "
		 << "\n   ";
	cin >> coef_x2 >> coef_y2 >> coef_indep2;
	
	abcisa_intr = 0;
	cout << "   Introduzca un valor de abcisa -> \n   ";
	cin >> abcisa_intr;
	
	ordenada_intr = 0;
	cout << "   Introduzca un valor de ordenada -> \n   ";
	cin >> ordenada_intr;
	
	Recta recta1(coef_x1, coef_y1, coef_indep1), recta2(coef_x2, coef_y2, coef_indep2);
	
	// Cómputos.
	
	pendiente1 = 0;
	angulo1 = 0;
	pendiente1 = recta1.Pendiente();
	angulo1 = recta1.AnguloRadEjeHoriz();

	pendiente2 = 0;
	angulo2 = 0;
	pendiente2 = recta2.Pendiente();
	angulo2 = recta2.AnguloRadEjeHoriz();
	
	ordenada= 0;
	abcisa = 0;
	ordenada = recta1.Ordenada(abcisa_intr);
	abcisa = recta1.Abcisa(ordenada_intr);
	recta1.EspejoAbsc(); // Recta Espejo
	pendiente_espejo = recta1.Pendiente(); // Pendiente R.Espe
	
	// Salida de datos.
	
	cout << "\n   Término independiente de la Recta 1: " << coef_indep1 << endl;
	cout << "   Término independiente de la Recta 2: " << coef_indep2 << endl;
	cout << "   Pendiente de la Recta 1: " << pendiente1 << endl;
	cout << "   Pendiente de la Recta 2: " << pendiente2 << endl;	
	cout << "   Ángulo en radianes con el eje horizontal en la Recta 1: "
		 << angulo1 << endl;
	cout << "   Ángulo en radianes con el eje horizontal en la Recta 2: "
		 << angulo2 << endl;	
	cout << "   Ordenada de la recta 1 en " << abcisa_intr << " = "
		 << ordenada << endl;
	cout << "   Abcisa de la recta 1 en " << ordenada_intr << " = "
		 << abcisa << endl;
	cout << "   Pendiente del espejo de la Recta 1: " << pendiente_espejo;


	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}

