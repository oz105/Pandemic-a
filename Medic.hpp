#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{

    class Medic: public Player{
    public:
        Medic(Board board, City city):Player(board, city){} 
        Medic& treat(City);
        const std::string role() const{
            return "Medic";
        }
    };
}