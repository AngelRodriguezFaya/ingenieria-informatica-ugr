# frozen_string_literal: true
#encoding:utf-8
require_relative 'dice'

module Irrgarten

  # Esta clase representa las armas que utiliza el jugador en los ataques durante los combates.
  class Weapon
    def initialize (power, uses)
      @power = power.to_f
      @uses = uses.to_i
    end

    def attack
      if @uses > 0
        @uses -= 1
        return @power
      else
        return 0.0
      end
    end

    def to_s
      "W[#{@power}, #{@uses}]"
    end

    def discard
      Dice.discard_element(@uses)
    end

  end   # end de la clase Weapon

end  # end del módulo Irrgarten


