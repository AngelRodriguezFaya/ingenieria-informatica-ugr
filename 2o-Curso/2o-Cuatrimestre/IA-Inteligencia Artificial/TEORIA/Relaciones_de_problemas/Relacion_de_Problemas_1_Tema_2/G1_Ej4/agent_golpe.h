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
	Agent(int x, int y):
		initializing(true),
		is_bump(false),
		lastX(-1),
		lastY(-1),
		lastAction(actIDLE)
	{
		RobotX_ = 0;
		RobotY_ = 0;
		ObjX_ = x;
		ObjY_ = y;

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				m[i][j] = 0;
			}
		}
		
	}

	enum ActionType
	{
	    actFORWARD,
	    actTURN,
	    actIDLE
	};

	enum Orientacion{
		Norte,
		Este,
		Sur,
		Oeste
	};

	void Perceive(const Environment &env);
	ActionType Think();

private:
	int RobotX_, RobotY_, ObjX_, ObjY_;
	int m[10][10];

	bool initializing, 
		is_bump;	// True si nos hemos chocado
	
	Orientacion orientacion;
	int lastX, lastY;

	ActionType lastAction;
	ActionType initialize();
	bool check_bump(); // Esto es una rutina
};

string ActionStr(Agent::ActionType);

#endif
