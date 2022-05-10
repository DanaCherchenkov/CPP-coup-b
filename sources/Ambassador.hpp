#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{

    class Ambassador:public Player{ 
        public:
            /*
            constractor
            */   
            Ambassador(Game& game, string name_player) : Player(game, name_player, "Ambassador"){};

            void transfer(Player& player_from, Player& player_to);
            
            void block(Player& player);
    };
}