
#ifndef ENVIRONMENT__
#define ENVIRONMENT__

#include <fstream>
using std::ifstream;

#include "agent_hormiga.h"
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
	int OutOfBoderTime() const {return tiempo_salido_;};

	bool isFeromona() const;
private:
	static const int FEROMONA = 2;
	static const char MAP_ROAD = '-', MAP_FEROMONA = 'F';

	int agentPosX_, agentPosY_, agentOriented_; // Orientacion: 0 Norte, 1 Este, 2 Sur, 3 Oeste.
	int maze_[MAZE_SIZE][MAZE_SIZE];
	int tiempo_salido_;	
};
// -----------------------------------------------------------

#endif
