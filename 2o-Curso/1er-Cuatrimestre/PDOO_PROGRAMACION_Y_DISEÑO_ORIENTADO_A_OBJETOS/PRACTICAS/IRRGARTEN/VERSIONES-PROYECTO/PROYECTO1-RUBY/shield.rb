# frozen_string_literal: true
#encoding:utf-8
require_relative 'dice'

module Irrgarten

  # Esta clase representa los escudos que utiliza el jugador cuando se defiende de un ataque de un monstruo.
  class Shield
    def initialize (protection, uses)
      @protection = protection.to_f
      @uses = uses.to_i
    end

    def protect
      if @uses > 0
        @uses -= 1
        return @protection
      else
        return 0.0
      end
    end

    def to_s
      "S[#{@protection}, #{@uses}]"
    end

    def discard
      Dice.discard_element(@uses)
    end

  end   # end de la clase Shield

end  # end del módulo Irrgarten