#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic{

    class Virologist : public Player{

        public:
        Virologist(Board b, City c):Player(b,c){};
    };

}