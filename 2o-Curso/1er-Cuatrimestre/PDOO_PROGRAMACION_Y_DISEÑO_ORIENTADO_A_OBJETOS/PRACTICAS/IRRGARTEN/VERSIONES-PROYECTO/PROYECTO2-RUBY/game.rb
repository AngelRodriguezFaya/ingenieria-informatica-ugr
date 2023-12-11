# frozen_string_literal: true
#encoding:utf-8

# File: labyrinth.rb
# Author: Ángel Rodríguez Faya

module Irrgarten
  class Game
    @@MAX_ROUNDS = 10.freeze

    def initialize (nplayers)
      #SE DECIDE DE FORMA ALEATORIA.
      # -   Jugador que empieza la partida ---> currentPlayerIndex
      # -   Número de monstruos.
      # -   Posición de la casilla de salida (exitRow, exitCol)

      generator = Random.new

      @log = ""
      @players = Array.new
      @monsters = Array.new

      # Creo y agrego los jugadores al contenedor.
      for i in 0..(nplayers-1)
        number_player = i.chr
        player = Player.new(number_player, Dice.random_intelligence,
                            Dice.random_strength)
        @players.add(player)
      end

      @current_player_index = generator.rand(nplayers.to_i)
      @current_player = @players[@current_player_index]

      # El número de monstruos y la casilla de salida lo haré de forma aleatoria.
      rows = 8.freeze # Número de FILAS de mi laberinto.
      cols = 8.freeze # Número de COLUMNAS de mi laberinto.
      num_monster = generator.rand(10.to_i) + 1
      exit_row    = Dice.random_pos(rows)
      exit_col    = Dice.random_pos(cols)

      # Añado los monstruos
      for i in 0..(num_monster-1)
        name_monster = "Monstruo '" + i.chr + "'"
        monster = Monster.new(name_monster.to_i, Dice.random_intelligence,
                              Dice.random_strength)
        @monsters.add(monster)
      end

      # Instancio el laberinto.
      @labyrinth = Labyrinth.new(rows,cols,exit_row,exit_col)

    end

    def finished #boolean
      @labyrinth.have_a_winner
    end

    def next_step(preferredDirection) #boolean
    end

    def get_game_state #GameState
      @game_state = GameState.new("", "", "", @current_player_index, finished, "")
      @game_state
    end

    def configure_labyrinth
    end

    def next_player
      @current_player_index += 1
      @current_player = @players.get(@current_player_index)
    end

    def actual_direction(preferredDirection) #Directions
    end

    def combat(monster) #GameCharacter

    end

    def manage_reward(winner)
    end

    def manage_resurrection
    end

    def log_player_won
      @log += "El jugador ha ganado el combate. \n"
    end

    def log_monster_won
      @log += "El monstruo ha ganado el combate.\n"
    end

    def log_resurrected
      @log += "El jugador ha resucitado.\n"
    end

    def log_player_skip_turn
      @log += "El jugador ha perdido el turno por estar muerto.\n"
    end

    def log_player_no_orders
      @log += "El jugador no ha podido seguir las instrucciones del jugador humano (no ha sido posible). \n"
    end

    def log_no_monster
      @log += "El jugador se ha movido a una celda vacía o no le ha sido posible moverse.\n"
    end

    def log_rounds(rounds, max)
      @log += "Se han producido #{rounds} de #{max} rondas de combate.\n"
    end

  end   # end de la clase Game
end  # end del módulo Irrgarten
