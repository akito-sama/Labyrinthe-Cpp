#pragma once
#include <SFML/Graphics.hpp>

class Game {

public:
    sf::RenderWindow* screen;

    Game(sf::RenderWindow* window);
    ~Game();

    void draw();
    void update();
    void event();
};