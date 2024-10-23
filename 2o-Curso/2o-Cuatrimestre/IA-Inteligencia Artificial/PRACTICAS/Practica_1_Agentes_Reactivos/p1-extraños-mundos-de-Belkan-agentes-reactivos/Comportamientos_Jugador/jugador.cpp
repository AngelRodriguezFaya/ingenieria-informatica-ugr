/**
 * @file jugador.cpp
 * @author Angel Rodriguez Faya
 * @date 07-04-2024
 * 
 * INTELIGENCIA ARTIFICIAL : PRÁCTICA 1 AGENTES REACTIVOS
 * 2º CURSO DE INGENIERÍA INFORMÁTICA
 * UNIVERSIDAD DE GRANADA
 * 
 * @brief Fichero de implementación de la clase ComportamientoJugador.
*/

#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
#include <vector>

using namespace std;

void reiniciar();

Action ComportamientoJugador::think(Sensores sensores)
{	

	Action accion = actIDLE;
	int a, i, ir_a_casilla;

	//------------------------------------------------------------------------------//
	//-------------------Actualización de las variables de estado-------------------//
	//------------------------------------------------------------------------------//

	switch (last_action){
	
	// AVANZAR
	case actWALK:		
		switch (current_state.brujula)
		{
		case norte: current_state.fil--; break;			
		case noreste: current_state.fil--; current_state.col++; break;
		case este: current_state.col++; break;
		case sureste: current_state.fil++; current_state.col++; break;
		case sur: current_state.fil++; break;
		case suroeste: current_state.fil++; current_state.col--; break;
		case oeste: current_state.col--; break;
		case noroeste: current_state.fil--; current_state.col--; break;
		}
		break;
	
	// CORRER
	case actRUN:		
		switch (current_state.brujula)
		{
		case norte: current_state.fil -= 2; break;
		case noreste: current_state.fil -= 2; current_state.col +=2; break;
		case este: current_state.col += 2; break;
		case sureste: current_state.fil += 2; current_state.col += 2; break;
		case sur: current_state.fil += 2; break;
		case suroeste: current_state.fil += 2; current_state.col -= 2; break;
		case oeste: current_state.col -= 2; break;
		case noroeste: current_state.fil -=2; current_state.col -= 2; break;
		}
		break;
	
	// GIRAR 45º A LA DERECHA
	case actTURN_SR:	
		a = current_state.brujula;
		a = (a + 1) % 8;
		current_state.brujula = static_cast<Orientacion>(a);
		break;
	
	// GIRAR 90º A LA IZQUIERDA
	case actTURN_L:	   
		a = current_state.brujula;
		a = (a + 8 - 2) % 8;
		current_state.brujula = static_cast<Orientacion>(a);
		break;
	}

	// CASILLA POSICIONAMIENTO
	if(sensores.terreno[0] == 'G'){
		if(sensores.nivel == 0){
			current_state.fil = sensores.posF;
			current_state.col = sensores.posC;
			current_state.brujula = sensores.sentido;
			bien_situado = true;
		} else if(sensores.nivel == 1 or sensores.nivel == 2 or sensores.nivel == 3){
			current_state.fil = sensores.posF;
			current_state.col = sensores.posC;
			current_state.brujula = sensores.sentido;
			bien_situado = true;
		}

	}else{
		if(sensores.nivel == 1 or sensores.nivel == 2 or sensores.nivel == 3){
			sensores.posF = -1;
			sensores.posC = -1;
			sensores.sentido = norte;
		}
	}

	// CASILLA BIKINI
	if(sensores.terreno[0] == 'K' and !bikini_puesto){
		bikini_puesto = true;
	}

	// CASILLA ZAPATILLAS
	if(sensores.terreno[0] == 'D' and !zapatillas_puestas){
		zapatillas_puestas = true;
	}

	// REINICIO (CASILLA DE LOBO O PRECIPICIO)
	if(sensores.agentes[0] == 'l' or sensores.terreno[0] == 'P'){
		cout << "Reiniciando...\n";
	}

	// CASILLA DE RECARGA
	if(sensores.terreno[0] == 'X'){
		recargarPilas(sensores);
	}

	// SI NECESITA RECARGAR BATERIA
	if(sensores.bateria < BATERIA_MIN){
		necesita_recargar = true;
	}else{
		necesita_recargar = false;
	}

	// SI LE QUEDA POCA VIDA
	if(sensores.vida < 100){
		queda_poca_vida = true;
	}else{
		queda_poca_vida = false;
	}

	// SI HA SIDO REINICIADO
	if(sensores.reset){
		current_state.fil = 99;
    	current_state.col = 99;
    	current_state.brujula = norte;
    	girar_derecha = false;
    	bien_situado = false;
    	bikini_puesto = false;
    	zapatillas_puestas = false;
		recargando_pilas = false;
	}

	// POOR SI EMPIEZA EN UNA SITUACIÓN DE BLOQUEO
	if(sensores.vida > 2990 and casillaLibreEspecial(sensores, 2)){
		accion = actWALK;
	}else if (sensores.vida > 2990 and !casillaLibreEspecial(sensores, 2)){
		accion = giroRandom(sensores);
	}

	// SI HA TENIDO UN REINICIO BLOQUEANTE
	if( reinicio_bloqueante and casillaLibreEspecial(sensores, 2) and iteraciones_desde_reinicio < 10){
		accion = actWALK;
		iteraciones_desde_reinicio++;
	} 
	// Si no esta disponible la casilla, giramos
	else if(reinicio_bloqueante and casillaLibreEspecial(sensores, 2) and iteraciones_desde_reinicio < 10){
		accion = giroRandom(sensores);
		iteraciones_desde_reinicio++;
	}

	if(iteraciones_desde_reinicio >= 10){
		reinicio_bloqueante = false;
		iteraciones_desde_reinicio = 0;
	}
	

	// >>>>>>>>>>>>>>>>>>>>>>  PINTAR EL MAPA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		// INICIALIZAR MAPA PINTANDO LOS BORDES
	if(sensores.vida == 2999) // PRIMERA ITERACIÓN
	{
		pintaBordes(tamanio_mapa, mapaResultado);
	}

		// SEGUIR PINTANDO EL MAPA SEGÚN EL NIVEL DEL JUEGO
	if( bien_situado && (sensores.nivel == 1 or sensores.nivel == 2 or sensores.nivel == 3)){ 
		ponerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado, sensores);
	}else if (sensores.nivel == 0){
		current_state.fil = sensores.posF;
		current_state.col = sensores.posC;
		current_state.brujula = sensores.sentido;
		ponerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado, sensores);
	}

	//------------------------------------------------------------------------------//
	//--------------------------Decidir la nueva accion-----------------------------//
	//------------------------------------------------------------------------------//

	if(!recargando_pilas){
		// Recorremos el sensor de terreno
		i = -1;
    	while(i < sensores.terreno.size()){ 

        	// Si el agente necesita posicionarse y encuentra la casilla 'G'
        	if (!bien_situado && sensores.terreno[i] == 'G') {
				cout << "Voy a la casilla G\n";
            	accion = siguienteAccion(sensores, i);
				ir_a_casilla = i;
				break;
        	}
        	// Si el agente necesita recargar y encuentra la casilla 'X'
        	else if (necesita_recargar && sensores.terreno[i] == 'X') {
            	cout << "Voy a la casilla X\n";
            	accion = siguienteAccion(sensores, i);
				recargarPilas(sensores);
				ir_a_casilla = i;
				break;
        	}
        	// Si el agente no tiene el bikini y encuentra la casilla 'K'
        	else if (!bikini_puesto && sensores.terreno[i] == 'K') {
				cout << "Voy a la casilla K\n";
            	accion = siguienteAccion(sensores, i);
				ir_a_casilla = i;
				break;
        	}
        	// Si el agente no tiene las zapatillas y encuentra la casilla 'D'
        	else if (!zapatillas_puestas && sensores.terreno[i] == 'D') {
            	cout << "Voy a la casilla D\n";
            	accion = siguienteAccion(sensores, i);
				ir_a_casilla = i;
				break;
        	}
			i++;
    	}

		// REGLAS PARA SITUACIONES EN LAS QUE ESTA ENCERRADO
		if( (casillaNoTransitable(sensores, 3) and casillaNoTransitable(sensores, 7) and casillaLibre(sensores, 13) 
			and orientacionActual(sensores, current_state) == oeste and orientacionActual(sensores, current_state) == este) )
		{
			cout << "Regla 1: Estoy encerrado por la parte derecha y veo un hueco dos casillas más adelante.\n";
			accion = actWALK;
			last_rule = 11;
		}

		else if( (casillaNoTransitable(sensores, 3) and casillaLibre(sensores, 7) 
			and orientacionActual(sensores, current_state) == oeste) and last_rule == 1)
		{
			cout << "Regla 2: Estoy encerrado por la parte derecha y veo un hueco una casilla más adelante.\n";
			accion = actWALK;
			last_rule = 12;
		}

		else if( (casillaLibre(sensores, 3) and orientacionActual(sensores, current_state) == oeste)
			and orientacionActual(sensores, current_state) == este and last_rule == 2)
		{
			cout << "Regla 3: Estoy encerrado por la parte derecha y tengo un hueco, giro a la derecha.\n";
			accion = actTURN_SR;
			last_rule = 3;
		}
		
		else if(last_rule == 3)
		{
			cout << "Regla 4: Avanzo una posicion y me meto en el hueco de la derecha.\n";
			accion = actWALK;
			last_rule = 4;
		}

		else if(last_rule == 4)
		{
			cout << "Regla 5: Termino de girar a la derecha en el hueco.\n";
			accion = actTURN_SR;
			last_rule = 5;
		}

    	// Si no se ha definido ninguna acción específica, el agente avanza (si puede)
    	if (accion == actIDLE){
			if(casillaLibre(sensores, 2)) {
        		accion = actWALK;  
			}else{
				accion = giroRandom(sensores);
    		}
		}
	}
	
	else if(reinicio_bloqueante){	// Si el agente ha sido reiniciado
		accion = salirDelPaso(sensores);
	}

	else if(sensores.agentes[2] == 'l'){	// Si el agente se encuentra con un lobo
		accion = giroRandom(sensores);
	}
		
	else{
		accion = actIDLE;
	}

	//------------------------------------------------------------------------------//
	//----------------------Mostrar el valor de los sensores------------------------//
	//------------------------------------------------------------------------------//

	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC;
	switch (sensores.sentido)
	{
		case norte:	  cout << " Norte\n";	break;
		case noreste: cout << " Noreste\n";	break;
		case este:    cout << " Este\n";	break;
		case sureste: cout << " Sureste\n";	break;
		case sur:     cout << " Sur\n";	break;
		case suroeste:cout << " Suroeste\n";	break;
		case oeste:   cout << " Oeste\n";	break;
		case noroeste:cout << " Noroeste\n";	break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];

	cout << "  Agentes: ";
	for (int i=0; i<sensores.agentes.size(); i++)
		cout << sensores.agentes[i];

	cout << "\nColision: " << sensores.colision;
	cout << "  Reset: " << sensores.reset;
	cout << "  Vida: " << sensores.vida << endl<< endl; 		

	//------------------------------------------------------------------------------//
	//----------------Mostrar el valor de las variables de estado-------------------//
	//------------------------------------------------------------------------------//

	cout << "\n Bien situado: " << bien_situado;
	cout << " current_state.fil: " << current_state.fil << endl;
	cout << " current_state.col: " << current_state.col << endl;
	cout << " current_state.brujula: " << current_state.brujula << endl;
	cout << " Bikini puesto: " << bikini_puesto << endl;
	cout << " Zapatillas puestas: " << zapatillas_puestas << endl;
	cout << " Recargando pilas: " << recargando_pilas << endl;
	cout << " Necesita recargar: " << necesita_recargar << endl;
	cout << " Queda poca vida: " << queda_poca_vida << endl;
	cout << " Reinicio bloqueante: " << reinicio_bloqueante << endl;

	cout << "\n--------------------------------------------\n\n";
	// Recordar la ultima accion
	last_action = accion;

	return accion;

}

//----------------------------------------------------------------------------------//
//----------------------Implementación de métodos auxiliares------------------------//
//----------------------------------------------------------------------------------//

int ComportamientoJugador::interact(Action accion, int valor){
	return false;
}

void ComportamientoJugador::ponerTerrenoEnMatriz(const vector<unsigned char> &terreno, 
			const state &st, vector< vector< unsigned char> > &matriz, Sensores& sensores){
	
	// Según la orinetación del agente, se coloca el terreno en la matriz.
	switch (st.brujula)
	{
	case norte:
		cout << ">>>>>>>Pinta terreno al norte\n";
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil - 1][st.col - 1] = terreno[1];
		matriz[st.fil - 1][st.col] = terreno[2];
		matriz[st.fil - 1][st.col + 1] = terreno[3];
		matriz[st.fil - 2][st.col - 2] = terreno[4];
		matriz[st.fil - 2][st.col - 1] = terreno[5];
		matriz[st.fil - 2][st.col + 1] = terreno[7];
		matriz[st.fil - 2][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col - 3] = terreno[9];
		matriz[st.fil - 3][st.col - 2] = terreno[10];
		matriz[st.fil - 3][st.col + 2] = terreno[14];
		matriz[st.fil - 3][st.col + 3] = terreno[15];
		if(sensores.nivel != 3){
			matriz[st.fil - 2][st.col] = terreno[6];
			matriz[st.fil - 3][st.col - 1] = terreno[11];
			matriz[st.fil - 3][st.col] = terreno[12];
			matriz[st.fil - 3][st.col + 1] = terreno[13];
		}
		break;
	case noreste:
		cout << "Pinta terreno al noreste\n";
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil - 1][st.col] = terreno[1];
		matriz[st.fil - 1][st.col + 1] = terreno[2];
		matriz[st.fil][st.col + 1] = terreno[3];
		matriz[st.fil - 2][st.col] = terreno[4];
		matriz[st.fil - 2][st.col + 1] = terreno[5];
		matriz[st.fil - 1][st.col + 2] = terreno[7];
		matriz[st.fil][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col] = terreno[9];
		matriz[st.fil - 3][st.col + 1] = terreno[10];
		matriz[st.fil - 1][st.col + 3] = terreno[14];
		matriz[st.fil][st.col + 3] = terreno[15];
		if(sensores.nivel != 3){
			matriz[st.fil - 2][st.col + 2] = terreno[6];
			matriz[st.fil - 3][st.col + 2] = terreno[11];
			matriz[st.fil - 3][st.col + 3] = terreno[12];
			matriz[st.fil - 2][st.col + 3] = terreno[13];
		}
		break;
	case este:
		cout << "Pinta terreno al este\n";
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil - 1][st.col + 1] = terreno[1];
		matriz[st.fil][st.col + 1] = terreno[2];
		matriz[st.fil + 1][st.col + 1] = terreno[3];
		matriz[st.fil - 2][st.col + 2] = terreno[4];
		matriz[st.fil - 1][st.col + 2] = terreno[5];
		matriz[st.fil + 1][st.col + 2] = terreno[7];
		matriz[st.fil + 2][st.col + 2] = terreno[8];
		matriz[st.fil - 3][st.col + 3] = terreno[9];
		matriz[st.fil - 2][st.col + 3] = terreno[10];
		matriz[st.fil + 2][st.col + 3] = terreno[14];
		matriz[st.fil + 3][st.col + 3] = terreno[15];
		if(sensores.nivel != 3){
			matriz[st.fil][st.col + 2] = terreno[6];
			matriz[st.fil - 1][st.col + 3] = terreno[11];
			matriz[st.fil][st.col + 3] = terreno[12];
			matriz[st.fil + 1][st.col + 3] = terreno[13];
		}
		break;
	case sureste:
		cout << "Pinta terreno al sureste\n";
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil][st.col + 1] = terreno[1];
		matriz[st.fil + 1][st.col + 1] = terreno[2];
		matriz[st.fil + 1][st.col] = terreno[3];
		matriz[st.fil][st.col + 2] = terreno[4];
		matriz[st.fil + 1][st.col + 2] = terreno[5];
		matriz[st.fil + 2][st.col + 1] = terreno[7];
		matriz[st.fil + 2][st.col] = terreno[8];
		matriz[st.fil][st.col + 3] = terreno[9];
		matriz[st.fil + 1][st.col + 3] = terreno[10];
		matriz[st.fil + 3][st.col + 1] = terreno[14];
		matriz[st.fil + 3][st.col] = terreno[15];
		if(sensores.nivel != 3){
			matriz[st.fil + 2][st.col + 2] = terreno[6];
			matriz[st.fil + 2][st.col + 3] = terreno[11];
			matriz[st.fil + 3][st.col + 3] = terreno[12];
			matriz[st.fil + 3][st.col + 2] = terreno[13];
		}
		break;
	case sur:
		cout << "Pinta terreno al sur\n";
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil + 1][st.col + 1] = terreno[1];
		matriz[st.fil + 1][st.col] = terreno[2];
		matriz[st.fil + 1][st.col - 1] = terreno[3];
		matriz[st.fil + 2][st.col + 2] = terreno[4];
		matriz[st.fil + 2][st.col + 1] = terreno[5];
		matriz[st.fil + 2][st.col - 1] = terreno[7];
		matriz[st.fil + 2][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col + 3] = terreno[9];
		matriz[st.fil + 3][st.col + 2] = terreno[10];
		matriz[st.fil + 3][st.col - 2] = terreno[14];
		matriz[st.fil + 3][st.col - 3] = terreno[15];
		if(sensores.nivel != 3){
			matriz[st.fil + 2][st.col] = terreno[6];
			matriz[st.fil + 3][st.col + 1] = terreno[11];
			matriz[st.fil + 3][st.col] = terreno[12];
			matriz[st.fil + 3][st.col - 1] = terreno[13];
		}
		break;

	case suroeste:
		cout << "Pinta terreno al suroeste\n";
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil + 1][st.col] = terreno[1];
		matriz[st.fil + 1][st.col - 1] = terreno[2];
		matriz[st.fil][st.col - 1] = terreno[3];
		matriz[st.fil + 2][st.col] = terreno[4];
		matriz[st.fil + 2][st.col - 1] = terreno[5];
		matriz[st.fil + 1][st.col - 2] = terreno[7];
		matriz[st.fil][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col] = terreno[9];
		matriz[st.fil + 3][st.col - 1] = terreno[10];	
		matriz[st.fil + 1][st.col - 3] = terreno[14];
		matriz[st.fil][st.col - 3] = terreno[15];
		if(sensores.nivel != 3){
			matriz[st.fil + 2][st.col - 2] = terreno[6];
			matriz[st.fil + 3][st.col - 2] = terreno[11];
			matriz[st.fil + 3][st.col - 3] = terreno[12];
			matriz[st.fil + 2][st.col - 3] = terreno[13];
		}
		break;
	
	case oeste:
		cout << "Pinta terreno al oeste\n";
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil + 1][st.col - 1] = terreno[1];
		matriz[st.fil][st.col - 1] = terreno[2];
		matriz[st.fil - 1][st.col - 1] = terreno[3];
		matriz[st.fil + 2][st.col - 2] = terreno[4];
		matriz[st.fil + 1][st.col - 2] = terreno[5];
		matriz[st.fil - 1][st.col - 2] = terreno[7];
		matriz[st.fil - 2][st.col - 2] = terreno[8];
		matriz[st.fil + 3][st.col - 3] = terreno[9];
		matriz[st.fil + 2][st.col - 3] = terreno[10];
		matriz[st.fil - 2][st.col - 3] = terreno[14];
		matriz[st.fil - 3][st.col - 3] = terreno[15];
		if(sensores.nivel != 3){
			matriz[st.fil][st.col - 2] = terreno[6];
			matriz[st.fil + 1][st.col - 3] = terreno[11];
			matriz[st.fil][st.col - 3] = terreno[12];
			matriz[st.fil - 1][st.col - 3] = terreno[13];
		}
		break;
	
	case noroeste:
		cout << "Pinta terreno al noroeste\n";
		matriz[st.fil][st.col] = terreno[0];
		matriz[st.fil][st.col - 1] = terreno[1];
		matriz[st.fil - 1][st.col - 1] = terreno[2];
		matriz[st.fil - 1][st.col] = terreno[3];
		matriz[st.fil][st.col - 2] = terreno[4];
		matriz[st.fil - 1][st.col - 2] = terreno[5];
		matriz[st.fil - 2][st.col - 1] = terreno[7];
		matriz[st.fil - 2][st.col] = terreno[8];
		matriz[st.fil][st.col - 3] = terreno[9];
		matriz[st.fil - 1][st.col - 3] = terreno[10];	
		matriz[st.fil - 3][st.col - 1] = terreno[14];
		matriz[st.fil - 3][st.col] = terreno[15];
		if(sensores.nivel != 3){
			matriz[st.fil - 2][st.col - 2] = terreno[6];
			matriz[st.fil - 2][st.col - 3] = terreno[11];
			matriz[st.fil - 3][st.col - 3] = terreno[12];
			matriz[st.fil - 3][st.col - 2] = terreno[13];
		}
		break;
	}

}

void ComportamientoJugador::recargarPilas(Sensores& sensores){
	if(sensores.terreno[0] == 'X' and necesita_recargar and !queda_poca_vida 
		and sensores.bateria < BATERIA_MAX_CARGA){
		recargando_pilas = true;
		cout << "Recargando mi bateria... Dame un descanso\n";
		sensores.bateria += 10;
	}else
		recargando_pilas = false;
}

// La casilla debe de estar en el cono de visión del agente
bool ComportamientoJugador::casillaLibre(const Sensores &sensores, const int& num_casilla){
	bool casilla_libre = false;
	if( (sensores.terreno[num_casilla] == 'T' 							// Suelo Arenoso
		or sensores.terreno[num_casilla] == 'S' 						// Suelo Pedregoso
		or sensores.terreno[num_casilla] == 'G' 						// Posicinamiento
		or (sensores.terreno[num_casilla] == 'B' and zapatillas_puestas)	// Bosque
		or (sensores.terreno[num_casilla] == 'A' and bikini_puesto)	 	// Agua
		or sensores.terreno[num_casilla] == 'K'							// Bikini
		or sensores.terreno[num_casilla] == 'D'							// Zapatillas
		or sensores.terreno[num_casilla] == 'X'							// Recarga
		) and sensores.agentes[num_casilla] == '_'						// No hay agente
		  and sensores.terreno[num_casilla] != 'l'						// No es un lobo
		  and sensores.terreno[num_casilla] != 'a'						// No es un aldeano
		  and sensores.terreno[num_casilla] != 'P'						// No es un precipicio
		  and sensores.terreno[num_casilla] != 'M')						// No es un muro
	{	
		casilla_libre = true;
	}

	return casilla_libre;
}


bool ComportamientoJugador::casillaLibreEspecial(const Sensores &sensores, const int& num_casilla){
	bool casilla_libre = false;
	if( (sensores.terreno[num_casilla] == 'T' 							// Suelo Arenoso
		or sensores.terreno[num_casilla] == 'S' 						// Suelo Pedregoso
		or sensores.terreno[num_casilla] == 'G' 						// Posicinamiento
		or sensores.terreno[num_casilla] == 'B'							// Bosque aunque sin ZAPATILLAS
		or sensores.terreno[num_casilla] == 'A'	 						// Agua aunque sin BIKINI
		or sensores.terreno[num_casilla] == 'K'							// Bikini
		or sensores.terreno[num_casilla] == 'D'							// Zapatillas
		or sensores.terreno[num_casilla] == 'X'							// Recarga
		) and sensores.agentes[num_casilla] == '_'						// No hay agente
		  and sensores.terreno[num_casilla] != 'l'						// No es un lobo
		  and sensores.terreno[num_casilla] != 'a'						// No es un aldeano
		  and sensores.terreno[num_casilla] != 'P'						// No es un precipicio
		  and sensores.terreno[num_casilla] != 'M')						// No es un muro
	{	
		casilla_libre = true;
	}

	return casilla_libre;
}

Action ComportamientoJugador::giroRandom(const Sensores& sensores){
	Action accion;
	if(!girar_derecha){	
		accion = actTURN_L;
		girar_derecha = (rand()%2 == 0);
	}else{
		accion = actTURN_SR;
		girar_derecha = (rand()%2 == 0);
	}

	return accion;
}

Action ComportamientoJugador::siguienteAccion(const Sensores &sensores, const int& i){
    if(casillaLibre(sensores, i)){
		if (i == 2 || i == 6 || i == 12) {
        	return actWALK;  
    	} else if (i == 1 || i == 4 || i == 5 || i == 9 || i == 10 || i == 11) {
        	return actTURN_L;
    	} else if (i == 3 || i == 7 || i == 8 || i == 13 || i == 14 || i == 15) {
        	return actTURN_SR;
    	}
	} else {
        	return actIDLE;
    }
}

bool ComportamientoJugador::esMuro(const Sensores& sensores, const int& num_casilla){
	return sensores.terreno[num_casilla] == 'M';
}

bool ComportamientoJugador::esPrecipicio(const Sensores& sensores, const int& num_casilla){
	return sensores.terreno[num_casilla] == 'P';
}

bool ComportamientoJugador::casillaNoTransitable(const Sensores& sensores, const int& num_casilla){
	return esMuro(sensores, num_casilla) or esPrecipicio(sensores, num_casilla);
}

Orientacion ComportamientoJugador::orientacionActual(const Sensores &sensores, const state& st){
	Orientacion orientacion_actual;
	
	// NIVEL 0
	if(sensores.nivel == 0)
	{
		orientacion_actual = st.brujula;
	}
	
	// NIVEL 1 Y NO SITUADO
	if(sensores.nivel == 1 and !bien_situado)
	{
		cout << "Estoy en el nivel 1 y no estoy bien situado. No puedo obtener la orientación actual.\n";
	}
	
	// NIVEL 2 Y NO SITUADO
	if(sensores.nivel == 2 and !bien_situado)
	{
		cout << "Estoy en el nivel 2 y no estoy bien situado. No puedo obtener la orientación actual.\n";
	}
	
	// NIVEL 3 Y NO SITUADO
	if(sensores.nivel == 3 and !bien_situado)
	{
		cout << "Estoy en el nivel 3 y no estoy bien situado. No puedo obtener la orientación actual.\n";
	}

	// NIVEL 1, 2 y 3 Y SITUADO
	if( (sensores.nivel == 1 or
		 sensores.nivel == 2 or
		 sensores.nivel == 3)
		  and bien_situado)
	{	
		orientacion_actual = st.brujula;
	}

	return orientacion_actual;
}

Action ComportamientoJugador::salirDelPaso(const Sensores& sensores){
	Action siguiente = actIDLE;
	if(reinicio_bloqueante){ // Si acaba de ser reinicado y estoy en una casilla no transitable
		if(casillaLibreEspecial(sensores, 2)){
			siguiente = actWALK;
		}else{
			siguiente = giroRandom(sensores);
		}
	}
	return siguiente;
}

void ComportamientoJugador::pintaBordes(const int& n, vector< vector< unsigned char> > &mapa){
	// Pinta las tres primeras y tres utlimas filas
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < n; ++j) {
            mapa[i][j] = 'P';
            mapa[n-i-1][j] = 'P';
        }
    }

    // Pinta las tres primeras y tres ultimas columnas
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            mapa[i][j] = 'P';
            mapa[i][n-j-1] = 'P';
        }
    }
}