/**
 * Esta clase representa el laberinto.
 * @file Labyrinth.java
 * @author angel_rodriguez
 */

package irrgarten;

import java.util.ArrayList;
import java.util.List;

public class Labyrinth {
    //Atributos de clase privados.
        // Estos atributos son caracteres que representan el estado de cada casilla del laberinto.
    private static final char BLOCK_CHAR = 'X';     // ‘X’= obstáculo
    private static final char EMPTY_CHAR = '-';     // '-'= casilla vacía
    private static final char MONSTER_CHAR = 'M';   // 'M'= monstruo
    private static final char COMBAT_CHAR = 'C';    // 'C'= combate entre jugador y monstruo.
    private static final char EXIT_CHAR = 'E';      // 'E'= casilla de salida.
    private static final int ROW = 0;
    private static final int COL = 1;

    //Atributos de instancia privados.
    private int nRows;              // Número de filas del laberinto.
    private int nCols;              // Número de columnas del laberinto.
    private int exitRow;            // Fila de la casilla de salida.
    private int exitCol;            // Columna de la casilla de salida.
    
    //Atributos de relación privados.
    private static Monster[][] monsterGrid;
    private static Player[][] playerGrid;
    private static char[][] characterGrid;

    //Métodos de instancia públicos.
    
    /**
     * Constructor con parámetros.
     * @param nRows         // Número de filas del laberinto.
     * @param nCols         // Número de columnas del laberinto.
     * @param exitRow       // Número de fila de la casilla de salida.
     * @param exitCol       // Número de columna de la casilla de salida.
     * @param Monster[][]   // 
     * @param char[][]      //
     * @param Player[][]    //
     */
    public Labyrinth(int nRows, int nCols, int exitRow, int exitCol) 
    {
        this.nRows = nRows;
        this.nCols = nCols;
        this.exitRow = exitRow;
        this.exitCol = exitCol;
        monsterGrid = new Monster[nRows][nCols];
        characterGrid = new char[nRows][nCols];
        playerGrid = new Player[nRows][nCols];
    }
    
    /**
     * Constructor sin parámetros.
     */
    public Labyrinth(){
        this(0, 0, 0, 0);
    }
    
    /**
     * Constructor por copia
     * @param l objeto de tipo Labyrinth
     */
    public Labyrinth(Labyrinth l){
        this(l.nRows, l.nCols, l.exitRow, l.exitCol);
    }
    
    /**
     * 
     * @param players ArrayList de Player
     */
    public void spreadPlayers(ArrayList<Player> players){
        throw new UnsupportedOperationException();
    }
    
    /**
     * Devuelve si hay un ganador en la casilla de salida.
     * @return Devuelve true si hay un ganador,
     *                  false si no hay un ganador.
     */
    public boolean haveAWinner(){
        return playerGrid[exitRow][exitCol] != null;
    }

    /**
     * Método toString
     * @return Deveuelve una representación interna del laberinto.
     */
    @Override
    public String toString() {
        return "Labyrinth{" + "nRows=" + nRows + ", nCols=" + nCols 
                + ", exitRow=" + exitRow + ", exitCol=" + exitCol + '}';
    }

    /**
     * Añade un monstruo al laberinto. 
     * Anota su presencia en el tablero de caracteres, guarda la referencia del
     * monstruo en el atributo contendor e indica al mosntruo su posición (setPos)
     * @param row       Número de fila en la que irá el monstruo.
     * @param col       Número de columna en la que irá el monstruo.
     * @param monster   Objeto monstruo.
     * @see Monster.setPos  Método de la clase Monster para guardar la nueva posición del mosntruo.
     */
    public void addMonster(int row, int col, Monster monster){
        if(posOK(row, col) && emptyPos(row, col)){
            characterGrid[row][col] = MONSTER_CHAR;
            monsterGrid[row][col] = monster;
            monster.setPos(row, col);
        }
 
    }
    
    /**
     * 
     * @param direction
     * @param player
     * @return 
     */
    public Monster putPlayer(Directions direction,Player player){
        throw new UnsupportedOperationException();
    }
    
    /**
     * 
     * @param orientation
     * @param startRow
     * @param startCol
     * @param length 
     */
    public void addBlock(Orientation orientation, int startRow, int startCol, 
            int length)
    {
        throw new UnsupportedOperationException();
    }
    
    /**
     * 
     * @param row
     * @param col
     * @return 
     */
    public ArrayList<Directions> validMoves(int row, int col){
        throw new UnsupportedOperationException();
    }
    
    /**
     * Comprueba si la posición suministrada está dentro del laberinto.
     * @param row   Número de fila.
     * @param col   Número de columna.
     * @return Devuelve true si la posición está dentro,
     *                  false si la posición está fuera.
     */
    private boolean posOK(int row, int col){
        boolean rowOK, colOK;
        rowOK = (row >= 0 && row < nRows);  //nRows es el número TOTAL de filas, no puede ser <=, sino <
        colOK = (col >= 0 && col < nCols);  //aquí pasa lo mismo
        
        return rowOK && colOK;
    }
    
    /**
     * Comprueba si la posición suministrada está vacía.
     * @param row   Número de fila.
     * @param col   Número de columna.
     * @return Devuelve true si la posición está vacía,
     *                  false si la posición tiene contenido.
     */
    private boolean emptyPos(int row, int col){
        return characterGrid[row][col] == EMPTY_CHAR;
    }
       
    /**
     * Comprueba si la posición suministrada alberga exclusivamente un monstruo.
     * @param row   Número de fila.
     * @param col   Número de columna.
     * @return Devuelve true si lo hay,
     *                  false si no lo hay.
     */
    private boolean monsterPos(int row, int col){
        boolean charGridOK, monsterGridOK;
        charGridOK      = characterGrid[row][col] == MONSTER_CHAR;
        monsterGridOK   = monsterGrid[row][col]   != null;
        return charGridOK && monsterGridOK;
    }
        
    /**
     * Comprueba si la posición suministrada es la de salida.
     * @param row   Número de fila.
     * @param col   Número de columna.
     * @return Devuelve true si lo es,
     *                  false si no lo es.
     */
    private boolean exitPos(int row, int col){
        boolean rowColOK, charGridOK;
        rowColOK = ((row == exitRow) && (col == exitCol));
        charGridOK = characterGrid[row][col] == EXIT_CHAR;
        return rowColOK && charGridOK;
    }
    
    /**
     * Comprueba si la posición suministrada contiene un combate (carácter 'C').
     * Cuando hay un combate, quiere decir que hay un jugador y un mostruo en la
     * misma casilla.
     * @param row   Número de fila.
     * @param col   Número de columna.
     * @return Devuelve true si lo hay,
     *                  false si no lo hay.
     */
    private boolean combatPos(int row, int col){
        boolean
                charGridOK = characterGrid[row][col] == COMBAT_CHAR,
                playerOK   = playerGrid[row][col]    != null,
                monsterOK  = monsterGrid[row][col]   != null;
        return charGridOK && playerOK && monsterOK;
    }
    
    /**
     * Comprueba si la posición suministrada está dentro del laberinto y si 
     * se corresponde con una de estas tres opciones:
     *      casilla vacía,
     *      casilla donde habita un mosntruo,
     *      casilla de salida.
     * @param row   Número de fila.
     * @param col   Número de columna.
     * @see posOk, emptyPos, monsterPos, exitPos.
     * @return Devuelve true si se cumple,
     *                  false si nos se cumple.
     */
    private boolean canStepOn(int row, int col){
        if(posOK(row, col)){
            return (emptyPos(row, col) || monsterPos(row, col) || exitPos(row, col));
        }
        return false;
    }
    
    /**
     * Este método es llamado cuando un jugador abandona una casilla y se 
     * encarga de dejar la casilla que se abandona en el estado correcto.
     * 
     * Este método solo realiza su función si la posición suministrada está 
     * dentro del laberinto. Si es así, tenemos:
     *      - si en esa posición, había un combate, el estado de esa casilla 
     *          pasa a indicar que simplemente hay un monstruo. 
     *      - en otro caso, el estado de esa casilla pasa a indicar que está vacía. 
     * @see posOk
     * @param row   Número de fila.
     * @param col   Número de columna.
     */
    private void updateOldPos(int row, int col){
        if(posOK(row, col)){
            if(characterGrid[row][col] == COMBAT_CHAR)
                characterGrid[row][col] = MONSTER_CHAR;
            else 
                characterGrid[row][col] = EMPTY_CHAR;
        }
    }
    
    /**
     * Este método calcula la posición del laberinto a la que se llegaría si 
     * desde la posición suministrada se avanza en la dirección pasada como 
     * parámetro. 
     * 
     * No realiza comprobaciones relativas a no generar posiciones fuera del 
     * laberinto.
     * 
     * @param row       Número de fila.
     * @param col       Número de columna.
     * @param direction Instancia del enum Directions
     * @return Devuelve: en la posición 0, el número de fila,
     *                   en la posición 1, el número de columna.
     */
    private int[] dir2Pos(int row, int col, Directions direction){
        
        switch (direction){
            case UP:
                row --;
                break;
            
            case DOWN:
                row++;
                break;
            
            case LEFT:
                col--;
                break;
                
            case RIGHT:
                col++;
                break;              
        }
        
        int newPos[] = {row, col};
        
        return newPos;
    }
    
    
    /**
     * Este método genera una posición aleatoria en el laberinto (fila y columna)
     * asegurandose que esté vacía. Si no hay posiciones vacías se producirá un 
     * bucle infinito.
     * @see Dice.randomPos(max), 
     *      emptyPos.
     * @return una posición aleatoria en el tablero y que está vacía. 
     *         en la posición 0, se guarda el número de fila,
     *         en la posición 1, se guarda el número de columna.
     */
    private int[] randomEmptyPos(){
        int rowRandom = 0, 
            colRandom = 0;
        boolean posValida = false;
        
        while (!posValida){
            rowRandom = Dice.randomPos(nRows);
            colRandom = Dice.randomPos(nCols);
            if(emptyPos(rowRandom, colRandom))
                posValida = true;       
        }
        int[] randomPos = {rowRandom, colRandom};
        return randomPos;
    }
    
    private Monster putPlayer2D(int oldRow, int oldCol, int row, int col, 
            Player player)
    {
        throw new UnsupportedOperationException();
    }
}
