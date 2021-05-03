#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class GeneSplicer: public Player{
    public:
        GeneSplicer(Board board, City city):Player(board, city){} 
        GeneSplicer& discover_cure(Color);
        const std::string role() const{
            return "GeneSplicer";
        }
    };
}