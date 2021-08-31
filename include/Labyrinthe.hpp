#pragma once
#include <SFML/Graphics.hpp>

class Case;
class Game;
class Shovel;

class Labyrinthe {

public:
    bool in_generation;
    Shovel* shovel;
    Game* game;
    Case** grid;
    int width, height;

    Labyrinthe();
    Labyrinthe(Game* game);

    Case** neighbor(sf::Vector2i position);
    void draw();
    ~Labyrinthe();
};
