#include <iostream>
#include <map>
#include "Board.hpp"
#include "City.hpp"
using namespace std;
using namespace pandemic;

static map<City,int> disease_level ;


Board::Board(){
    for(int city = City::Algiers; city<= City::Washington; city++){
        disease_level[(City)city] = 0;
    }
}

int& Board::operator[](const City& city){
    return disease_level[city];
}

bool Board::is_clean(){
    for(auto& city: disease_level){
        if(city.second > 0){
            return false;
        }
    }
    return true;
}

ostream& pandemic::operator<<(ostream& os, const Board& b){
    return os;
}