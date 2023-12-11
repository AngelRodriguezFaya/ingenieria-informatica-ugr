package irrgarten;

/**
 *
 * @author angel_rodriguez
 */

// Esta clase permite almacenar una representación del estado completo del juego

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

    public GameState() {};

    
    public GameState(String labyrinthv, String players, String monsters, int currentPlayer, Boolean winner, String log) {
        this.labyrinthv = labyrinthv;
        this.players = players;
        this.monsters = monsters;
        this.currentPlayer = currentPlayer;
        this.winner = winner;
        this.log = log;
    }


    public String getLabyrinthv() {
        return labyrinthv;
    }
    
    public String getPlayers(){
        return players;
    }
    
    public String getMonsters(){
        return monsters;
    }
    
    public int getCurrentPlayer() {
        return currentPlayer;
    }
    
    public Boolean getWinner() {
        return winner;
    }
    
    public String getLog() {
        return log;
    }
 
}
