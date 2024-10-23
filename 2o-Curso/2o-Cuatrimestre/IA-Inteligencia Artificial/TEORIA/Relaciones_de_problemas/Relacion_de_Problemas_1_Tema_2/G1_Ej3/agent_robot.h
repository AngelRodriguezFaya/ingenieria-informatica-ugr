#ifndef AGENT__
#define AGENT__

#include <string>
#include <iostream>
using namespace std;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------
class Environment;
class Agent
{
public:
	Agent(){
		CNY70_=false;
		BUMPER_=false;
		Brujula_ =0;
		// Inicializar las variables de estado.
		//he_visto_la_frontera = false;
		//n_casillas = 1;
		girando = false;		
		veces_en_la_frontera = 0;
		girando = 0;	
		ultimo_giro_derecha = false;	
	}

	enum ActionType
	{
	    actFORWARD,
	    actTURN_L,
	    actTURN_R,
		actBACKWARD,
		actPUSH,
		actIDLE
	};

	void Perceive(const Environment &env);
	ActionType Think();

private:
	bool CNY70_;
	bool BUMPER_;
	int Brujula_;	// Nueva declaración, si tiene '_' al final indica que es un sensor.
	// Declaración de las variables de estado
/* 	int n_casillas;				// lleva la cuenta de las casillas recorridas.
	bool he_visto_la_frontera;	//true cuando ya se ha activado al menos una vez CNY70 
	bool girando;				// cuando estoy en mitad (estoy realizando) el giro de 180º
*/
	int veces_en_la_frontera;	// cuenta las veces que se activo CNY70_
	int girando;				// 0 no estoy girando, 1 hice un giro de 90, 2 hice un giro y avance.
	bool ultimo_giro_derecha;	// Si es true, vuelvo a girar a la derecha, si es false a la izquierda.
};	

string ActionStr(Agent::ActionType);

#endif
