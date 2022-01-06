#include "Moveable.h"
#include <iostream>


sf::Clock Moveable::m_clock;


//void Moveable::move(sf::Time& deltaTime)
//{
//    m_sprite.move(dirFromKey() * m_speed * deltaTime.asSeconds());
//}

void Moveable::move(sf::Vector2f& direction, sf::Time& deltaTime)
{
//    m_direction.x = dirFromKey().x;
//    m_direction.y = dirFromKey().y;
    //auto deltaTime = m_clock.restart();
    m_sprite.move(direction * m_speed * deltaTime.asSeconds());
}

void Moveable::moveBack(GameObj& other)
{
    
    sf::FloatRect playerBounds = this->m_sprite.getGlobalBounds();
    float xDist = abs((other.getLeftBounds() + (other.getWidth() / 2)) - (playerBounds.left + (playerBounds.width / 2)));
    float yDist = abs((other.getTopBounds() + (other.getHeight() / 2)) - (playerBounds.top + (playerBounds.height / 2)));
    if (xDist > yDist)
    {
        if (playerBounds.left < other.getLeftBounds())
            this->m_sprite.setPosition(other.getLeftBounds() - playerBounds.width, playerBounds.top);
        else 
            this->m_sprite.setPosition(other.getLeftBounds() + other.getWidth(), playerBounds.top);
    }

    else
    {
        if (playerBounds.top > other.getTopBounds())
            this->m_sprite.setPosition(playerBounds.left, other.getTopBounds() + other.getHeight());
        else
            this->m_sprite.setPosition(playerBounds.left, other.getTopBounds() - playerBounds.height);
    }
}

