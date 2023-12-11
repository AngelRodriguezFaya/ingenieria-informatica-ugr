
/**
 * Esta clase representa las armas que utiliza el jugador en los ataques 
 * durante los combates.
 * @file Weapon.java
 * @author angel_rodriguez
 */

package irrgarten;

public class Weapon {
    
    // Atributos de instancia privados.
    
    private float power;        // atributo de instancia privado de tipo float
    private int uses;           // atributo de instancia privado de tipo int
    
    // Métodos de instancia públicos.
        
    /**
     * Constructor sin parámetros.
     */
    public Weapon() {
        this(0f, 0);
    }
    
    /**
     * Constructor con parámetros.
     * @param power potencia de disparo del arma.
     * @param uses  usos restantes del arma.
     */
    public Weapon(float power, int uses) {
        this.power = power;
        this.uses = uses;
    }
    
    /**
     * Devuelve el daño/ataque del arma si uses > 0, si no, devuelve 0.
     * @return float representando la intensidad del ataque del arma.
     */
    public float attack () {
        if(uses > 0){
            uses--;
            return power; 
        } else {               // if (uses <= 0)
            return 0;
        }  
    } 
    
    /**
     * Método toString.
     * @return representación del estado interno del arma.
     */
    @Override
    public String toString(){       
        return "W[" + power + ", " + uses + "]";
    }
    
    /**
     * Implementa la decisión de si el arma debe ser descartada.
     * Delega en el método discardElement de la clase Dice.
     * Hay que pasarle como parámetros la cantidad de usos restantes del arma.
     * @see Dice.discardElement(usesLeft).
     * @return boolean si el arma se descarta o no.
     */
    public boolean discard(){
        return Dice.discardElement(uses);
    }
    
}
