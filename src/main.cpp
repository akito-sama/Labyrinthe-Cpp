#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main() {
    unsigned int seed = time(0);
    srand(seed);
    auto screen = sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Labyrinthe");
    Game game = Game(screen);

    float sleep_time = 1.0f/5; 

    while(screen.isOpen())
    {
        game.event();
        game.draw();
        game.update();
        sf::sleep(sf::seconds(sleep_time));
    }

    std::cout << "the seed was : " << seed << std::endl;
}
