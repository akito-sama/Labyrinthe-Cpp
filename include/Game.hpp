#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Labyrinthe;

class Game {

public:
    int const GridSize = 120;
    sf::RenderWindow* screen = nullptr;
    int LabyrintheHeight, LabyrintheWidth;
    std::unique_ptr<Labyrinthe> labyrinthe;
    int offset;


    Game(sf::RenderWindow& window);
    ~Game();

    void draw();
    void update();
    void event();
};
