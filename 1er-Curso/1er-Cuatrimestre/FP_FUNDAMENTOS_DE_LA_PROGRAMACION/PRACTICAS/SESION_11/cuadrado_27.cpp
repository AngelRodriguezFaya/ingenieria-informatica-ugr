/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación 
// Ingeniería Informática 1º D2
// ETSIIT (Universidad de Granada)
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 25/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 
	
*/

#include <iostream>		//  Inclusión de recursos de E/S
#include <cmath>		//  Inclusión de recursos matemáticos.
using namespace std;

class Cuadrado{
	//Atributos.
	private:
		double x = 0;
		double y = 0;
		double longitud_lado = 0;
	//Métodos. Getters -> Devolver valores.		Setters -> Asignar valores.
	public:
		void SetXY(double x_intr, double y_intr);
		void SetLongitud(double longitud_intr);
		double X(){
			return x;
		}
		double Y(){
			return y;
		}
		double Longitud_lado(){
			return longitud_lado;
		}
		double Area();
		double Perimetro();
		
};

void Cuadrado::SetXY(double x_intr, double y_intr){
	x = x_intr;
	y = y_intr;
} 

void Cuadrado::SetLongitud(double longitud_intr){
	longitud_lado = longitud_intr;
}

double Cuadrado::Area(){
	double area;
	area = longitud_lado * longitud_lado;
	return area;
}

double Cuadrado::Perimetro(){
	double perimetro;
	const int LADOS_CUADRADO = 4;
	perimetro = longitud_lado * LADOS_CUADRADO;
	return perimetro;
}

int main(){
	
	cout << "\n\tPROGRAMA 27: CUADRADO. \n\n";

	// Declarar las variables.
	
	double x1 = 0, y1 = 0, lado1 = 0, area1 = 0, perimetro1 = 0;
	double x2 = 0, y2 = 0, lado2 = 0, area2 = 0, perimetro2 = 0;
	
	Cuadrado cuadrado1, cuadrado2;
	
	// Entrada de datos.
	
	cout << "   Introduzca la coordenadas de la esquina inferior izquierda del "
			"\n   primer cuadrado y seguidamente la longitud del lado ->\n   ";
	cin >> x1 >> y1 >> lado1;
	cuadrado1.SetXY(x1,y1);
	cuadrado1.SetLongitud(lado1); 
	
	cout << "   Introduzca la coordenadas de la esquina inferior izquierda del "
			"\n   segundo cuadrado y seguidamente la longitud del lado ->\n   ";
	cin >> x2 >> y2 >> lado2;
	cuadrado2.SetXY(x2,y2);
	cuadrado2.SetLongitud(lado2);
	
	// Cómputos.
	
	area1 = cuadrado1.Area();
	perimetro1 = cuadrado1.Perimetro();
	
	area2 = cuadrado2.Area();
	perimetro2 = cuadrado2.Perimetro();
	
	// Salida de datos.
	
	cout << "\n    Cuadrado 1 -> " << endl;
	cout << "        Coordenadas x = " << cuadrado1.X() << ",  y = " 
	   	 << cuadrado1.Y() << endl;
	cout << "        Longitud: " << cuadrado1.Longitud_lado() << endl;
	cout << "        Área: " << area1 << endl;
	cout << "        Perímetro: " << perimetro1 << endl;
	
	cout << "\n    Cuadrado 2 -> " << endl;
	cout << "        Coordenadas x = " << cuadrado2.X() << ",  y = " 
	   	 << cuadrado2.Y() << endl;
	cout << "        Longitud: " << cuadrado2.Longitud_lado() << endl;
	cout << "        Área: " << area2 << endl;
	cout << "        Perímetro: " << perimetro2 << endl;
	
	
	cout << "\n\n  Fin del programa. Vuelva pronto :)" << endl;
	cout << "  Programa de Ángel Rodríguez Faya. ";	
}
