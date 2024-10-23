
#ifndef ENVIRONMENT__
#define ENVIRONMENT__

#include <fstream>
using std::ifstream;

#include "agent_golpe.h"
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
        int AgentPosX() const;
        int AgentPosY() const;
        int ObjPosX() const;
        int ObjPosY() const;
	bool isBump() const;
private:
	static const int DESTINATION = -1;
        static const int OBSTACLE = -2;
        static const char MAP_ROAD = '-', MAP_OBSTACLE = 'O', MAP_DESTINATION = 'X';
	
	int agentPosX_, agentPosY_, agentOriented_; // Orientacion: 0 Norte, 1 Este, 2 Sur, 3 Oeste.
	int ObjX_, ObjY_;
	int maze_[MAZE_SIZE][MAZE_SIZE];
	int tiempo_salido_;
};
// -----------------------------------------------------------

#endif
