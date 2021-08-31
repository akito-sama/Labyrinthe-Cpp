#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Case;
class Game;
class Shovel;

class Labyrinthe {

public:
    bool in_generation;
    std::unique_ptr<Shovel> shovel;
    Game* game = nullptr;
    Case** grid = nullptr;
    int width, height;

    Labyrinthe();
    Labyrinthe(Game& game);

    void neighbor(Case** neighbor, const sf::Vector2i position);
    void draw();
    ~Labyrinthe();
};
