#include "agent_robot.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
	ActionType accion = actFORWARD;
	
	/* ESCRIBA AQUI SUS REGLAS */
	/* 	Apartado a)
	if(girando){
		std::cout<<"Regla 1: Terminar el giro de 180 grados\n";
		accion = actTURN_R;
		girando = false;
	}else if(CNY70_ and !he_visto_la_frontera){
		std::cout << "Regla 2: Primera vez en la frontera\n";
		accion = actTURN_R;
		girando = true;
		he_visto_la_frontera = true;
		n_casillas = 1;
	}else if(CNY70_ and he_visto_la_frontera){ 	// La 2a condición no es necesaria ya que si ha llegado a este punto, es porque ha encontrado la frontera
		std::cout << "Regla 3: Termino de contar\n";
		std::cout << "El número de casillas es: " << n_casillas << "\n";
		accion = actIDLE;
	}else{
		std::cout << "Regla 4: regla por defecto -> avanzar\n";
		accion = actFORWARD;
		n_casillas++;
	} */
	if(BUMPER_){
		std::cout << "Regla 1: Encontré el obstáculo\n";
		accion = actIDLE;
	}else if(CNY70_ && girando == 0 && (veces_en_la_frontera % 2) == 0){
		std::cout << "Regla 2: Acabo de llegar a la frontera par y giro a la izquierda.\n";
		girando = 1;
		accion = actTURN_L;
	}else if(CNY70_ && girando == 0 && (veces_en_la_frontera % 2) != 0){
		std::cout << "Regla 3: Acabo de llegar a la frontera impar y giro a la derecha.\n";
		girando = 1;
		accion = actTURN_R;
	}else if(girando == 1 && !CNY70_){		
		std::cout << "Regla 4: Avanzo una posicion\n";
		girando = 2;
		accion = actFORWARD;
	}else if(girando == 1 && CNY70_){		
		std::cout << "Regla 6: Estoy en la esquina: ";
		girando = 0;
		if((veces_en_la_frontera % 2) == 0){
			accion = actTURN_L;
			cout << "sup. izq. de la frontera y giro 90º a la izquierda\n";
		}else{
			accion = actTURN_R;
			cout << "sup. dcha. de la frontera y giro 90º a la derecha\n";
		}
	}else if(girando == 2 && (veces_en_la_frontera % 2) == 0){
		std::cout << "Regla 7: Estoy en frontera par y termino el giro de 180º\n";
		girando = 0;
		accion = actTURN_L;
		veces_en_la_frontera++;
	}else if(girando == 2 && (veces_en_la_frontera % 2) != 0){
		std::cout << "Regla 8: Estoy en frontera impar y termino el giro de 180º\n";
		girando = 0;
		accion = actTURN_R;
		veces_en_la_frontera++;
	}else if(girando == 0){
		std::cout << "Regla 9: Avanzo\n";
		accion = actFORWARD;
	} 

	return accion;

}
// -----------------------------------------------------------
void Agent::Perceive(const Environment &env)
{
	CNY70_ = env.isFrontier();
	BUMPER_ = env.isBump();
	Brujula_ = env.where();
}
// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actBACKWARD: return "BACKWARD";
	case Agent::actPUSH: return "PUSH";
	case Agent::actIDLE: return "IDLE";
	default: return "???";
	}
}
