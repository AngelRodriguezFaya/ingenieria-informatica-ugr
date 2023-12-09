/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 10/12/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	PROGRAMA 1: Corrige los errores.
	
	/* ASÍ SE MUESTRA LO QUE FALTA EN EL PROGRAMA O LAS ANOTACIONES. */
	


int Sumale1(/* int entero */)  /* Faltaba pasarle entero como parámetro */
{
	return entero + 1;
}

int Sumale1(int entero)
{
	entero = entero + 1;
	/* return entero */	/* Hay que poner return si no la función no devuelve nada */ 
}

int ValorAbsoluto(int entero)
{
	if (entero < 0)
		entero = -entero;
		/* return entero */	/* Hay que poner return si no la función no devuelve nada */ 
	else
		return entero;
}

bool EsPositivo(int valor)
{
	if (valor > 0)
		return true;
  /*else
  		return false;
  */
}
	
long ParteEntera(double real){	/* A ESTA FUNCIÓN NO LE ENCUENTRO FALLOS */
	int parte_entera;
	parte_entera = trunc(real);
	return parte_entera;
}

// En esta función lo que ocurre es que devuelve entero y después lo suma.
int Sumale1(int entero)
{
	return entero + 1;
	/*return 1+entero */ /* Así si devuelve 6 y no 5 */ 
}
int main(){
	int n = 5;
	Sumale1(n);
	cout << n;
}
