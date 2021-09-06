#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Labyrinthe.hpp"
#include "SkipLabel.hpp"
#include <random>

int main() {
    unsigned int seed = time(0);
    srand(seed);

    auto screen = sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Labyrinthe");
    
    int GridSize = 20;

    SkipLabel text(screen.getSize());
    Game game = Game(screen, GridSize);
    sf::Clock clock;
    float tick;

    float sleep_time = 1.0f/60; 
    while(screen.isOpen())
    {
        tick = clock.restart().asSeconds();
        game.event();
        game.draw();
        if (game.labyrinthe->in_generation)
        {
            screen.draw(text.text);
            text.update(tick);
        }
        game.update();
        sf::sleep(sf::seconds(sleep_time));
    }

    std::cout << "the seed was : " << seed << std::endl;
}
