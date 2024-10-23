
#ifndef ENVIRONMENT__
#define ENVIRONMENT__

#include <fstream>
using std::ifstream;

#include "agent_robot.h"
// -----------------------------------------------------------
//				class Environment
// -----------------------------------------------------------

class RandomNumberGenerator;

class Environment
{
public:
	static const int MAZE_SIZE = 10;

	Environment(ifstream &infile);
	void Show(int,int) const;
	void AcceptAction(Agent::ActionType);
	bool isFrontier() const;
	bool isBump() const;
	int where() const {return agentOriented_;};	// NUUEVO METODO DEFINIDO, Devuelve una varibale de la clase que indica la orientación
	int OutOfBoderTime() const {return tiempo_salido_;};
private:
	static const int OBSTACLE = -1;
	static const int FRONTIER = -2;
	static const char MAP_ROAD = '-', MAP_FRONTIER = 'T', MAP_OBSTACLE = 'O';
	
	int agentPosX_, agentPosY_, agentOriented_; // Orientacion: 0 Norte, 1 Este, 2 Sur, 3 Oeste.
	int objectPosX_, objectPosY_;
	int maze_[MAZE_SIZE][MAZE_SIZE];
	int tiempo_salido_;
};
// -----------------------------------------------------------

#endif
