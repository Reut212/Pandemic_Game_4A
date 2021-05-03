#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <ostream>
#include <map>
#include <set>

using namespace std;

namespace pandemic{
    class Board{

        public:
        // static map<City, set<City>> connect;
        map<City, int> cubes;
        set<City> citiesWithReaserchStations;

        int& operator[](City c); //put disease cubes in a specific city
        bool is_clean(); //check if there is anything on the board
        void remove_cures(); //remove all mediciens from the board
        friend ostream& operator<<(ostream& out, const Board& b); //print board
    };
}