#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Labyrinthe.hpp"
#include "Shovel.hpp"
#include <memory>


Game::Game(sf::RenderWindow& window, int GridSize) {
    this->GridSize = GridSize;
    offset = GridSize / 2;
    screen = &window;
    LabyrintheWidth = window.getSize().x - GridSize;
    LabyrintheHeight = window.getSize().y - GridSize;
    labyrinthe = std::make_unique<Labyrinthe>(*this);
}

Game::~Game() {
    std::cout << "Game deleted" << std::endl;
}

void Game::draw() {
    screen->clear(sf::Color::White);
    labyrinthe->draw();
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
        labyrinthe->event(event);
    }

}

void Game::update() {
    if (labyrinthe->in_generation)
        labyrinthe->shovel.move();
    screen->display();
}
