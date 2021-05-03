#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    
    class Board{
    private:
        
    public:
        Board();
        ~Board() = default ;
        int& operator[](const City&);
        void remove_cures() {
            std::cout << std::endl ;
        }
        bool is_clean();
        friend std::ostream& operator<<(std::ostream&, const Board&);
    };
}