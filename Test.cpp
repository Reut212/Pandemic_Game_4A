#include "doctest.h"
#include "Board.hpp"

#include "OperationsExpert.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

TEST_CASE("Check is_clean()"){
    Board board;
    CHECK(board.is_clean() == true);
    board[City::Algiers] = 3; //put 3 black disease cubes in Kinshasa.
    board[City::Atlanta] = 1; // put 1 blue disease cube in Atlanta.
    board[City::Chicago] = 4; // put 1 blue disease cube in Chicago

    CHECK(board.is_clean() == false);

    /* cleaning the board*/
    board[City::Algiers] = 0; 
    board[City::Atlanta] = 0;
    board[City::Chicago] = 0;

    CHECK(board.is_clean() == true);
}

TEST_CASE("Check operator[]"){
    Board board;
    CHECK(board.is_clean() == true);
    board[City::Algiers] = 3; //put 3 black disease cubes in Algiers.
    board[City::Atlanta] = 1; // put 1 blue disease cube in Atlanta.
    board[City::Chicago] = 4; // put 1 blue disease cube in Chicago
    CHECK(board[City::Algiers] == 3); 
    CHECK(board[City::Atlanta] == 1);
    CHECK(board[City::Chicago] == 4);
    OperationsExpert operationsExpertplayer {board, City::Algiers};
    operationsExpertplayer.drive(City::Cairo);
    CHECK(board[City::Cairo] == 0);
    board[City::Cairo] = 1;
    CHECK(board[City::Cairo] == 1);
}

TEST_CASE("Check if the player moved to another city on the globe"){
    Board board;
    board[City::Algiers] = 3; //put 3 black disease cubes in Kinshasa.
    board[City::Atlanta] = 1; // put 1 blue disease cube in Atlanta.
    board[City::Chicago] = 4; // put 1 blue disease cube in Chicago
    OperationsExpert operationsExpertplayer {board, City::Algiers};
    operationsExpertplayer.take_card(City::Atlanta);
    CHECK(operationsExpertplayer.city == operationsExpertplayer.fly_direct(City::Atlanta).city); //check if the operation expert in Atlanta.
    operationsExpertplayer.build();
    operationsExpertplayer.take_card(City::Johannesburg);
    operationsExpertplayer.fly_charter(City::Atlanta); // take a flight to Atlanta
    operationsExpertplayer.build(); //Build a reaserch station in Atlanta
    operationsExpertplayer.fly_direct(City::Johannesburg); //take a flight to Johannesburg
    operationsExpertplayer.build(); //Build a reaserch station in Johannesburg
    operationsExpertplayer.fly_shuttle(City::Atlanta); //take a flight to Atlanta
    CHECK(operationsExpertplayer.city == City::Atlanta);//check if the operation expert moved to Atlanta (other city with control lab).
    Researcher reasercherPlayer {board, City:: Algiers};
    reasercherPlayer.treat(City::Algiers);
    CHECK(board[City::Algiers] == 2);
}

TEST_CASE("Check the role() of all players"){
    Board board;
    board[City::Algiers] = 3; //put 3 black disease cubes in Kinshasa.
    board[City::Atlanta] = 1; // put 1 blue disease cube in Atlanta.
    board[City::Chicago] = 4; // put 1 blue disease cube in Chicago
    OperationsExpert operationsExpertplayer {board, City::Algiers};
    CHECK(operationsExpertplayer.role() == "OperationsExpert");
    CHECK_THROWS(operationsExpertplayer.role() = "Medic");
    Dispatcher dispatcherplayer {board, City::Atlanta};
    CHECK(dispatcherplayer.role() == "Dispatcher");
    CHECK_THROWS(dispatcherplayer.role() = "Medic");
    Medic medicPlayer{board, City::Cairo};
    CHECK(medicPlayer.role() == "Medic");
    CHECK_THROWS(medicPlayer.role() = "Scientist");
    FieldDoctor fieldDoctorPlayer{board, City::Chennai};
    CHECK(fieldDoctorPlayer.role() == "FieldDoctor");
    CHECK_THROWS(fieldDoctorPlayer.role() = "Medic");
    GeneSplicer GeneSplicerPlayer { board, City::Delhi};
    CHECK(GeneSplicerPlayer.role() == "GeneSplicer");
    CHECK_THROWS(GeneSplicerPlayer.role() = "Medic");
    Researcher reasercherPlayer1 {board, City::HoChiMinhCity};
    CHECK(reasercherPlayer1.role() == "Researcher");
    CHECK_THROWS(reasercherPlayer1.role() = "Medic");
    Virologist Virologist1 {board, City::Jakarta};
    CHECK(Virologist1.role() == "Virologist");
    CHECK_THROWS(Virologist1.role() = "Medic");
    Scientist scientistPlayer1 {board, City::Kinshasa, 4};
    CHECK(scientistPlayer1.role() == "Scientist");
    CHECK_THROWS(scientistPlayer1.role() = "Medic");
    Scientist scientistPlayer2 {board, City::Kinshasa, 2};
    CHECK(scientistPlayer2.role() == scientistPlayer1.role());
    CHECK_THROWS(scientistPlayer2.role() = "Medic");
    Virologist Virologist2 {board, City::Jakarta};
    CHECK(Virologist2.role() == Virologist1.role());
    CHECK_THROWS(Virologist2.role() = "Medic");
    Researcher reasercherPlayer2 {board, City::HoChiMinhCity};
    CHECK(reasercherPlayer1.role() == reasercherPlayer2.role());
    CHECK_THROWS(reasercherPlayer1.role() = "Medic");
}