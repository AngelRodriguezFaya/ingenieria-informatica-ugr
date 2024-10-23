/**
 * @file jugador.hpp
 * @author Angel Rodriguez Faya
 * @date 07-04-2024
 * 
 * INTELIGENCIA ARTIFICIAL : PRÁCTICA 1 AGENTES REACTIVOS
 * 2º CURSO DE INGENIERÍA INFORMÁTICA
 * UNIVERSIDAD DE GRANADA
 * 
 * @brief Fichero de cabecera de la clase ComportamientoJugador.
*/

#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;


struct state // Estado
{
  int fil;
  int col;
  Orientacion brujula;
};


class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      current_state.fil = 99;         // Fila actual del agente
      current_state.col = 99;         // Columna actual del agente
      current_state.brujula = norte;  // Orientación hacia la que mira el agente
      last_action = actIDLE;          // Ultima acción realizada
      girar_derecha = false;          // Indica si el agente debe girar a la derecha
      bien_situado = false;           // Indica si el agente está bien situado
      bikini_puesto = false;          // Indica si el agente lleva puesto el bikini
      zapatillas_puestas = false;     // Indica si el agente lleva puestas las zapatillas
      recargando_pilas = false;       // Indica si el agente está recargando las pilas
      necesita_recargar = false;      // Indica si el agente necesita recargar las pilas
      queda_poca_vida = false;        // Indica si al agente le queda poca vida
      accion_pendiente = false;       // Indica si el agente tiene una acción pendiente
      last_rule = 0,                  // Última regla que ejecuto el agente    
      reinicio_bloqueante = false,    // Indica si el agente reaparecio en una casilla bloqueante tras ser reiniciado
      tamanio_mapa = size,            // Tamaño del mapa
      iteraciones_desde_reinicio = 0; // Número de iteraciones desde que el agente fue reiniciado la última vez. 
    }
    
    /**
     * @brief Constructor de copia
    */
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    
    /**
     * @brief Destructor
    */
    ~ComportamientoJugador(){}
    
    /**
     * @brief Ejecuta el proceso de toma de decisiones del jugador.
     * 
     * Esta función se encarga de actualizar las variables de estado, analizar los datos del sensor 
     * y determinar la próxima acción a tomar.
     * Recibe las lecturas del sensor como entrada y devuelve la acción elegida.
     * 
     * @param sensores sensores del agente.
     * @return La acción elegida.
    */
    Action think(Sensores sensores);

    int interact(Action accion, int valor);

    /**
     * @brief Pone el terreno en el mapaResulatdo.
     * 
     * Esta función se encarga de poner el terreno en el mapaResultado.
     * 
     * @param terreno vector con el terreno, viene de sensores.terreno.
     * @param st estado actual del agente.
     * @param matriz matriz donde se va a poner el terreno, que es el mapaResultado.
     * @param sensores sensores del agente.
    */
    void ponerTerrenoEnMatriz(const vector<unsigned char> &terreno, 
			const state &st, vector< vector< unsigned char> > &matriz, Sensores& sensores);
    
    /**
     * @brief Gestiona la recarga de la batería del agente
     * 
     * Esta función se encarga de gestionar la recarga de la batería del agente, mediante
     * el valor de variables de estado y las lecturas del sensor.
     * 
     * @param sensores sensores del agente.
    */
    void recargarPilas(Sensores& sensores);

    /**
     * @brief Nos indica si una casilla está libre.
     * 
     * Esta función nos indica si una casilla está libre, es decir, si no hay obstáculos 
     * y se puede avanzar a ella
     * 
     * @param sensores sensores del agente.
     * @param num_casilla número de la casilla.
     * 
     * @return true si la casilla está libre, false en caso contrario.
    */
    bool casillaLibre(const Sensores &sensores, const int& num_casilla);

    /**
     * @brief Nos devuelve una acción de giro.
     * 
     * Esta función nos devuelve una acción de giro aleatoria, o 
     * 45 grados a la derecha o 90 grados a la izquierda.
     *
     * @param sensores sensores del agente.
     * 
     * @return La acción de giro.
    */
    Action giroRandom(const Sensores &sensores);


    /**
     * @brief Nos devuelve la siguiente acción.
     * 
     * Esta función nos devuelve la siguiente acción a realizar por el agente.
     * 
     * @param sensores sensores del agente.
     * @param i número de la casilla.
     * 
     * @return La acción a realizar.
    */
    Action siguienteAccion(const Sensores &sensores, const int& i);

    /**
     * @brief Nos devuelve si la casilla indicada es un muro.
     * 
     * Esta función nos indica si la casilla indicada es un muro.
     * Un muro aparaece en el vector de terreno con el valor 'M'
     * 
     * @param sensores sensores del agente.
     * @param num_casilla número de la casilla.
     * 
     * @return true si la casilla es un muro, false en caso contrario.
    */
    bool esMuro(const Sensores &sensores, const int& num_casilla);

    /**
     * @brief Nos devuelve si la casilla indicada es un precipicio.
     * 
     * Esta función nos indica si la casilla indicada es un precipicio.
     * Un precipicio aparaece en el vector de terreno con el valor 'P'
     * 
     * @param sensores sensores del agente.
     * @param num_casilla número de la casilla.
     * 
     * @return true si la casilla es un precipicio, false en caso contrario.
    */
    bool esPrecipicio(const Sensores &sensores, const int& num_casilla);

    /**
     * @brief Nos devuelve si la casilla indicada es un obstáculo.
     * 
     * Esta función nos indica si la casilla indicada es un muro o un precipicio.
     * 
     * @param sensores sensores del agente.
     * @param num_casilla número de la casilla.
     * 
     * @return true si la casilla es un obstáculo, false en caso contrario.
    */
    bool casillaNoTransitable(const Sensores& sensores, const int& num_casilla);

    /**
     * @brief Nos devuelve la orientación del agente
     * 
     * Si el agente está bien situado, nos devuelve su orientación.
     * 
     * @param sensores sensores del agente.
     * @param st estado actual del agente.
     * 
     * @return La orientación del agente.     * 
    */
    Orientacion orientacionActual(const Sensores &sensores, const state& st);

    /**
     * @brief Ayuda al agente a salir de unas casillas cuando es reiniciado.
     * 
     * Si el agente aparece en un bosque o en el agua sin zapatillas o bikini
     * respectivamente, va a poder salri de ellas, aunque le cueste más bateria.
     * 
     * @param sensores sensores del agente.
     * 
     * @return La acción a realizar.
    */
    Action salirDelPaso(const Sensores &sensores);

    /**
     * @brief Pinta los bordes del mapa, que son precipicios 'P'.
     * 
     * Esta función pinta los bordes del mapa, que son las 3 primeras filas y las 3 últimas, 
     * y las 3 primeras columnas y las 3 últimas.
     * 
     * @param n tamaño del mapa.
     * @param mapa mapa donde se van a pintar los bordes, que es el mapaResultado.
    */
    void pintaBordes(const int& n, vector< vector< unsigned char> > &mapa);

    /**
     * @brief Nos devuelve si la casilla indicada es una casilla Libre Especial.
     * 
     * Esta función nos indica si la casilla esta libre y podemos acceder a ella,
     * aunque sea un bosque o agua.
     * 
     * @param sensores sensores del agente.
     * @param num_casilla número de la casilla.
     * 
     * @see casillaLibre
     * @see salirDelPaso
     * 
     * @return true si la casilla es una casilla libre especial, false en caso contrario.
     * 
    */
    bool casillaLibreEspecial(const Sensores &sensores, const int& num_casilla);


  private:
    const int BATERIA_MAX_CARGA = 5000;     // INDICA EL NIVEL DE BATERIA MÁXIMO
    const int BATERIA_MIN = 4000;           // INDICA EL NIVEL DE BATERIA MÍNIMO
    const int TAM_SENSORES_TERR_AGEN = 16;  // TAMAÑO DEL VECTOR DE SENSORES DE TERRENO Y AGENTES

  // Declarar aquí las variables de estado
  
    state current_state;        // Estado actual del agente 
  
    Orientacion brujula;        // Orientación del agente(además de la de current_state)
  
    Action last_action;;        // Última acción realizada por el agente
  
    bool girar_derecha,         // Indica si el agente debe girar a la derecha
        bien_situado,          // Indica si el agente está bien situado
        bikini_puesto,         // Indica si el agente lleva puesto el bikini
        zapatillas_puestas,    // Indica si el agente lleva puestas las zapatillas
        recargando_pilas,      // Indica si el agente está recargando las pilas/batería
        necesita_recargar,     // Indica si el agente necesita recargar las pilas/batería
	      queda_poca_vida,       // Indica si al agente le queda poca vida
        accion_pendiente,      // Indica si el agente tiene una acción pendiente
        reinicio_bloqueante;   // Indica si el agente reaparecio en una casilla bloqueante tras ser reiniciado
  
    int last_rule,                  // Última regla que ejecuto el agente 
        tamanio_mapa,               // Tamaño del mapa
        iteraciones_desde_reinicio; // Número de iteraciones desde que el agente fue reiniciado la última vez.

};
#endif
