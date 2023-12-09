/////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Ángel Rodríguez Faya
// Correo: arf04@correo.ugr.es
// Fecha de creación: 20/10/2022																			
////////////////////////////////////////////////////////////////////////////

/*
	8. [Tabulación] . Indique si los siguientes trozos de código están 
	correctamente tabulados	según las normas indicadas en clase. En caso 
	de que no lo estén, re-escríbalos:
*/

// ESTO SÓLO ES UN ARCHIVO DE CÓMO QUEDARÍAN ESTAS CONDICIONES BIEN INDENTADAS
// POR ESO NO HE PUESTO iostream NI using namespace std NI int main(){}.

//a)
	if (edad > 18){
		es_mayor_edad = true;		
	}
	else{
		es_mayor_edad = false;
	}

//b) 

	if (edad > 18){
		if (ingresos <= MAX_INGRESOS){
			suscept_ayuda = true;
		}
		else{
		suscept_ayuda = false;
		}
	}
	else if (ingresos > MIN_INGRESOS){
		suscept_ayuda = true;
	}
	else{
		suscept_ayuda = false;
	}

