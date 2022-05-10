#include <iostream>
#include <string>
#include "Player.hpp"
#include "Contessa.hpp"
using namespace std;

namespace coup{
    void Contessa::block(Player& player){
        if(player.role() != "Assassin"){
            throw invalid_argument("Cannot do this action on this player");
        }
        if(!player.get_active()){
            throw invalid_argument("The player is not part of the participants");
        }
        if(game.get_player(player.get_name()) == NULL){
            throw invalid_argument("The player is not part of the participants");
        }
        if(player.get_last_action()[0] == "coup" ){
            throw invalid_argument("This is a normal coup and can not block it");
        }
        if(this->game.get_start_game()){
            if(player.get_last_action()[0] == "not normal coup"){
                Player* dismissed_player = game.get_player(player.get_last_action()[1]);
                dismissed_player->set_active(true);
                this->last_action.clear();
                this->last_action.push_back("block");
                this->last_action.push_back(player.get_name());
            }else{
                throw invalid_argument("No action can be taken on this player - the player not couped any another player");
            }
        }else{
            throw invalid_argument("The game is not started yet or is over");
        }
    }
}