#include "agent_golpe.h"
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

	/* ESCRIBA AQUI SUS REGLAS */
	if(initializing) accion = initialize();
	if(!initializing){
		//Actualizar mapa
	}

	// Guardamos la ultima posicion y accion
	lastAction = accion;
	lastX = RobotX_;
	lastY = RobotY_;
	return accion;

}
// -----------------------------------------------------------
void Agent::Perceive(const Environment &env)
{
	RobotX_ = env.AgentPosX();
	RobotY_ = env.AgentPosY();
	ObjX_ = env.ObjPosX();
	ObjY_ = env.AgentPosY();

	is_bump = check_bump();
}
// -----------------------------------------------------------
bool Agent::check_bump(){
	// Si la ultima accion fue avanzar y el robot sigue en la misma 
	// posicion que antes, entiendo que me he chocado
	return (lastAction = actFORWARD) and (RobotX_ == lastX) 
	and (RobotY_ == lastY);
}
// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN: return "TURN";
	case Agent::actIDLE: return "IDLE";
	default: return "???";
	}
}
// -----------------------------------------------------------
Agent::ActionType Agent::initialize(){
	ActionType accion = actIDLE;
	// Si no es la primera vez que me muevo y ha cambiado mi posicion
	// vamos a descubrir como ha cambiado
	if((lastX != -1) and (lastX != RobotX_ ) or (lastY != RobotY_)){
		int offX = RobotX_ - lastX;
		int offY = RobotY_ - lastY;

		if(offX == 1)
			orientacion = Orientacion::Este;
		else if(offX == -1)
			orientacion = Orientacion::Oeste;
		else if(offY == 1)
			orientacion = Orientacion::Norte;
		else if(offY == -1)
			orientacion = Orientacion::Sur;
		else
			throw "Error: No se ha podido obtener la orientacion";

		cout << "Orientacion: " << orientacion << endl;
		//break initializing
		initializing = false;

	}else{
		if(is_bump) //si me he chocado...
			accion = actTURN; //Roto
		else		//si no ...
			accion = actFORWARD; //Avanzo
	}

	return accion;
}