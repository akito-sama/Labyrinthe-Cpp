#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Case {

private:
    bool right, left, used;
    Game* game;

    void drawGrid();

public:
    Case();
    Case(Game* game);
    ~Case();
};