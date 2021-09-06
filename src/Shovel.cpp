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

Shovel::Shovel()
{

}

Shovel::Shovel(Labyrinthe& labyrinthe) {
    this->labyrinthe = &labyrinthe;
    coordinate = sf::Vector2i(0, 0);
    mouvements = std::stack<sf::Vector2i>();
    shape.setFillColor(sf::Color::Cyan);
    (&this->labyrinthe->grid[0][0])->used = true;
    shape.setRadius((labyrinthe.game->GridSize - labyrinthe.game->GridSize / 10) / 2);
}

Shovel::~Shovel() {
    std::cout << "shovel deleted" << std::endl;
}

void Shovel::move() {

    Case* neighbor[4];
    labyrinthe->neighbor(neighbor, coordinate);
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
        Case& current_case = labyrinthe->grid[coordinate.y][coordinate.x];
        Case& choice = *possible_case[rand() % possible_case.size()];

        if (coordinate.x - choice.x > 0)
        {
            choice.right = false;
        }

        else if (coordinate.x - choice.x < 0)
        {
            current_case.right = false;
        }

        if (coordinate.y - choice.y > 0)
        {
            choice.bottom = false;
        }

        else if (coordinate.y - choice.y < 0)
        {
            current_case.bottom = false;
        }

        choice.used = true;
        
        mouvements.push(coordinate);
        coordinate.x = choice.x;
        coordinate.y = choice.y;
    }
    else if (!mouvements.empty())
    {
        coordinate = mouvements.top();
        mouvements.pop();
    }
    else {
        labyrinthe->game->screen->setTitle("Génération finished");
        labyrinthe->in_generation = false;
        sf::Texture texture; 
        texture.create(labyrinthe->game->screen->getSize().x, labyrinthe->game->screen->getSize().y) ; 
        labyrinthe->game->draw();
        labyrinthe->game->screen->display();
        texture.update(*labyrinthe->game->screen); 
        if  (texture.copyToImage().saveToFile( "last labyrinthe.png" )) 
        { 
            std :: cout  <<  "capture d'écran enregistrée dans "  << "last labyrinthe.png" << std :: endl ; 
        }
    }
}

void Shovel::draw(sf::RenderWindow& window) {
    shape.setPosition(coordinate.x * labyrinthe->game->GridSize + labyrinthe->game->offset, coordinate.y * labyrinthe->game->GridSize + labyrinthe->game->offset);
    window.draw(shape);
}
