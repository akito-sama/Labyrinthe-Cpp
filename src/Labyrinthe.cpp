#include "Labyrinthe.hpp"
#include "Game.hpp"
#include "Case.hpp"
#include "iostream"


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
    width = game->screenWidth / game->GridSize;
    height = game->screenHeight / game->GridSize;
    grid = new Case*[height];
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
}
