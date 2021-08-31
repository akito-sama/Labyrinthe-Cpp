#include "Shovel.hpp"
#include "Case.hpp"
#include "Direction.hpp"
#include "Labyrinthe.hpp"
#include "Game.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& o, Case _case);
std::ostream& operator<<(std::ostream& o, sf::Vector2i vector)
{
    o << vector.x << ", " << vector.y;
    return o;
}


Shovel::Shovel(Labyrinthe* labyrinthe) {
    this->labyrinthe = labyrinthe;
    coordinate = sf::Vector2i(0, 0);
    mouvements = new std::stack<sf::Vector2i>();
    shape.setFillColor(sf::Color::Cyan);
    labyrinthe->grid[coordinate.y][coordinate.x].used = true; 
    shape.setRadius(5);
}

Shovel::~Shovel() {
    delete[] mouvements;
    std::cout << "shovel deleted" << std::endl;
}

void Shovel::move() {

    auto neighbor = labyrinthe->neighbor(coordinate);
    std::vector<Case*> possible_case = {};
    possible_case.reserve(4);
    for (int i = 0; i < 4; i++)
    {
        auto _case = neighbor[i];
        if (_case != nullptr)
        {
            if (!_case->used)
            {
                possible_case.push_back(_case);
            }
        }
    }

    if (!possible_case.empty())
    {
        Case* current_case = &labyrinthe->grid[coordinate.y][coordinate.x];
        Case* choice = possible_case[rand() % possible_case.size()];

        if (coordinate.x - choice->x > 0)
        {
            choice->right = false;
        }

        else if (coordinate.x - choice->x < 0)
        {
            current_case->right = false;
        }

        if (coordinate.y - choice->y > 0)
        {
            choice->bottom = false;
        }

        else if (coordinate.y - choice->y < 0)
        {
            current_case->bottom = false;
        }
        std::cout << coordinate << std::endl;
        std::cout << *choice << std::endl;

        choice->used = true;
        
        mouvements->push(coordinate);
        coordinate.x = choice->x;
        coordinate.y = choice->y;
    }
    else if (!mouvements->empty())
    {
        coordinate = mouvements->top();
        mouvements->pop();
    }
    else
    {
        labyrinthe->game->screen->setTitle("Génération fini");
        labyrinthe->in_generation = false;
    }

    delete[] neighbor;
}

void Shovel::draw(sf::RenderWindow* window) {
    shape.setPosition(coordinate.x * 20, coordinate.y * 20);
    window->draw(shape);
}
