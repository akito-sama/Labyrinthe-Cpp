#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Game;

class Case {

public:
    int x, y;
    bool right, bottom, used;
    Game* game;

    void drawGrid();

    Case();
    Case(Game* game, int x, int y);
    ~Case();
};

std::ostream& operator<<(std::ostream& o, Case _case);
