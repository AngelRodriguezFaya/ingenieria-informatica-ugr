
package irrgarten;

/**
 *
 * @author angel_rodriguez
 */

// Esta clase representa las armas que utiliza el jugador en los ataques 
// durante los combates.

public class Weapon {
    
    // Atributos de instancia privados.
    
    private float power;        // atributo de instancia privado de tipo float
    private int uses;           // atributo de instancia privado de tipo int
    
    // Metodos de instancia públicos.
        
        // Constructor sin parámetros
    public Weapon() { }
    
        // Constructor con parámetros
    public Weapon(float power, int uses) {
        this.power = power;
        this.uses = uses;
    }
    
    public float attack () {
        if(uses > 0){
            uses--;
            return power; 
        } else {               // if (uses <= 0)
            return 0;
        }  
    } 
    
    @Override
    public String toString(){       
        return "W[" + power + ", " + uses + "]";
    }
    
    public boolean discard(){
        return Dice.discardElement(uses);
    }
    
}
