#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class FieldDoctor: public Player{
    public:
        FieldDoctor(Board board, City city):Player(board, city){} 
        FieldDoctor& treat(City);
        const std::string role() const{
            return "FieldDoctor";
        }
    };
}