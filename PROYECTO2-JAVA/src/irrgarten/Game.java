/**
 * @file Game.java
 * @author angel_rodriguez
 */

package irrgarten;

import java.util.ArrayList;
import java.util.Random;

public class Game {
    //Atributo de clase privado.
    private static final int MAX_ROUNDS = 10;
    
    //Atributos de instancias privados.
    private int currentPlayerIndex;     // índice del jugador actual.
    private String log;                 // cadena para almacenar el estado del juego.
    
    //Atributos de relación privados.
    private ArrayList <Player> players;      // contenedor de jugadores
    private Player currentPlayer;       // jugador actual
    private ArrayList <Monster> monsters;    // contenedor de monstruos
    private Labyrinth labyrinth;        // laberinto
    
    //Métodos de instancias públicos.
    
    /**
     * Constructor paramétrico.
     * @param nplayers número de jugadores.
     */
    public Game(int nplayers){
        /* SE DECIDE TODO DE FORMA ALEATORIA.
            -   Jugador que empieza la partida ---> currentPlayerIndex
            -   Número de monstruos.
            -   Posición de la casilla de salida (exitRow, exitCol)
        */
        
        Random generator = new Random();
        
        this.log = "";
        this.players = new ArrayList<Player>();
        this.monsters = new ArrayList<Monster>();
        
        // Creo y agrego los jugadores al contenedor.
        for (int i = 0; i < nplayers; i++){
            char numberPlayer = (char) (i);
            Player player = new Player(numberPlayer, 
                    Dice.randomIntelligence(), Dice.randomStrength());
            this.players.add(player);
        }
        
        this.currentPlayerIndex = generator.nextInt(nplayers);      
        this.currentPlayer = players.get(currentPlayerIndex);
        
        // El número de monstruos y la casilla de salida lo haré de forma aleatoria.
        final int ROWS = 8; 
        final int COLS = 8;
        int 
            numMonster = generator.nextInt(10) + 1, //mínimo 1 monstruo.
            exitRow    = Dice.randomPos(ROWS),
            exitCol    = Dice.randomPos(COLS);
        
        // Añado los monstruos
        for( int i = 0; i < numMonster; i++){
            String nameMonster = "Monstruo '" + (char) i + "'";
            Monster monster = new Monster(nameMonster, 
                    Dice.randomIntelligence(), Dice.randomStrength());
            this.monsters.add(monster);
        }
        
        // Instancio el laberinto
        this.labyrinth = new Labyrinth(ROWS, COLS, exitRow, exitCol);
        
        // Configuro el laberinto.
        configureLabyrinth();
        
        // Reparte los jugadores por el tablero.
        labyrinth.spreadPlayers(this.players);
    }
    
    /**
     * Constructor por defecto.
     */
    public Game(){ this(2);}
    

    
    public Game(int currentPlayerIndex, int nplayers, ArrayList<Player> players){
        this.currentPlayerIndex = 0;
        this.log = "";
        this.players = new ArrayList<Player>();
        
        // Creo y agrego los jugadores al contenedor.
        for (int i = 0; i < nplayers; i++){
            Player player = new Player();
            this.players.add(player);
        }
        
        this.currentPlayer = new Player();
        this.monsters = new ArrayList<Monster>();
        this.labyrinth = new Labyrinth();
    }
    
    public boolean finished(){
        return labyrinth.haveAWinner();        
    }
    
    public boolean nextStep(Directions preferredDirection){
        throw new UnsupportedOperationException();
    }
    
    public GameState getGameState(){
        GameState gameState = new GameState("", "", "", 
                currentPlayerIndex, finished(), "");
        return gameState;
    }

    // No se puede continuar hasta la P3 ya que se necesita el método addBlock() de Labyrinth.
    private void configureLabyrinth(){
//        //Utilizo el método randomEmptyPos() de la clase Labyrinth para calcular
//        //una posición aleatroria en el laberinto y que sea válida.
//        //Para insertar el número de bloques y monstruos lo voy a hacer con random.
//        Random generator = new Random();
//        int numsObstaculos = generator.nextInt(10) + 1;
//        
//        for (int i = 0; i < numsObstaculos; i++){
//            
//        }
//        labyrinth.;
        throw new UnsupportedOperationException();
    }
    
    private void nextPlayer(){
        this.currentPlayerIndex++;
        this.currentPlayer = this.players.get(currentPlayerIndex);
    }
    
    private Directions actualDirection(Directions preferredDirection){
        throw new UnsupportedOperationException();
    }
    
    private GameCharacter combat(Monster monster){
        throw new UnsupportedOperationException();
    }
    
    private void manageReward(GameCharacter winner){
        throw new UnsupportedOperationException();
    }
    
    private void manageResurrection(){
        throw new UnsupportedOperationException();
    }
    
    private void logPlayerWon(){
        this.log += "El jugador ha ganado el combate. \n";
    }
    
    private void logMonsterWon(){
        this.log += "El monstruo ha ganado el combate.\n";
    }
    
    private void logResurrected(){
        this.log += "El jugador ha resucitado.\n";
    }
    
    private void logPlayerSkipTurn(){
        this.log += "El jugador ha perdido el turno por estar muerto.\n";
    }
    
    private void logPlayerNoOrders(){
        this.log += "El jugador no ha podido seguir las instrucciones del jugador humano (no ha sido posible). \n";
    }
    
    private void logNoMonster(){
        this.log += "El jugador se ha movido a una celda vacía o no le ha sido posible moverse.\n";  
    }
    
    private void logRounds(int rounds, int max){
        this.log += "Se han producido " + rounds + " de " + max + " rondas de combate.\n";
    }
    
}
