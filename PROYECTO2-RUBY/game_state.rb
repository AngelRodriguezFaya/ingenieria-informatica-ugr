# frozen_string_literal: true
#encoding:utf-8

# File: game_state.rb
# Author: Ángel Rodríguez Faya

module Irrgarten

  #Esta clase permite almacenar una representación del estado completo del juego
  class GameState
    def initialize(labyrinthv, players, monsters, current_player, winner, log)
      @labyrinthv = labyrinthv.to_s       # Estado del laberinto.
      @players = players.to_s             # Estado de los jugadores.
      @monsters = monsters.to_s           # Estado de los monstruos.
      @current_player = current_player.to_i   # Índice del jugador que tiene el turno.
      @winner = winner                    # Indicador de si hay un ganador.
      @log = log.to_s                     # Atributo adicional para guardar en una cadena de caracteres eventos interesantes
                                          # que hayan ocurrido desde el turno anterior.
    end

    attr_reader :labyrinthv, :players, :monsters, :current_player, :winner, :log

  end   # end de la clase GameState

end  # end del módulo Irrgarten