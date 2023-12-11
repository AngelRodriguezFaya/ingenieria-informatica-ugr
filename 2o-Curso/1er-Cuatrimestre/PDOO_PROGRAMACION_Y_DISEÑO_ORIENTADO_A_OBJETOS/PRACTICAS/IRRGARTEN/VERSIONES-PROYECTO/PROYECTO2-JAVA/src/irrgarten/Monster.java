
/**
 * Esta clase representa a un monstruo.
 * @file Monster.java
 * @author angel_rodriguez
 */

package irrgarten;

public class Monster {
    //Atributo de clase privado.
    private static final int INITIAL_HEALTH = 5;
    
    //Atributos de instancia privados.
    private String name;        // Nombre
    private float intelligence; // Inteligencia
    private float strength;     // Fuerza
    private float health;       // Salud
    private int row;            // nº Fila (de su posición)
    private int col;            // nº Columna (de su posición)
    
    
    //Métodos públicos de instancia.
    
    /**
     * Constructor sin parámetros.
     */
    public Monster() {    
        this("", 0f, 0f, (float)INITIAL_HEALTH, 0, 0);
    }

    /**
     * Constructor con TODOS los parámetros.
     * @param name          nombre del monstruo.
     * @param intelligence  inteligencia del monstruo.
     * @param strength      fuerza del monstruo.
     * @param health        salud del monstruo.
     * @param row           fila donde se encuentra el monstruo.
     * @param col           columna donde se encuentra el mosntruo.
     */
    public Monster(String name, float intelligence, float strength,
                   float health, int row, int col) {
        this.name = name;
        this.intelligence = intelligence;
        this.strength = strength;
        this.health = health;
        this.row = row;
        this.col = col;
    }
    
    /**
     * Constructor con parámetros
     * @param name          nombre del monstruo.
     * @param intelligence  inteligencia del monstruo.
     * @param strength      fuerza del monstruo.
     */
    public Monster(String name, float intelligence, float strength){
        this.name = name;
        this.intelligence = intelligence;
        this.strength = strength;
        this.health = INITIAL_HEALTH;
        this.row = 0;
        this.col = 0;
    }
    
    /**
     * Sirve para comprobar si el monstruo está muerto.
     * @return Devuelve true si está muerto, 
     *                  false si no lo está.
     */
    public boolean dead() {
        return health < 1;
    }
    
    /**
     * Genera el resultado delegando en el método intensity del dado
     * pasando como parámetro la fuerza del monstruo.
     * @see Dice.intensity(competence)
     * @return Devuelve la fuerza del ataque del monstruo.
     */
    public float attack() {
        return Dice.intensity(strength);
    }
    
    /**
     * 
     */
    public boolean defend(float receivedAttack){
        throw new UnsupportedOperationException();   
    }
    
    /**
     * Modificador de fila y columna.
     * @param row número de fila.
     * @param col número de columna.
     */
    public void setPos (int row, int col){
        this.row = row;
        this.col = col;
    }
    
    /**
     * toString
     * @return Genera un representación del estado completo del 
     *         monstruo en forma de cadena de caracteres.
     */
    @Override
    public String toString() {
        return "Monster{" + "name=" + name + ", intelligence=" + intelligence 
                + ", strength=" + strength + ", health=" + health + ", row=" 
                + row + ", col=" + col + '}';
    }
    
    
    //Método de instancia privado.
    
    /**
     * Decrementa en una unidad la salud del monstruo.
     */
    private void gotWounded(){
        health--;
    }  
    
}
