#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic{
    class Scientist : public Player{

        public:
        Scientist(Board b, City c, int a) : Player(b,c){};
    };
}