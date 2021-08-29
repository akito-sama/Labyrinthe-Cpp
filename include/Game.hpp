#pragma once
#include <SFML/Graphics.hpp>

class Game {
    
private:
    int const GridSize = 20;

public:
    sf::RenderWindow* screen;
    int screenHeight, screenWidth;
    

    Game(sf::RenderWindow* window);
    ~Game();

    void draw();
    void update();
    void event();
};