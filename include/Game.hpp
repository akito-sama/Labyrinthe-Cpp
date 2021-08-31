#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Labyrinthe;

class Game {

public:
    int const GridSize = 12;
    sf::RenderWindow* screen;
    int screenHeight, screenWidth;
    std::unique_ptr<Labyrinthe> labyrinthe;


    Game(sf::RenderWindow* window);
    ~Game();

    void draw();
    void update();
    void event();
};
