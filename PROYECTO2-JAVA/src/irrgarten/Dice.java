
/**
 * Esta clase tiene la responsabilidad de tomar todas las decisiones que 
 * dependen del azar en el juego. Es como una especie de dado, pero algo más 
 * sofisticado, ya que no proporciona simplemente un número del 1 al 6, sino 
 * decisiones concretas en base a una serie de probabilidades establecidas.
 * 
 * Dado que se considera que no tiene sentido que existan distintas instancias 
 * de esta clase, con estados distintos, toda la funcionalidad requerida la 
 * proporciona la propia clase.
 * 
 * @file Dice.java
 * @author angel_rodriguez
 */

package irrgarten;

import java.util.Random;

public class Dice {
    
    // Atributos de clase privados. 
    
        // private static final significan que son CONSTANTES de clase y privadas.
    
    private static final int MAX_USES = 5;              //(número máximo de usos de armas y escudos)
    private static final float MAX_INTELLIGENCE = (float) 10.0;  //(valor máximo para la inteligencia de jugadores y monstruos)
    private static final float MAX_STRENGTH = (float) 10.0;      //(valor máximo para la fuerza de jugadores y monstruos)
    private static final float RESURRECT_PROB = (float) 0.3;    //(probabilidad de que un jugador sea resucitado en cada turno)
    private static final int WEAPONS_REWARD = 2;        //(numero máximo de armas recibidas al ganar un combate)
    private static final int SHIELDS_REWARD = 3;        //(numero máximo de escudos recibidos al ganar un combate)
    private static final int HEALTH_REWARD = 5;         //(numero máximo de unidades de salud recibidas al ganar un combate)
    private static final int MAX_ATTACK = 3;            //(máxima potencia de las armas)
    private static final int MAX_SHIELD = 2;            //(máxima potencia de los escudos)
    private static final Random generator = new Random();
    
    // Métodos de clase públicos.
    
    /**
     * Devuelve un número de fila o columna aleatorio entre [0, max[
     * @param max número de filas o columnas del tablero.
     * @return int número aleatorio de fila o columna dentro del tablero.
     */
    public static int randomPos(int max){
        int randomPos = 0;
        randomPos = generator.nextInt(max);
        return randomPos;
    }
    
    /**
     * Devuelve el índice del jugador que comenzará la partida. Será un número 
     * aleatorio entre [0, nplayers[
     * @param nplayers número de jugadores en la partida.
     * @return int índice del jugador que comienza la partida.
     */
    public static int whoStarts(int nplayers){
        int randomStart = 0;
        randomStart = generator.nextInt(nplayers);
        return randomStart;
    }
    
    /* 
    - El método Random.nextInt() devuelve un entero aleatorio.
      Si le damos un parámetro, nextInt(máx), y máx es de tipo int, nos 
      devolverá un entero. ESTO PRODUCE DESDE 0 A MÁX-1. [0, MÁX[
      Si queremos que nos produzca hasta max (inclusive), tenemos que poner (máx+1)
      Si lo queremos poner en rangos, por ejemplo desde 1 a 10 incluidos, tengo
      que ponerlo como (nextInt(max) + 1) ESTO PRODUCE DESDE 0 A MÁX. [0, MÁX]
    
    - El método Random.netxFloat no aceptan parámetros, por lo que nos
      devolverá un numero aleatorio entre 0,0 y 1,0, y eso tenemos que 
      sumarlo a un entero.
    */
    
    /**
     * Devuelve un valor aleatorio de inteligencia entre [0, MAX_INTELLIGENCE[
     * @return float valor aleatorio de inteligencia.
     */
    public static float randomIntelligence(){
        float randomIntelligence = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt((int) MAX_INTELLIGENCE);
            randomIntelligence = (generator.nextFloat() + randomNum);
        } while (randomIntelligence > MAX_INTELLIGENCE);
        
        return randomIntelligence;
    }
    
    /**
     * Devuelve un valor aleatorio de fuerza entre [0, MAX_STRENGTH[
     * @return float valor aleatorio de fuerza.
     */
    public static float randomStrength(){
        float randomStrength = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt( (int) MAX_STRENGTH );
            randomStrength = (generator.nextFloat() + randomNum);
        } while (randomStrength > MAX_STRENGTH);
        
        return randomStrength;
    }
    
    /**
     * Indica si un jugador muerto debe resucitar o no.
     * @return boolean si el jugador resucita o no.
     */
    
    public static boolean resurrectPlayers(){
        float numRandom = generator.nextFloat();
        return numRandom <= RESURRECT_PROB;
    }
    
    /**
     * Indica la cantidad de armas que recibirá el jugador por ganar el combate.
     * Será un número aleatorio entre [0,WEAPONS_REWARD].
     * @return int cantidad de armas que recibe el jugador.
     */
    public static int weaponsReward(){
        int weaponsReward = 0;
        weaponsReward = generator.nextInt(WEAPONS_REWARD + 1);
        return weaponsReward;
        
    }
    
    /**
     * Indica la cantidad de escudos que recibirá el jugador por ganar el combate.
     * Será un número aleatorio entre [0,SHIELDS_REWARD].
     * @return int cantidad de escudos que recibe el jugador.
     */
    public static int shieldsReward(){
        int shieldsReward = 0;
        shieldsReward = generator.nextInt(SHIELDS_REWARD + 1);
        return shieldsReward;
    }
    
    /**
     * Indica la cantidad de unidades de salud que recibirá el jugador por ganar 
     * el combate.Será un número aleatorio entre [0,HEALTH_REWARD].
     * @return int cantidad de unidades de salud que recibe el jugador.
     */
    public static int healthReward(){
        int healthReward = 0;
        healthReward = generator.nextInt(HEALTH_REWARD + 1);
        return healthReward;
    }
   
    /**
     * Devuelve un valor aleatorio representando la potencia o daño del arma. 
     * Será un valor entre [0, MAX_ATTACK[.
     * @return float potencia/daño del arma.
     */
    public static float weaponPower(){
        float weaponPower = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt(MAX_ATTACK);
            weaponPower = (generator.nextFloat() + randomNum);
        } while (weaponPower >= MAX_INTELLIGENCE);
        
        return weaponPower;
    }
    
    /**
     * Devuelve un valor aleatorio representando la potencia o protección del 
     * escudo. Será un valor entre [0, MAX_SHIELD[.
     * @return float potencia/protección del escudo.
     */
    public static float shieldPower(){
        float shieldPower = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt(MAX_SHIELD);
            shieldPower = (generator.nextFloat() + randomNum);
        } while (shieldPower >= MAX_SHIELD);
        
        return shieldPower;
    }
    
    /**
     * Devuelve el número de usos que se asignará a un arma o escudo. Será un 
     * número aleatorio entre [0, MAX_USES].
     * @return int número de usos que se le asignará a un arma o escudo.
     */
    public static int usesLeft(){
        int randomUses = 0;
        randomUses = generator.nextInt(MAX_USES + 1);
        return randomUses;
    }
    
    /**
     * Devuelve la cantidad de competencia aplicada. Será un valor aleatorio 
     * del intervalo [0, competence[
     * @param competence competencia máxima.
     * @return float competencia aplicada.
     */
    public static float intensity(float competence){
        float intensity = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt((int) competence);
            intensity = (generator.nextFloat() + randomNum);
        } while (intensity >= competence);
        
        return intensity;       
    }
    
    /**
     * Devuelve true con una probabilidad inversamente proporcional a lo cercano 
     * que esté el parámetro del número máximo de usos que puede tener un arma 
     * o escudo.
     * @param usesLeft usos del arma o escudo.
     * @return usesLeft == máximo de usos, devuelve false.
     *         usesLeft == 0, devuelve true
     *         en cualquier otro caso, se valorará dentro del método.
     */
    public static boolean discardElement (int usesLeft){
        // Caso extremo: si el número de usos es el máximo, devuelve false
        if (usesLeft == MAX_USES) {
            return false;
        }
        
        // Caso extremo: si el número de usos es 0, devuelve true
        if (usesLeft == 0) {
            return true;
        }

        // Calcula la probabilidad inversamente proporcional
        double probabilidad = 1.0 / (usesLeft + 1);

        // Genera un número aleatorio entre 0 y 1
        double randomValue = generator.nextDouble();

        // Compara el número aleatorio con la probabilidad
        return randomValue < probabilidad;
    } 

}
