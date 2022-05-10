#include <iostream>
#include <vector>
#pragma once

using namespace std;

namespace coup{

    class Player;

    class Game{    
        private:
            vector<Player*> players_names;
            size_t turn_counter;
            bool start_game; //True if the one of the players started to play

        public: 
            Game();
            string turn();
            void update_turn_counter();
            vector<string> players();
            string winner();
            Player* get_player(string const& name);
            int get_index_player(Player* player);
            void add_player(Player* player);
            bool get_start_game() const;
            void set_start_game();
            size_t count_player();
            int get_active_players();
    };
}