
package irrgarten;

/**
 *
 * @author angel_rodriguez
 */


// Esta clase representa los escudos que utiliza el jugador cuando se 
// defiende de un ataque de un monstruo.

public class Shield {
    
    // Atributos de instancia privados.
    
    private float protection;   
    private int uses;           
    
    // Métodos de instancia públicos.
    
        // Constructor sin parámetros
    public Shield () {}
    
        // Constructor con parámetros
    public Shield (float protection, int uses){
        this.protection = protection;
        this.uses = uses;
    }
    
        /* Devuelve un numero float representando la intensidad de defensa del 
           jugador. Siempre que (uses > 0), por el contrario, devuelve 0. */
    public float protect () {
        if(uses > 0){
            uses--;
            return protection; 
        } else {               // if (uses <= 0)
            return 0;
        }  
    }
    
    @Override
    public String toString () {     
        return "S[" + protection + ", " + uses + "]";
 
    }  
    
    public boolean discard(){
        return Dice.discardElement(uses);
    }
    
}
