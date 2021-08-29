#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(sf::RenderWindow* window) {
    screen = window;
}

Game::~Game() {
    std::cout << "object deleted" << std::endl;
}

void Game::draw() {
    screen->clear(sf::Color::White);
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

}