#include "Case.hpp"
#include "Game.hpp"
#include <iostream>

Case::Case(Game* game) {
    right = true;
    left = true;
    used = false;
    this->game = game;
}

Case::~Case() {
    std::cout << "case deleted" << std::endl; 
}

