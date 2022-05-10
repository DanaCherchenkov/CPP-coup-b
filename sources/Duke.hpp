#include <iostream>
#include <stdexcept>
#include "Player.hpp"
using namespace std;

namespace coup{

    class Duke:public Player{
        public: 
            /*
            constractor
            */   
            Duke(Game& game, string name_player) : Player(game, name_player, "Duke"){};

            void block(Player& player);
            
            void tax();
    };


}
