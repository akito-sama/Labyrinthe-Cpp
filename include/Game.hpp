#pragma once
#include <SFML/Graphics.hpp>

class Labyrinthe;

class Game {

public:
    int const GridSize = 100;
    sf::RenderWindow* screen;
    int screenHeight, screenWidth;
    Labyrinthe* labyrinthe;


    Game(sf::RenderWindow* window);
    ~Game();

    void draw();
    void update();
    void event();
};
