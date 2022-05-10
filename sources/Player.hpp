#include <iostream>
#include "Game.hpp"
#include <map>
#pragma once
using namespace std;

namespace coup{
    
    class Game;

    class Player{
        protected:
            Game& game;
            string player_role;
            int player_coins;
            string name;
            bool active;
            vector<string>last_action; //last_action[0] = the last action of this player, last_action[1] = The name of on whom the action was taken

        public:
            Player(Game& game, string const& name, string player_role);
            void income();
            void foreign_aid();
            void coup(Player& player);
            string role();
            int coins() const;

            bool get_active() const;
            void set_active(bool action);
            string get_name();
            vector<string> get_last_action();
            void amount_of_coins(int num);
    };
}