#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Labyrinthe.hpp"
#include "Shovel.hpp"


Game::Game(sf::RenderWindow* window) {
    screen = window;
    screenWidth = window->getSize().x;
    screenHeight = window->getSize().y;
    labyrinthe = new Labyrinthe(this);
}

Game::~Game() {
    delete labyrinthe;
    std::cout << "Game deleted" << std::endl;
}

void Game::draw() {
    screen->clear(sf::Color::White);
    labyrinthe->draw();
    screen->display();
}

void Game::event() {

    sf::Event event;
    while (screen->pollEvent(event))
    {
        switch (event.type)
        {

        case sf::Event::Closed:
            screen->close();
            break;

        default:
            break;
        }
    }

}

void Game::update() {
    labyrinthe->shovel->move();
}
