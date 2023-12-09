/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación 
// Ingeniería Informática 1º D2
// ETSIIT (Universidad de Granada)
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 27/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 22. Cree un programa principal que haga lo siguiente:
	- Cree dos objetos recta1 y recta2 de la clase Recta.
	
	- Lea seis reales desde teclado. Puede asumir que los valores se 
	  introducirán correctamente y por tanto A y B no serán simultáneamente 
	  cero. Asigne los tres primeros a los coeficientes de recta1 y los otros 
	  tres a recta2. Imprima en pantalla el término independiente de cada recta.

	- Calcule e imprima la pendiente de cada recta.
	
	- Calcule e imprima el ángulo en radianes con respecto al eje 
	  horizontal de cada recta.
	
	- Lea un valor de abscisa e imprima la ordenada según recta1. 
	  A continuación lea un valor de ordenada e imprima la abscisa que 
	  le corresponde.
	
	- Ejecute el método EspejoAbsc sobre recta1 e imprima en pantalla la 
	  pendiente nueva (será la misma que antes pero cambiada de signo).
	  
	  
	LA RECTA ESTÁ FORMADA POR -> Ax + By + C
	
	A -> coef_x
	B -> coef_y
	C -> coef_indep
	
	EL PROGRAMA 24 nos pide que modifiquemos el programa 22 para cambiar los 
	datos de publicos(22) a privados(24). Por lo que habrá que añadir guetters
	y setters.
	  
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

class Recta{
	
	//Atributos.
	private:
		double coef_x, 
			   coef_y,
			   coef_indep;
	
	//Métodos.
	public:
		void SetCoeficientes(double x, double y, double indep);
		double Pendiente();
		double AnguloRadEjeHoriz();
		double Ordenada(double abcisa_intr);
		double Abcisa(double ordenada_intr);
		void EspejoAbsc();
};

void Recta::SetCoeficientes(double x, double y, double indep){
	coef_x = x;
	coef_y = y;
	coef_indep = indep;
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
	
	cout << "\n\tPROGRAMA: 24. RECTA CON DATOS DE MIEMBROS PRIVADOS. \n\n";

	// Declarar las variables.
	
	Recta recta1, recta2;
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
	recta1.SetCoeficientes(coef_x1, coef_y1, coef_indep1);

	coef_x2 = 0;
	coef_y2 = 0;
	coef_indep2 = 0;
	cout << "   Introduzca los tres primeros coeficientes de la Recta 2 -> "
		 << "\n   ";
	cin >> coef_x2 >> coef_y2 >> coef_indep2;
	recta2.SetCoeficientes(coef_x2, coef_y2, coef_indep2);
	
	abcisa_intr = 0;
	cout << "   Introduzca un valor de abcisa -> \n   ";
	cin >> abcisa_intr;
	
	ordenada_intr = 0;
	cout << "   Introduzca un valor de ordenada -> \n   ";
	cin >> ordenada_intr;
	
	
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

