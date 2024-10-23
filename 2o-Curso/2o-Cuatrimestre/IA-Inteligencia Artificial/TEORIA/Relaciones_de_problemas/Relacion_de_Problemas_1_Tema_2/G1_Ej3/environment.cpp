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
			else if (c == MAP_OBSTACLE) {
   				maze_[row][col] = OBSTACLE;
				objectPosX_ = row;
				objectPosY_ = col;
			}
			else if (c == MAP_FRONTIER) {
   				maze_[row][col] = FRONTIER;
			}
			else {
				cout << c << " es un simbolo no reconocido por este programa!" <<  endl; exit(1);
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
			
			if (row == agentPosX_ && col == agentPosY_){
				float size=0.8*length;
				switch (agentOriented_){
					case 0: // Orientacion Norte
						glBegin(GL_POLYGON);
						if(isFrontier())
							glColor3f(1.0,0.0,0.0);
						else if(isBump())
							glColor3f(0.0,0.0,1.0);
						else
							glColor3f(0.2,0.8,0.0);
						glVertex2f(x,y+size);
						glVertex2f(x+size,y-size);
						glVertex2f(x-size,y-size);
						glEnd();									 
						break;
					case 1: // Orientacion Este
						glBegin(GL_POLYGON);
						if(isFrontier())
							glColor3f(1.0,0.0,0.0);
						else if(isBump())
							glColor3f(0.0,0.0,1.0);
						else
							glColor3f(0.2,0.8,0.0);
						glVertex2f(x+size,y);
						glVertex2f(x-size,y-size);
						glVertex2f(x-size,y+size);
						glEnd();
						break;
					case 2: // Orientacion Sur
						glBegin(GL_POLYGON);
						if(isFrontier())
							glColor3f(1.0,0.0,0.0);
						else if(isBump())
							glColor3f(0.0,0.0,1.0);
						else
							glColor3f(0.2,0.8,0.0);
						glVertex2f(x,y-size);
						glVertex2f(x+size,y+size);
						glVertex2f(x-size,y+size);
						glEnd();
						break;
					case 3: // Orientacion Oeste
						glBegin(GL_POLYGON);
						if(isFrontier())
							glColor3f(1.0,0.0,0.0);
						else if(isBump())
							glColor3f(0.0,0.0,1.0);
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
			if (maze_[row][col] == FRONTIER)
				glColor3f(0.5,0.25,0.0);
			else if (maze_[row][col] == OBSTACLE)
				glColor3f(0.0,0.0,0.0);
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
		case Agent::actPUSH:
		    switch(agentOriented_){
	            case 0: // Orientacion Norte
			            agentPosX_-=1;
						maze_[objectPosX_][objectPosY_] = 0;
						objectPosX_-=1;
						if (maze_[objectPosX_][objectPosY_] != FRONTIER)
							maze_[objectPosX_][objectPosY_] = OBSTACLE;						
			            break;
			    case 1: // Orientacion Este
			            agentPosY_+=1;
						maze_[objectPosX_][objectPosY_] = 0;
						objectPosY_+=1;
						if (maze_[objectPosX_][objectPosY_] != FRONTIER)						
							maze_[objectPosX_][objectPosY_] = OBSTACLE;						
						break;
	            case 2: // Orientacion Sur
			            agentPosX_+=1;
						maze_[objectPosX_][objectPosY_] = 0;
						objectPosX_+=1;
						if (maze_[objectPosX_][objectPosY_] != FRONTIER)						
							maze_[objectPosX_][objectPosY_] = OBSTACLE;						
	                    break;
	            case 3: // Orientacion Oeste
			            agentPosY_-=1;
						maze_[objectPosX_][objectPosY_] = 0;
	                    objectPosY_-=1;
						if (maze_[objectPosX_][objectPosY_] != FRONTIER)						
							maze_[objectPosX_][objectPosY_] = OBSTACLE;						
						break;
			    }
			    break;
		case Agent::actBACKWARD:
		    switch(agentOriented_){
	            case 0: // Orientacion Norte
						agentPosX_+=1;
				        break;
			    case 1: // Orientacion Este
			            agentPosY_-=1;
			            break;
                case 2: // Orientacion Sur
			            agentPosX_-=1;
                        break;
                case 3: // Orientacion Oeste
			            agentPosY_+=1;
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
	if (agentPosX_>=0 and agentPosX_<=9 and agentPosY_>=0 and agentPosY_<=9)
         tiempo_salido_=0;
     else
         tiempo_salido_++;
}
// -----------------------------------------------------------
bool Environment::isFrontier() const {
	bool out = false;
	
    switch(agentOriented_){
        case 0: // Orientacion Norte
	            out = (maze_[agentPosX_-1][agentPosY_] == FRONTIER);
	            break;
	    case 1: // Orientacion Este
	            out = (maze_[agentPosX_][agentPosY_+1] == FRONTIER);
	            break;
        case 2: // Orientacion Sur
	            out = (maze_[agentPosX_+1][agentPosY_] == FRONTIER);
                break;
        case 3: // Orientacion Oeste
	            out = (maze_[agentPosX_][agentPosY_-1] == FRONTIER);
                break;

    }
	return out;
}
// -----------------------------------------------------------
bool Environment::isBump() const {
	bool out = false;
	
    switch(agentOriented_){
        case 0: // Orientacion Norte
	            out = (maze_[agentPosX_-1][agentPosY_] == OBSTACLE);
	            break;
	    case 1: // Orientacion Este
	            out = (maze_[agentPosX_][agentPosY_+1] == OBSTACLE);
	            break;
        case 2: // Orientacion Sur
	            out = (maze_[agentPosX_+1][agentPosY_] == OBSTACLE);
                break;
        case 3: // Orientacion Oeste
	            out = (maze_[agentPosX_][agentPosY_-1] == OBSTACLE);
                break;

    }
	return out;
}
