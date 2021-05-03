#include "Board.hpp"

using namespace std;
using namespace pandemic;

int& Board::operator [] (City c){
            return cubes[c];
}
bool Board::is_clean(){
        return false;
}
void Board::remove_cures(){
        
}
std::ostream& pandemic::operator<<(std::ostream& out, const Board& b){
        return out;
}