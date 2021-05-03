#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"

namespace pandemic{
    class Medic : public Player{
        
        public:
        Medic(Board b, City c) : Player(b,c){};
    };
}