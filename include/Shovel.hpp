#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

class Labyrinthe;

class Shovel {

public:
    sf::Vector2i coordinate;
    Labyrinthe* labyrinthe;
    std::stack<sf::Vector2i>* mouvements;
    sf::CircleShape shape;
    void move();
    void draw(sf::RenderWindow* window);
    Shovel(Labyrinthe* labyrinthe);
    ~Shovel();
};