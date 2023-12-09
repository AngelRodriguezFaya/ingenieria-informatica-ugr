/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 10/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 20: Corrige los errores en las funciones de tipo VOID.
	
	/* ASÍ SE MUESTRA LO QUE FALTA EN EL PROGRAMA O LAS ANOTACIONES. */
	

void Imprime(double valor)
{
	/* double valor; Esto sobra ya que 'valor' ya se le pasa como parámetro */
	cout << valor;
}

void Cuadrado (int entero)
{
	/* return entero*entero; Esto está mal ya que la función void no devuelve nada */
	/* Habría que poner :
	cout << entero*entero; */
}


int Cuadrado (int entero)
{
	entero = entero*entero;
}

/* Para empezar, está función no es de tipo void, sino int, por lo que necesita
	un return para devolver el valor. 
	
	Si fuera de tipo void no necesitaría el return. Si queremos mostrar el
	resultado, quedaría tal que así:
	
	void Cuadrado (int entero){
		entero = entero*entero;
		cout << entero;
	}
*/
