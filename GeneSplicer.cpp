#include "GeneSplicer.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

GeneSplicer& GeneSplicer::discover_cure(Color){
    return *this;
}