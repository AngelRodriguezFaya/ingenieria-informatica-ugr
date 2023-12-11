# frozen_string_literal: true
#encoding:utf-8

# File: monster.rb
# Author: Ángel Rodríguez Faya

module Irrgarten
  class Monster
    attr_writer :row, :col

    # Atributos
    @@INITIAL_HEALTH = 5

    public  # Métodos públicos
    def initialize(name, intelligence, strength)
      @name         = name.to_s
      @intelligence = intelligence.to_f
      @strength     = strength.to_f
      @health       = @@INITIAL_HEALTH
      @row          = 0
      @col          = 0
    end

    def dead
      if @health == 0.0
        return true
      else
        return false
      end
    end

    def attack
      Dice.intensity(@strength)
    end

    def defend(receive_attack)
    end

    def set_pos(row, col)
      @row = row
      @col = col
    end

    def to_string
      "Name: #{@name}, intelligence: #{@intelligence}, strength: #{@strength},
       health: #{@health}, row: #{@row}, col: #{@col}"
    end

    private  # Método privado
    def go_wounded
      @health -= 1
    end

  end   # end de la clase Monster
end  # end del módulo Irrgarten