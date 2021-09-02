#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Labyrinthe;

class Game {

public:
    int GridSize;
    sf::RenderWindow* screen = nullptr;
    int LabyrintheHeight, LabyrintheWidth;
    std::unique_ptr<Labyrinthe> labyrinthe;
    int offset;


    Game(sf::RenderWindow& window, int GridSize);
    ~Game();

    void draw();
    void update();
    void event();
};
