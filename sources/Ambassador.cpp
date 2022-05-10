#include <iostream>
#include "Player.hpp"
#include "Ambassador.hpp"
using namespace std;

namespace coup{
    void Ambassador::transfer(Player& player_from, Player& player_to){
        if(this->game.turn() != this->get_name()){
            throw invalid_argument("This is not your turn to play");
        }
        if((!player_from.get_active())|| (!player_to.get_active())){
            throw invalid_argument("The both of the players have to participants in the game");
        }
        if(this->game.get_player(player_from.get_name()) == NULL || this->game.get_player(player_to.get_name()) == NULL){
            throw invalid_argument("The both of the players have to participants in the game");
        }
        if(player_from.coins() == 0){
            throw invalid_argument("The player we want to take from does not have enough coins");
        }
        if(this->game.get_start_game()){
            player_from.amount_of_coins(-1);
            player_to.amount_of_coins(+1);
            this->last_action.clear();
            this->last_action.push_back("transfer");
            this->last_action.push_back(player_from.get_name());
            this->game.update_turn_counter();
        }else{
            throw invalid_argument("The game is not started yet or is over");
        }
    }

    void Ambassador::block(Player& player){
        if(player.role() != "Captain"){
            throw invalid_argument("Cannot do this action on this player");
        }
        if(!player.get_active()){
            throw invalid_argument("The player is not part of the participants");
        }
        if(game.get_player(player.get_name()) == NULL){
            throw invalid_argument("The player is not part of the participants");
        }
        if(this->game.get_start_game()){
            if(player.get_last_action()[0] == "steal" && player.coins() >= 2){
                Player* stolen_from = game.get_player(player.get_last_action()[1]);
                stolen_from->amount_of_coins(+2);
                player.amount_of_coins(-2);
                this->last_action.clear();
                this->last_action.push_back("block");
                this->last_action.push_back(player.get_name());
            }else{
                throw invalid_argument("No action can be taken on this player");
            }
        }else{
            throw invalid_argument("The game is not started yet or is over");
        }
    }
}