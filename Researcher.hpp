#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{
    class Researcher : public Player{
        
        public:
        Researcher(Board b, City c) : Player(b,c){};
    };
}