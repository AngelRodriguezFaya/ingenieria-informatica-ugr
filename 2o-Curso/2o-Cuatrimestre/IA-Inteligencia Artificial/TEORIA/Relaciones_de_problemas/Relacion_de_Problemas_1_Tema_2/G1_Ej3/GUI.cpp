#include<fstream>
#include<unistd.h>
#include<sstream>
#include<iomanip>
#include<iostream>
using namespace std;
#include"GUI.h"
using namespace GUI;
#include<stdlib.h>
#include"environment.h"
#include"agent_robot.h"

const int SELECTMAP_BTN_ID=103,DISPLAY_BTN_ID=104,NEWMAP_BTN_ID=105;
const int NEWMAP_OK_BTN_ID=202,NEWMAP_CANCEL_BTN_ID=203;
const int SELECTMAP_SELECT_ID=302,SELECTMAP_CANCEL_BTN_ID=303;
const int DO_ONE_STEP_BTN_ID=402,DO_ONE_RUN_BTN_ID=403,NEXT_RUN_BTN_ID=404,DO_ALL_RUN_BTN_ID=405;
const int ERROR_OK_BTN_ID=502;

char life_time_input[1000]="2000",total_runs_input[1000]="10",file_name_input[1000]="map/tablero1.map";
char display_step[20]="100",display_time[20]="10";
char life_time_temp[1000],total_runs_temp[1000],file_name_temp[1000];
int tx,ty,tw,th;
float magnification_x,magnification_y;
long long life_time=2000,current_time,total_runs=10,current_run;

Environment *env=NULL;
Agent *agent=NULL;
Agent::ActionType action=Agent::actIDLE;

GLUI *main_glui,*score_glui,*new_map_glui,*select_map_glui,*error_glui;
GLUI_Button *new_map_btn,*select_map_btn,*new_map_ok_btn,*new_map_cancel_btn;
GLUI_Button *do_one_step_btn,*display_btn,*do_one_run_btn,*next_run_btn,*do_all_run_btn;
GLUI_StaticText *time_run_text,*time_step_text,*action_text,*robot_text;
GLUI_StaticText *complete_runs_text,*total_score_text,*average_score_text;
GLUI_FileBrowser *map_list;

void GUI::myGlutReshape(int w,int h){
	GLUI_Master.get_viewport_area(&tx,&ty,&tw,&th);
	
	glViewport(tx,ty,tw,th);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(tw<=th){
		magnification_x=1;
		magnification_y=(GLfloat)th/(GLfloat)tw;
	}
	else{
		magnification_x=(GLfloat)tw/(GLfloat)th;
		magnification_y=1;
	}
	glOrtho(-10.0*magnification_x,10.0*magnification_x,-10.0*magnification_y,10.0*magnification_y,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}
void GUI::myGlutDisplay(){
	glClearColor(200.0/255,200.0/255,200.0/255,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(-50.0,50.0,-50.0,50.0);
	if(env!=NULL){
		env->Show(tw,th);
		showScore();
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}
void GUI::control_cb(int id){
	switch(id){
		case NEWMAP_BTN_ID:
			new_map_btn->disable();
			select_map_btn->disable();
			strcpy(life_time_temp,life_time_input);
			strcpy(total_runs_temp,total_runs_input);
			strcpy(file_name_temp,file_name_input);
			new_map_glui=GLUI_Master.create_glui("Nuevo Juego",0,100,100);
			new GLUI_EditText(new_map_glui,"Numero de pasos maxima:",life_time_temp);
			new GLUI_EditText(new_map_glui,"Numero de ejec. maxima:",total_runs_temp);
			new GLUI_EditText(new_map_glui,"Fichero de mapa:",file_name_temp);
			new_map_ok_btn=new GLUI_Button(new_map_glui,"OK",NEWMAP_OK_BTN_ID,control_cb);
			new_map_cancel_btn=new GLUI_Button(new_map_glui,"Cancelar",NEWMAP_CANCEL_BTN_ID,control_cb);
			break;
		case SELECTMAP_BTN_ID:
			new_map_btn->disable();
			select_map_btn->disable();
			strcpy(life_time_temp,life_time_input);
			strcpy(total_runs_temp,total_runs_input);
			strcpy(file_name_temp,file_name_input);
			select_map_glui=GLUI_Master.create_glui("Nuevo Juego",0,100,100);
			new GLUI_EditText(select_map_glui,"Numero de pasos maxima:",life_time_temp);
			new GLUI_EditText(select_map_glui,"Numero de ejec. maxima:",total_runs_temp);
			map_list=new GLUI_FileBrowser(select_map_glui,"",false,SELECTMAP_SELECT_ID,control_cb);
			map_list->fbreaddir("map/");
			new_map_cancel_btn=new GLUI_Button(select_map_glui,"Cancelar",SELECTMAP_CANCEL_BTN_ID,control_cb);
			break;
		case DISPLAY_BTN_ID:
			if(true){
				long long sleep = atol(display_time);
				for(long long t=atol(display_step);t>0 && current_time<life_time;--t){
					doOneStep();
					myGlutDisplay();
					usleep(sleep*1000);
				}
			}
			break;
		case NEWMAP_OK_BTN_ID:
			strcpy(life_time_input,life_time_temp);
			strcpy(total_runs_input,total_runs_temp);
			strcpy(file_name_input,file_name_temp);
			life_time=atol(life_time_input);
			total_runs=atol(total_runs_input);
			current_run=1;
			newGame();
			new_map_btn->enable();
			select_map_btn->enable();
			new_map_glui->close();
			break;
		case NEWMAP_CANCEL_BTN_ID:
			new_map_btn->enable();
			select_map_btn->enable();
			new_map_glui->close();
			break;
		case SELECTMAP_SELECT_ID:
			strcpy(life_time_input,life_time_temp);
			strcpy(total_runs_input,total_runs_temp);
			strcpy(file_name_input,map_list->get_file());
			life_time=atol(life_time_input);
			total_runs=atol(total_runs_input);
			current_run=1;
			newGame();
			new_map_btn->enable();
			select_map_btn->enable();
			select_map_glui->close();
			break;
		case SELECTMAP_CANCEL_BTN_ID:
			new_map_btn->enable();
			select_map_btn->enable();
			select_map_glui->close();
			break;
		case DO_ONE_STEP_BTN_ID:
			doOneStep();
			break;
		case DO_ONE_RUN_BTN_ID:
			doOneRun();
			break;
		case NEXT_RUN_BTN_ID:
			nextRun();
			break;
		case DO_ALL_RUN_BTN_ID:
			doAllRun();
			break;
		case ERROR_OK_BTN_ID:
			error_glui->close();
			break;
		default:
			break;
	}
	glutPostRedisplay();
}
int GUI::startDraw(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowPosition(50,50);
	glutInitWindowSize(668,693);
	
	int main_window=glutCreateWindow("Ejercicio 3 - Robot");
	GLUI_Master.set_glutReshapeFunc(myGlutReshape);
	glutDisplayFunc(myGlutDisplay);
		glEnable(GL_DEPTH_TEST);
			
	score_glui=GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_BOTTOM);
		new GLUI_StaticText(score_glui,""); 
		time_run_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,""); 
		time_step_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,""); 
		action_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,""); 
		complete_runs_text = new GLUI_StaticText(score_glui,"");
		new GLUI_StaticText(score_glui,""); 
		
    	new GLUI_StaticText(score_glui,"");//¥HªÅ¥Õ¦æ°µ¤À¹j
    	robot_text = new GLUI_StaticText(score_glui,"");		
		
	score_glui->set_main_gfx_window( main_window );
	main_glui=GLUI_Master.create_glui_subwindow(main_window,GLUI_SUBWINDOW_RIGHT);
		new GLUI_StaticText(main_glui,""); 
		new_map_btn=new GLUI_Button(main_glui,"Nuevo Mapa",NEWMAP_BTN_ID,control_cb);
		select_map_btn=new GLUI_Button(main_glui,"Elegir Mapa",SELECTMAP_BTN_ID,control_cb);
		new GLUI_StaticText(main_glui,""); 
		new GLUI_StaticText(main_glui,""); 
		do_one_step_btn=new GLUI_Button(main_glui,"Paso",DO_ONE_STEP_BTN_ID,control_cb);
		do_one_step_btn->disable();
		do_one_run_btn=new GLUI_Button(main_glui,"Ejecucion",DO_ONE_RUN_BTN_ID,control_cb);
		do_one_run_btn->disable();
		next_run_btn=new GLUI_Button(main_glui,"Sig. ejecucion",NEXT_RUN_BTN_ID,control_cb);
		next_run_btn->disable();
		do_all_run_btn=new GLUI_Button(main_glui,"Todas las ejec.",DO_ALL_RUN_BTN_ID,control_cb);
		do_all_run_btn->disable();
		new GLUI_StaticText(main_glui,""); 
		new GLUI_StaticText(main_glui,""); 
		new GLUI_EditText(main_glui,"Pasos:",display_step);
		new GLUI_EditText(main_glui,"Retardo:",display_time);
		new GLUI_StaticText(main_glui,""); 
		display_btn=new GLUI_Button(main_glui,"Ejecutar",DISPLAY_BTN_ID,control_cb);
		display_btn->disable();
		new GLUI_StaticText(main_glui,""); 
		new GLUI_StaticText(main_glui,""); 

		new GLUI_Button(main_glui,"Salir",0,(GLUI_Update_CB)exit );
	main_glui->set_main_gfx_window( main_window );
	glutMainLoop();
	return 0;
}

void GUI::showScore(){
	ostringstream sout;
	sout.str("");
	sout<<"Ejecucion "<<current_run<<"/"<<total_runs_temp;
	time_run_text->set_text(sout.str().c_str());
	sout.str("");
	sout<<"Paso "<<current_time<<"/"<<life_time_temp;
	time_step_text->set_text(sout.str().c_str());
	
	sout.str("");
	sout<<"Accion "<<ActionStr(action);
	action_text->set_text(sout.str().c_str());

	long long complete_runs=current_run-(current_time!=life_time);
	//The Round has been completed 
	sout.str("");
	sout<<"Ejecuciones completas "<<complete_runs<<"/"<<total_runs_temp;
	complete_runs_text->set_text(sout.str().c_str());	
	
	sout.str("");
	
    switch(env->OutOfBoderTime()){
        case 0: sout << " ";
                break;
        case 1: sout << "        Robot: Oh! Oh!";
                break;
        case 2: sout << "        Robot: Te llamo cuando llegue!!";
                break;
        case 3: sout << "        Robot: No es que no me fie de ti, pero sabes donde me llevas?!?!";
                break;
        case 4: sout << "        Robot: Perdoname que insista, no es evidente que no me has programado bien!!!";
                break;
        case 5: sout << "        Robot: No, y seras capaz de darle otra vez al botoncito!!!!";
                break;
        case 6: sout << "        Robot: Nada, tu a lo tuyo, tu sigue pulsando el botoncito dichoso!!!!";
                break;
        case 7: sout << "        Robot: Espera, espera, veo un cartel... Murcia 3 Kms";
                break;
        case 8: sout << "        Robot: T..e.. est..oy......perd..ie..ndo..";
                break;
        default: sout << "       Robot no disponible o fuera de cobertura";
    }
	robot_text->set_text(sout.str().c_str());
}

void GUI::doOneStep(){
	if(current_time<life_time){		
		agent->Perceive(*env);
		
		action = agent->Think();
		env->AcceptAction(action);
		
		++current_time;
		if(current_time==life_time){
			do_one_step_btn->disable();
			display_btn->disable();
			do_one_run_btn->disable();
						
			if(current_run<total_runs){
				next_run_btn->enable();
			}
			else{
				do_all_run_btn->disable();
			}
		}
	}
}

void GUI::doOneRun(){
	do_one_run_btn->disable();
	
	while(current_time<life_time){
		doOneStep();
	}
	
	if(current_run==total_runs){
		do_all_run_btn->disable();
	}
}
void GUI::doAllRun(){
	doOneRun();
	while(current_run<total_runs){
		nextRun();
		doOneRun();
	}
	do_all_run_btn->disable();
}
void GUI::nextRun(){
	if(current_run<total_runs){
		++current_run;
		do_one_step_btn->enable();
		display_btn->enable();
		do_one_run_btn->enable();
		next_run_btn->disable();
		newGame();
	}
}

void GUI::newGame(){
	ifstream fin;
	
	delete env;
	delete agent;

	fin.open(file_name_input);
	if(fin){
		current_time=0;
		env=new Environment(fin);
		agent=new Agent();
		
		do_one_step_btn->enable();
		display_btn->enable();
		do_one_run_btn->enable();
		do_all_run_btn->enable();
				
		myGlutDisplay();
		glutPostRedisplay();
	}
	else{
		char temp[1000]={"map/"};
		strcat(temp,file_name_input);
		fin.open(temp);
		if(fin){
			current_time=0;
			env=new Environment(fin);
			agent=new Agent();
		
			
			do_one_step_btn->enable();
			display_btn->enable();
			do_one_run_btn->enable();
			do_all_run_btn->enable();
			
			myGlutDisplay();
			glutPostRedisplay();
		}
		else{
			do_one_step_btn->disable();
			display_btn->disable();
			do_one_run_btn->disable();
			do_all_run_btn->disable();
			error_glui=GLUI_Master.create_glui("Error",0,100,100);
				char error_message[1000]="El fichero ";
				strcat(error_message,file_name_input);
				strcat(error_message," no se puede abrir");
				new GLUI_StaticText(error_glui,error_message);
				new_map_ok_btn=new GLUI_Button(error_glui,"OK",ERROR_OK_BTN_ID,control_cb);
		}
	}
}
