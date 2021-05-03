#pragma once
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Color.hpp"

namespace pandemic{
    class Dispatcher : public Player{

        public:
        Dispatcher(Board b, City c) : Player(b, c){};
    };
}