#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main() {
    auto screen = sf::RenderWindow(sf::VideoMode(600, 600), "Labyrinthe");
    Game game = Game(&screen);

    while(screen.isOpen())
    {
        game.event();
        game.draw();
        game.update();
    }

    std::cout << "Hello World !!" << std::endl;
}
