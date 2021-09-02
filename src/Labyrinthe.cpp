#include "Labyrinthe.hpp"
#include "Game.hpp"
#include "Case.hpp"
#include "Direction.hpp"
#include "Shovel.hpp"
#include <iostream>
#include <memory>


void drawLine(sf::RenderWindow& surface, sf::Vector2f point1, sf::Vector2f point2)
{
    sf::VertexArray line(sf::LinesStrip, 2);
    line[0].position = point1;
    line[1].position = point2;
    line[0].color = sf::Color::Black;
    line[1].color = sf::Color::Black;
    surface.draw(line);
}

Labyrinthe::Labyrinthe()
{

}

Labyrinthe::Labyrinthe(Game& game) {
    this->game = &game;
    in_generation = true;
    width = game.LabyrintheWidth / game.GridSize;
    height = game.LabyrintheHeight / game.GridSize;
    grid = new Case*[height];
    shovel = Shovel(*this);
    for (int y = 0; y < height; y++)
    {
        grid[y] = new Case[width];
        for (int x = 0; x < width; x++)
        {
            grid[y][x] = Case(x, y);
        }
    }
    grid[0][0].used = true;
    grid[height - 1][width - 1].bottom = false;
}

Labyrinthe::~Labyrinthe() {
    for (int y = 0; y < height; y++)
    {
        delete[] grid[y];
    }
    delete[] grid;
    std::cout << "i Lzbyrinthe deleted" << std::endl;
}

void Labyrinthe::draw() {

    Case* current_case;
    int const GridSize = game->GridSize;
    int const OffSet = game->offset;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            current_case = &(grid[y][x]);
            if (current_case->right)
            {
                drawLine(*game->screen, sf::Vector2f((x + 1) * GridSize + OffSet, y * GridSize + OffSet), sf::Vector2f((x + 1) * GridSize + OffSet, (y + 1) * GridSize + OffSet));      
            }
            if (current_case->bottom)
            {
                drawLine(*game->screen, sf::Vector2f(x * GridSize + OffSet, (y + 1) * GridSize + OffSet), sf::Vector2f((x + 1) * GridSize + OffSet, (y + 1) * GridSize + OffSet));
            }
        }
    }
    drawLine(*game->screen, sf::Vector2f(OffSet, OffSet), sf::Vector2f(width * GridSize + OffSet, OffSet));
    drawLine(*game->screen, sf::Vector2f(OffSet, OffSet), sf::Vector2f(OffSet, height * GridSize + OffSet));
    shovel.draw(*game->screen);
}

void Labyrinthe::neighbor(Case** neighbor, const sf::Vector2i position)
{

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
}

void Labyrinthe::skip() {
    while(in_generation)
    {
        shovel.move();
    }
}

void Labyrinthe::event(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::S)
            skip();
    }
}
