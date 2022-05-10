#include <iostream>
#include "Player.hpp"
#include "Game.hpp"
#include <map>
using namespace std;

int const MAX_COINS = 10;
int const MAX_IN_GAME = 6;
int const COINS_TO_NORMAL_COUP = 7;

namespace coup{
    Player::Player(Game& game, string const& name, string role) :  game(game), name(name){
        if(game.count_player() >= MAX_IN_GAME){
            throw invalid_argument("There are not enouph players or too much players");
        }
        if(game.get_start_game()){
            throw invalid_argument("Cannot join to the game, it is already started");
        }
        this->game.add_player(this);
        this->active = true;
        this->name = name;
        this->player_coins = 0;
        this->player_role =move(role);
   } 

    void Player::income(){
        if(this->game.turn() != this->name){
            throw invalid_argument("This is not your turn to play");
        }
        if(this->game.players().size()== 1){
            throw invalid_argument("There are not enough participants");
        }
        if(this->coins() >= MAX_COINS){
            throw invalid_argument("You have reached the maximum amount, need to do coup");
        }
        if(!this->game.get_start_game()){
            this->game.set_start_game();
        }
        this->player_coins++;
        this->last_action.clear();
        this->last_action.push_back("income");
        this->last_action.push_back("null"); 
        this->game.update_turn_counter();
    }

    void Player::foreign_aid(){
        if(this->game.turn() != this->name){
            throw invalid_argument("This is not your turn to play");
        }
        if(this->game.players().size() == 1){
            throw invalid_argument("There are not enough participants");
        }
        if (this->coins() >= MAX_COINS){
            throw invalid_argument("You have reached the maximum amount, need to do coup");
        }
        if(!this->game.get_start_game()){
            this->game.set_start_game();
        }
        this->player_coins += 2;
        this->last_action.clear();
        this->last_action.push_back("foreign_aid");
        this->last_action.push_back("null"); 
        this->game.update_turn_counter();
    }

    void Player::coup(Player& player){
        if(this->game.turn() != this->name){
            throw invalid_argument("This is not your turn to play");
        }
        if(!player.get_active()){
            throw invalid_argument("Can not coup this player, he is already couped");
        }
        if(this->coins() < COINS_TO_NORMAL_COUP){
            throw invalid_argument("There is not enough coins");
        }
        this->amount_of_coins(-COINS_TO_NORMAL_COUP);
        player.set_active(false);
        this->last_action.clear();
        this->last_action.push_back("coup");
        this->last_action.push_back(player.get_name());
        this->game.update_turn_counter();
    }

    string Player::role(){
        return this->player_role;
    }

    int Player::coins() const{
        return this->player_coins;
    }

    bool Player::get_active() const{
        return this->active;
    }

    void Player::set_active(bool action){
        this->active = action;
    }

    string Player::get_name(){
        return this->name;
    }

    vector<string> Player::get_last_action(){
        return this->last_action;
    }

    void Player::amount_of_coins(int num){
        this->player_coins += num;
    }
}
