#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
namespace pandemic{
    class Player{
    public:
        Player(Board, City);
        Player& drive(City);
        Player& take_card(City);
        Player& fly_charter(City);
        Player& fly_shuttle(City);

        virtual Player& build();
        virtual Player& treat(City);
        virtual Player& fly_direct(City);        
        virtual Player& discover_cure(Color);
        virtual const std::string role() const{
            return "Player";
        }
    };
}