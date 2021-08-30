#pragma once
#include <SFML/Graphics.hpp>
#include "Labyrinthe.hpp"

class Game {

public:
    int const GridSize = 20;
    sf::RenderWindow* screen;
    int screenHeight, screenWidth;
    Labyrinthe* labyrinthe;


    Game(sf::RenderWindow* window);
    ~Game();

    void draw();
    void update();
    void event();
};
