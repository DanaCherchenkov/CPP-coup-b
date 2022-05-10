#include <iostream>
#include "Assassin.hpp"
#include "Player.hpp"
using namespace std;

int const COINS_TO_NORMAL_COUP = 7;
int const ASSASSIN_COUP = 3;

namespace coup{
    void Assassin::coup(Player& player){
        if(this->game.turn() != this->get_name()){
            throw invalid_argument("This is not your turn to play");
        }
        if(!player.get_active()){
            throw invalid_argument("The player is not part of the participants");
        }
        if(game.get_player(player.get_name()) == NULL){
            throw invalid_argument("The player is not part of the participants");
        }
        if(this->coins() >= COINS_TO_NORMAL_COUP){
            Player::coup(player);
            return;
        }
        if(this->coins() < ASSASSIN_COUP){
            throw invalid_argument("There are not enough coins to carry out the coup");
        }
        if(this->game.get_start_game()){
            player.set_active(false);
            this->amount_of_coins(-3);
            this->last_action.clear();
            this->last_action.push_back("not normal coup");
            this->last_action.push_back(player.get_name());
            this->game.update_turn_counter();
        }else{
            throw invalid_argument("The game is not started yet or is over");
        }
    }
}

