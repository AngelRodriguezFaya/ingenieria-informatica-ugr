#encoding:utf-8
require_relative 'weapon'
require_relative 'shield'
require_relative 'dice'
require_relative 'game_state'


class TestP1
  def self.main     #Programa principal
    weapon_1 = Irrgarten::Weapon.new(5.0, 3)
    shield_1 = Irrgarten::Shield.new(3.0, 4)
    game_state_1 = Irrgarten::GameState.new("open", "good", "bored", 2, true, "GOOO")

    puts "Compruebo la clase Weapon"
    puts weapon_1.attack
    puts weapon_1.to_s
    puts weapon_1.discard

    puts "\nCompruebo la clase Shield"
    puts shield_1.protect
    puts shield_1.to_s
    puts weapon_1.discard

    puts "\nCompruebo la clase Dice"
    puts "random_pos: #{Irrgarten::Dice.random_pos(2)}"
    puts "who_starts: #{Irrgarten::Dice.who_starts(5)}"
    puts "random_intelligence: #{Irrgarten::Dice.random_intelligence}"
    puts "random_strength: #{Irrgarten::Dice.random_strength}"
    puts "resurrect_players: #{Irrgarten::Dice.resurrect_player}"
    puts "weapons_reward: #{Irrgarten::Dice.weapons_reward}"
    puts "shields_reward: #{Irrgarten::Dice.shields_reward}"
    puts "health_reward: #{Irrgarten::Dice.health_reward}"
    puts "weapon_power: #{Irrgarten::Dice.weapon_power}"
    puts "shields_power: #{Irrgarten::Dice.shields_power}"
    puts "uses_left: #{Irrgarten::Dice.uses_left}"
    puts "intensity: #{Irrgarten::Dice.intensity(3)}"
    puts "discard_element: #{Irrgarten::Dice.discard_element(5)}"

    puts "\nCompruebo la clase GameState"
    puts game_state_1.labyrinthv
    puts game_state_1.players
    puts game_state_1.monsters
    puts game_state_1.current_player
    puts game_state_1.winner
    puts game_state_1.log
  end
end

TestP1.main