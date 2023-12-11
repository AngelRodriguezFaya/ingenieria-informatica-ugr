
package irrgarten;

import java.util.Random;

/**
 *
 * @author angel_rodriguez
 */

/* 
    Como no podemos crear instancias de esta clase (Dice), no tiene sentido que 
    los métodos sean de instancia por lo que tendremos que poner métodos de 
    clase. En Java, se ponen como static 
*/

/* Esta clase tiene la responsabilidad de tomar todas las decisiones que 
   dependen del azar en el juego. Es como una especie de dado, pero algo más 
   sofisticado, ya que no proporciona simplemente un número del 1 al 6, sino 
   decisiones concretas en base a una serie de probabilidades establecidas.
*/

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
    
    public static int randomPos(int max){
        int randomPos = 0;
        randomPos = generator.nextInt(max);
        return randomPos;
    }
    
    public static int whoStarts(int nplayers){
        int randomStart = 0;
        randomStart = generator.nextInt(nplayers);
        return randomStart;
    }
    
    /* 
    - El método Random.nextInt() devuelve un entero aleatorio.
      Si le damos un parámetro, nextInt(máx), y máx es de tipo int, nos 
      devolverá un entero. ESTO PRODUCE DESDE 0 A MÁX-1.
      Si queremos que nos produzca hasta max (inclusive), tenemos que poner (máx+1)
      Si lo queremos poner en rangos, por ejemplo desde 1 a 10 incluidos, tengo
      que ponerlo como (nextInt(max) + 1)
    
    - El método Random.netxFloat no aceptan parámetros, por lo que nos
      devolverá un numero aleatorio entre 0,0 y 1,0, y eso tenemos que 
      sumarlo a un entero.
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
    
    public static float randomStrength(){
        float randomStrength = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt( (int) MAX_STRENGTH );
            randomStrength = (generator.nextFloat() + randomNum);
        } while (randomStrength > MAX_STRENGTH);
        
        return randomStrength;
    }
    
    public static boolean resurrectPlayers(){
        float numRandom = generator.nextFloat();
        if(numRandom <= RESURRECT_PROB){
            return true;
        }else{
            return false;
        }
    }
    
    public static int weaponsReward(){
        int weaponsReward = 0;
        weaponsReward = generator.nextInt(WEAPONS_REWARD + 1);
        return weaponsReward;
        
    }
    
    public static int shieldsReward(){
        int shieldsReward = 0;
        shieldsReward = generator.nextInt(SHIELDS_REWARD + 1);
        return shieldsReward;
    }
   
    public static int healthReward(){
        int healthReward = 0;
        healthReward = generator.nextInt(HEALTH_REWARD + 1);
        return healthReward;
    }
   
    public static float weaponPower(){
        float weaponPower = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt(MAX_ATTACK);
            weaponPower = (generator.nextFloat() + randomNum);
        } while (weaponPower >= MAX_INTELLIGENCE);
        
        return weaponPower;
    }

    public static float shieldPower(){
        float shieldPower = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt(MAX_SHIELD);
            shieldPower = (generator.nextFloat() + randomNum);
        } while (shieldPower >= MAX_SHIELD);
        
        return shieldPower;
    }
    
    public static int usesLeft(){
        int randomUses = 0;
        randomUses = generator.nextInt(MAX_USES + 1);
        return randomUses;
    }
    
    public static float intensity(float competence){
        float intensity = (float) 0.0;
        int randomNum = 0;
        
        do{
            randomNum = generator.nextInt((int) competence);
            intensity = (generator.nextFloat() + randomNum);
        } while (intensity >= competence);
        
        return intensity;       
    }
    
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
