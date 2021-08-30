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
    std::cout << "case deleted" << " x = " <<  x << ", y = " << y << std::endl; 
}

