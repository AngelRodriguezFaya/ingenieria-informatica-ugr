# frozen_string_literal: true
#encoding:utf-8

# File: dice.rb
# Author: Ángel Rodríguez Faya

module Irrgarten

  # Esta clase tiene la responsabilidad de tomar todas las decisiones que dependen del azar en el juego.
  # Es como una especie de dado, pero algo más sofisticado, ya que no proporciona simplemente un
  # número del 1 al 6, sino decisiones concretas en base a una serie de probabilidades establecidas.

  #Como no podemos crear instancias de esta clase (Dice), no tiene sentido que los métodos sean de instancia
  # por lo que tendremos que poner métodos de clase. En Ruby, se ponen como self._______

  class Dice
    # Atributos de clase privados
    @@MAX_USES = 5              #(número máximo de usos de armas y escudos)
    @@MAX_INTELLIGENCE = 10.0   #(valor máximo para la inteligencia de jugadores y monstruos)
    @@MAX_STRENGTH = 10.0       #(valor máximo para la fuerza de jugadores y monstruos)
    @@RESURRECT_PROB = 0.3      #(probabilidad de que un jugador sea resucitado en cada turno)
    @@WEAPONS_REWARD = 2        #(numero máximo de armas recibidas al ganar un combate)
    @@SHIELDS_REWARD = 3        #(numero máximo de escudos recibidos al ganar un combate)
    @@HEALTH_REWARD = 5         #(numero máximo de unidades de salud recibidas al ganar un combate)
    @@MAX_ATTACK = 3            #(máxima potencia de las armas)
    @@MAX_SHIELD = 2            #(máxima potencia de los escudos)
    @@generator = Random.new

    # Métodos de clase públicos

    # El método rand() de la clase Random devuelve un float aleatorio si no le damos parámetros.
    # Si le damos un parámetro, rand(máx), y máx es de tipo int, nos devolverá un entero. ESTO PRODUCE DESDE 0 A MÁX-1.
    # Si queremos que nos produzca hasta max (inclusive), tenemos que poner rand(máx+1)
    # También lo podemos poner en rangos, por ejemplo: rand(0..10)

    public

    def self.random_pos(max)
      @@generator.rand(max.to_i)
    end

    def self.who_starts(n_players)
      @@generator.rand(n_players.to_i)
    end

    def self.random_intelligence
      @@generator.rand(@@MAX_INTELLIGENCE)
    end

    def self.random_strength
      @@generator.rand(@@MAX_STRENGTH)
    end

    def self.resurrect_player
      random_float = @@generator.rand
      if random_float <= @@RESURRECT_PROB
        return true
      else
        return false
      end
    end

    def self.weapons_reward
      @@generator.rand(@@WEAPONS_REWARD + 1)
    end

    def self.shields_reward
      @@generator.rand(@@SHIELDS_REWARD + 1)
    end

    def self.health_reward
      @@generator.rand(@@HEALTH_REWARD + 1)
    end

    def self.weapon_power
      @@generator.rand(@@MAX_ATTACK)
    end

    def self.shields_power
      @@generator.rand(@@MAX_SHIELD)
    end

    def self.uses_left
      @@generator.rand(@@MAX_USES + 1)
    end

    def self.intensity(competence)
      @@generator.rand(competence.to_f)
    end

    def self.discard_element(uses_left)
      uses_left = uses_left.to_i
      # Caso extremo: si el número de usos es el máximo, devuelve false
      return false if uses_left == @@MAX_USES

      # Caso extremo: si el número de usos es 0, devuelve true
      return true if uses_left == 0

      # Calcula la probabilidad inversamente proporcional
      probabilidad = 1.0/(uses_left.to_f + 1.0)

      # Genera un número aleatorio entre 0 y 1
      random_value = @@generator.rand

      # Compara el número aleatorio con la probabilidad
      return random_value < probabilidad

    end

  end   # end de la clase Dice

end  # end del módulo Irrgarten