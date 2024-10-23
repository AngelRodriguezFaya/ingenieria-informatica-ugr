
#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include "stdlib.h"

#include "environment.h"
#include"include/GL/glui.h"

Environment::Environment(ifstream &infile)
{
	string comment;
	getline(infile, comment);
	infile >> agentPosX_ >> agentPosY_;
    agentOriented_=0; //Siempre mira hacia el norte
    tiempo_salido_=0;

	for (int row=0; row<MAZE_SIZE; row+=1)
	{
		for (int col=0; col<MAZE_SIZE; col+=1)
		{
			char c;
			infile >> c;
			if (c == MAP_ROAD) {
   				maze_[row][col] = 0;
			}
			else if (c == MAP_FEROMONA) {
   				maze_[row][col] = FEROMONA;
			}
			else {
				cout << c << " es un simbolo no reconocido por este programa!"; exit(1);
			}
		}// for - col
	}// for - row
}
// -----------------------------------------------------------
void Environment::Show(int w,int h) const
{
	float length=(float)(w>h?h:w)/(float)(MAZE_SIZE+4);
	for (int row=0; row<MAZE_SIZE; row+=1)
	{
		for (int col=0; col<MAZE_SIZE; col+=1)
		{
			float x=(col-MAZE_SIZE/2)*length*2+length,y=(MAZE_SIZE/2-row)*length*2-length;
			char symbol = ' ';
   			if (row == agentPosX_ && col == agentPosY_){
				float size=0.8*length;
				symbol = '=';
				switch (agentOriented_){
					case 0: // Orientacion Norte
					glBegin(GL_POLYGON);
					if(isFeromona())
						glColor3f(1.0,0.0,0.0);
					else
						glColor3f(0.2,0.8,0.0);
					glVertex2f(x,y+size);
					glVertex2f(x+size,y-size);
					glVertex2f(x-size,y-size);
					glEnd();									 
					break;
					case 1: // Orientacion Este
					glBegin(GL_POLYGON);
					if(isFeromona())
						glColor3f(1.0,0.0,0.0);
					else
						glColor3f(0.2,0.9,0.0);
					glVertex2f(x+size,y);
					glVertex2f(x-size,y-size);
					glVertex2f(x-size,y+size);
					glEnd();
					break;
					case 2: // Orientacion Sur
					glBegin(GL_POLYGON);
					if(isFeromona())
						glColor3f(1.0,0.0,0.0);
					else
						glColor3f(0.2,0.8,0.0);
					glVertex2f(x,y-size);
					glVertex2f(x+size,y+size);
					glVertex2f(x-size,y+size);
					glEnd();
					break;
					case 3: // Orientacion Oeste
					glBegin(GL_POLYGON);
					if(isFeromona())
						glColor3f(1.0,0.0,0.0);
					else
						glColor3f(0.2,0.8,0.0);
					glVertex2f(x-size,y);
					glVertex2f(x+size,y-size);
					glVertex2f(x+size,y+size);
					glEnd();
					break;
				}
			}
			glBegin(GL_POLYGON);
				if (maze_[row][col] == FEROMONA) 
					glColor3f(0.95,0.95,0.95);
				else
					glColor3f(1.0,1.0,1.0);
				glVertex2f(x-length,y-length);
				glVertex2f(x+length,y-length);
				glVertex2f(x+length,y+length);
				glVertex2f(x-length,y+length);
			glEnd();
		}// for - col
	}// for - row
}
// -----------------------------------------------------------
bool Environment::isFeromona() const {
	bool out = false;
	
    switch(agentOriented_){
        case 0: // Orientacion Norte
				if (maze_[agentPosX_-1][agentPosY_] == FEROMONA)
					out = true;
	            break;
	    case 1: // Orientacion Este
				if (maze_[agentPosX_][agentPosY_+1] == FEROMONA)
					out = true;
	            break;
        case 2: // Orientacion Sur
				if (maze_[agentPosX_+1][agentPosY_] == FEROMONA)
					out = true;
                break;
        case 3: // Orientacion Oeste
				if (maze_[agentPosX_][agentPosY_-1] == FEROMONA)
					out = true;
                break;
    }
	return out;
}
// -----------------------------------------------------------
void Environment::AcceptAction(Agent::ActionType action)
{
	switch (action)
	{
		case Agent::actFORWARD:
		    switch(agentOriented_){
                case 0: // Orientacion Norte
			            agentPosX_-=1;
			            break;
			    case 1: // Orientacion Este
			            agentPosY_+=1;
			            break;
                case 2: // Orientacion Sur
			            agentPosX_+=1;
                        break;
                case 3: // Orientacion Oeste
			            agentPosY_-=1;
                        break;

		    }
		    break;
		case Agent::actTURN_L:
		    agentOriented_ = (agentOriented_+3)%4;
			break;
		case Agent::actTURN_R:
		    agentOriented_ = (agentOriented_+1)%4;
			break;
        
	};	
	
    if (agentPosX_>=0 and agentPosX_<=9 and agentPosY_>=0 and agentPosY_<=9){
        tiempo_salido_=0;
    }
    else
        tiempo_salido_++;
}
// -----------------------------------------------------------
