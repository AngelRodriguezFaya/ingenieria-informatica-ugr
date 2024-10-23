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
	    FEROMONA_=false;
		// Inicializar las variables de estado.
		n_giros = 0;
	}

	enum ActionType
	{
	    actFORWARD,
	    actTURN_L,
	    actTURN_R,
		actIDLE
	};

	void Perceive(const Environment &env);
	ActionType Think();

private:
	bool FEROMONA_;
	// DEclaro las variables de estado
	int n_giros; // El número de giros dados por el agente en la casilla actual.
};

string ActionStr(Agent::ActionType);

#endif
