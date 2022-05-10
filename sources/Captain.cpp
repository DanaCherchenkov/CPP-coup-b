#include <iostream>
#include "Captain.hpp"
#include "Player.hpp"
using namespace std;

namespace coup{
    void Captain::block(Player& player){
        if(player.role() != "Captain"){
            throw invalid_argument("Cannot do this action on this player");
        }
        if(!player.get_active()){
            throw invalid_argument("The player is not part of the participants");
        }
        if(this->game.get_player(player.get_name()) == NULL){
            throw invalid_argument("The player is not part of the participants");
        }
        if(this->game.get_start_game()){
            if(player.get_last_action()[0] == "steal"){
                string name_stolen = player.get_last_action()[1];
                Player* stolen_from = this->game.get_player(name_stolen);
                stolen_from->amount_of_coins(+2);
                player.amount_of_coins(-2);
                this->last_action.clear();
                this->last_action.push_back("block");
                this->last_action.push_back(player.get_name());
            }    
        }
        else{
            throw invalid_argument("The game is not started yet or is over");
        }
    }

    void Captain::steal(Player& player){
        if(this->game.turn() != this->get_name()){
            throw invalid_argument("This is not your turn to play");
        }
        if(!player.get_active()){
            throw invalid_argument("The player is not part of the participants");
        }
        if(this->game.get_player(player.get_name()) == NULL){
            throw invalid_argument("The player is not part of the participants");
        }
        if(this->game.get_start_game()){
            if(player.coins() >= 2){
                player.amount_of_coins(-2);
                this->amount_of_coins(+2);
                this->last_action.clear();
                this->last_action.push_back("steal");
                string name = player.get_name();
                this->last_action.push_back(name);  
                this->game.update_turn_counter();
            }
            else if(player.coins() == 1){
                player.amount_of_coins(-1);
                this->amount_of_coins(+1);
                this->last_action.clear();
                this->last_action.push_back("steal");
                string name = player.get_name();
                this->last_action.push_back(name);  
                this->game.update_turn_counter();
            }
            else{
                throw invalid_argument ("This player does not have enough coins");
            }
        }
        else{
            throw invalid_argument("The game is not started yet or is over");
        }
    }
}