#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup{
    Game:: Game(){
        this->turn_counter = 0;
        this->start_game = false;
    }

    string Game::turn(){
        return this->players_names[turn_counter]->get_name();
    }

    void Game::update_turn_counter(){
        this->turn_counter++;
        this->turn_counter = this->turn_counter % this->players_names.size();
        while(!this->players_names[this->turn_counter]->get_active()){
            this->turn_counter++;
            this->turn_counter = this->turn_counter % this->players_names.size();    
        }
    }

    vector<string> Game::players(){
        vector<string> cpy_players;
        for(Player* player_name : this->players_names){
            if(player_name-> get_active()){
                cpy_players.push_back(player_name->get_name());
            }
	    }
        return cpy_players;
    }

    string Game::winner(){
        string winner_player;
        int active_players = 0;
        if(!this->get_start_game()){
            throw std::invalid_argument("There is no winner yet");
        }
        if(this->get_active_players() > 1){
            throw std::invalid_argument("There are more then one player im game");
        }
        for(Player* player : this->players_names){
            if (player->get_active()){
                winner_player = player->get_name();
            }
	    }
        return winner_player;
    }

    Player* Game::get_player(string const& name){
        for(Player* player: this->players_names){
            if(player->get_name() == name){
                return player;
            }
        }
        return NULL;
    }

    int Game::get_index_player(Player* player){
        int index_player = 0;
        for(size_t i = 0; i < players_names.size(); i++){
            if(players_names[i]->get_name() == player->get_name()){
                index_player = i;
            }
        }
        return index_player;
    }
    
    void Game::add_player(Player* player){
        this->players_names.push_back(player);
    }

    bool Game::get_start_game() const{
        return start_game;
    }

    void Game::set_start_game(){
        start_game = true;
    }

    size_t Game::count_player(){
       return this->players_names.size();
    }

    int Game::get_active_players(){
        int count_active = 0;
        for(Player* player : players_names){
            if(player->get_active()){
                count_active++;
            }
        } 
        return count_active;
   }
}