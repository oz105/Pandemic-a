#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Scientist: public Player{
    private:
        int check_four ;
    public:
        Scientist(Board board, City city , int check = 0 ):Player(board, city),check_four(check){} 
        Scientist& discover_cure(Color);
        const std::string role() const{
            return "Scientist";
        }
    };
}