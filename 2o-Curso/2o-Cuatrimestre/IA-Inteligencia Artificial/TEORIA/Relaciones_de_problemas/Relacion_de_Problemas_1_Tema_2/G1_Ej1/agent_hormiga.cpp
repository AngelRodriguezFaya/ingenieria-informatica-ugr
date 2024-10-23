#include "agent_hormiga.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
	ActionType accion = actIDLE;
	
	/* ESCRIBA AQUI LAS REGLAS */
	if(FEROMONA_){
		accion = actFORWARD;
		n_giros = 0;
	}
	else if(n_giros < 1){
		accion = actTURN_R;
		n_giros++;
	}else{
		accion = actTURN_L;
		n_giros++;
	}
	
	return accion;

}
// -----------------------------------------------------------
void Agent::Perceive(const Environment &env)
{
	FEROMONA_ = env.isFeromona();
}
// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actIDLE: return "IDLE";
	default: return "????";
	}
}
