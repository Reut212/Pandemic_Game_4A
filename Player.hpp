#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic{
    class Player{
        public:
        Board board;
        City city;
        string _role;

        Player(Board b, City c):board(b), city(c){}; //build a player object for each role
        Player& take_card(City city); //taking a new card
        Player& drive (City neighbourCity); //drive to a neighbour city
        Player& fly_direct (City cityOnCard); //fly to another city. only if there is a card with the name of the city. don't forget to throw the card
        void fly_charter (City anyCity); //fly to another cith. don't forget to throw the card of the city you left
        void fly_shuttle (City reaserchStationCity); //fly to anothe city with reaserch staion only if in your city is with a reaserch station as well.
        void build (); //build a reaserch station in this city.
        void discover_cure (Color anyColor); //discover a cure to some disease (according to color). Throw 5 cards with the color of the disease.
        Player& treat (City cityImIn); //decrease one cube from this city.
        string role(){ //get the role of the expert.
            return _role;
        };


    };
}