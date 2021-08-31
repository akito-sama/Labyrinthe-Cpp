#include "Labyrinthe.hpp"
#include "Game.hpp"
#include "Case.hpp"
#include "Direction.hpp"
#include "Shovel.hpp"
#include <iostream>
#define log(x) std::cout<< x <<std::endl

void drawLine(sf::RenderWindow* surface, sf::Vector2f point1, sf::Vector2f point2)
{
    sf::VertexArray line(sf::LinesStrip, 2);
    line[0].position = point1;
    line[1].position = point2;
    line[0].color = sf::Color::Black;
    line[1].color = sf::Color::Black;
    surface->draw(line);
}

Labyrinthe::Labyrinthe()
{

}

Labyrinthe::Labyrinthe(Game* game) {
    this->game = game;
    in_generation = true;
    width = game->screenWidth / game->GridSize;
    height = game->screenHeight / game->GridSize;
    grid = new Case*[height];
    shovel = new Shovel(this);
    for (int y = 0; y < height; y++)
    {
        grid[y] = new Case[width];
        for (int x = 0; x < width; x++)
        {
            grid[y][x] = Case(game, x, y);
        }
    }
}

Labyrinthe::~Labyrinthe() {
    for (int y = 0; y < height; y++)
    {
        delete[] grid[y];
    }
    // std::cout << "i am deleted" << std::endl;
    delete[] grid;
    delete shovel;
}

void Labyrinthe::draw() {

    Case* current_case;
    int const GridSize = game->GridSize;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            current_case = &(grid[y][x]);
            if (current_case->right)
            {
                drawLine(game->screen, sf::Vector2f((x + 1) * GridSize, y * GridSize), sf::Vector2f((x + 1) * GridSize, (y + 1) * GridSize));      
            }
            if (current_case->bottom)
            {
                drawLine(game->screen, sf::Vector2f(x * GridSize, (y + 1) * GridSize), sf::Vector2f((x + 1) * GridSize, (y + 1) * GridSize));
            }
        }
    }
    shovel->draw(game->screen);
}

Case** Labyrinthe::neighbor(const sf::Vector2i position)
{
    Case** neighbor = new Case*[4];

    if (position.y == 0)
        neighbor[Direction::Up] = nullptr;
    else
        neighbor[Direction::Up] = &grid[position.y - 1][position.x];
    
    if (position.x == (width - 1))
        neighbor[Direction::Right] = nullptr;
    else
        neighbor[Direction::Right] = &grid[position.y][position.x + 1];

    if (position.y == (height - 1))
        neighbor[Direction::Down] = nullptr;
    else
        neighbor[Direction::Down] = &grid[position.y + 1][position.x];

    if (position.x == 0)
        neighbor[Direction::Left] = nullptr;
    else
        neighbor[Direction::Left] = &grid[position.y][position.x - 1];

    return neighbor;
}
