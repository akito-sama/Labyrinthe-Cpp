#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Game;

class Case {

public:
    int x, y;
    bool right, bottom, used;

    void drawGrid();

    Case();
    Case(int x, int y);
    ~Case();
};

std::ostream& operator<<(std::ostream& o, Case _case);
