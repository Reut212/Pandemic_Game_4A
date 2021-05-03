#include "Player.hpp"

namespace pandemic{

    Player& Player::drive (City neighbourCity){
        return *this;
    }
    Player& Player::fly_direct (City cityOnCard){
        return *this;
    }
    void Player::fly_charter (City anyCity){

    }
    void Player::fly_shuttle (City reaserchStationCity){
    }
    void Player::build (){

    }
    void Player::discover_cure (Color anyColor){

    } 
    Player& Player::take_card(City city){
        return *this;
    }

    Player& Player::treat (City cityImIn){
        return *this;
    }

   
}