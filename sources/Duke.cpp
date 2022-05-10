#include <iostream>
#include "Duke.hpp"
#include "Player.hpp"
using namespace std;

int const MAX_COINS = 10;

namespace coup{
        void Duke::block(Player& player){
                if(!player.get_active()){
                        throw invalid_argument("The player is not part of the participants");
                }
                if(game.get_player(player.get_name()) == NULL){
                        throw invalid_argument("The player is not part of the participants");
                }
                if(this->game.get_start_game()){
                        if(player.get_last_action()[0] == "foreign_aid" && player.coins() >= 2){
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

        void Duke::tax(){
                if(this->game.turn() != this->get_name()){
                        throw invalid_argument("This is not your turn to play");
                }
                if(this->role() != "Duke"){
                        throw invalid_argument("Only the Duke can do this action");
                }
                if(this->coins() >= MAX_COINS){
                        throw invalid_argument("Too many coins, need to do coup befor");
                }
                this->amount_of_coins(+3);
                this->last_action.clear();
                this->last_action.push_back("tax");
                this->last_action.push_back("null");
                this->game.update_turn_counter();
        }
}

