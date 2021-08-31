#include "Case.hpp"
#include "Game.hpp"
#include <iostream>

Case::Case()
{

}

Case::Case(Game* game, int x, int y) {
    this->x = x;
    this->y = y;
    right = true;
    bottom = true;
    used = false;
    this->game = game;
}

Case::~Case() {
    // std::cout << "case deleted" << " x = " <<  x << ", y = " << y << std::endl; 
}

std::ostream& operator<<(std::ostream& o, Case _case)
{
    o << "Case object at x " << _case.x << " , y " << _case.y << "right : " << _case.right << " bottom " << _case.bottom << " used " << _case.used;
    return o;
}

