#pragma once
#include <array>
#include <SFML/Graphics.hpp>

class Case;
class Game;

class Labyrinthe {

public:
    Game* game;
    Case** grid;
    int width, height;

    Labyrinthe();
    Labyrinthe(Game* game);

    void draw();

    ~Labyrinthe();
};
