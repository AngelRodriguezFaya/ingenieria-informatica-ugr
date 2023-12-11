
/**
 * Esta clase permite almacenar una representación del estado completo del juego.
 * @file GameState.java
 * @author angel_rodriguez
 */

package irrgarten;

public class GameState {
    
    //Atributos de instancia privados.
    
    private String labyrinthv;  // Estado del laberinto.
    private String players;     // Estado de los jugadores.
    private String monsters;    // Estado de los monstruos.
    private int currentPlayer;  // Índice del jugador que tiene el turno.
    private Boolean winner;     // Indicador de si hay un ganador.
    private String log;         /* Atributo adicional para guardar en una 
                                   cadena de caracteres eventos interesantes 
                                   que hayan ocurrido desde el turno anterior.*/
    
    //Métodos de instancia públicos.
    
    /**
     * Constructor sin parámetros.
     */
    public GameState() {
        this("", "", "", 0, false, "");
    }
    
    /**
     * Constructor con parámetros.
     * @param labyrinthv    Estado del laberinto.
     * @param players       Estado de los jugadores.
     * @param monsters      Estado de los monstruos.
     * @param currentPlayer Índice del jugador que tiene el turno.
     * @param winner        Indicador de si hay un ganador.
     * @param log           Guarda un string con eventos interesantes.
     */
    public GameState(String labyrinthv, String players, String monsters, int currentPlayer, Boolean winner, String log) {
        this.labyrinthv = labyrinthv;
        this.players = players;
        this.monsters = monsters;
        this.currentPlayer = currentPlayer;
        this.winner = winner;
        this.log = log;
    }

    /**
     * Devuelve el estado del laberinto
     * @return String labyrinthv.
     */
    public String getLabyrinthv() {
        return labyrinthv;
    }
    
    /**
     * Devuelve el estado de los jugadores.
     * @return String players.
     */
    public String getPlayers(){
        return players;
    }
    
    /**
     * Devuelve el estado de los monstruos.
     * @return String monsters.
     */
    public String getMonsters(){
        return monsters;
    }
    
    /**
     * Devuelve el índice del jugador que tiene el turno.
     * @return String currentPlayer.
     */
    public int getCurrentPlayer() {
        return currentPlayer;
    }
    
    /**
     * Devuelve hay un ganador en la partida.
     * @return true si un jugador ha ganado,
     *         false si ningún jugador ha ganado.
     */
    public Boolean getWinner() {
        return winner;
    }
    
    /**
     * Devuelve la cadena que guarda eventos interesantes que hayan ocurrido 
     * desde el turno anterior.
     * @return String log.
     */
    public String getLog() {
        return log;
    }
 
}
