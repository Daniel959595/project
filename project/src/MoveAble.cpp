#include "Moveable.h"
#include <iostream>


sf::Clock Moveable::m_clock;

namespace
{
    sf::Vector2f dirFromKey()
    {
        static const
            std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
            keyToVectorMapping =
        {
            { sf::Keyboard::Right, { 1, 0 } },
            { sf::Keyboard::Left , { -1, 0 } },
            { sf::Keyboard::Up   , { 0, -1 } },
            { sf::Keyboard::Down , { 0, 1 } },
        };

        for (const auto& pair : keyToVectorMapping)
        {
            if (sf::Keyboard::isKeyPressed(pair.first))
            {
                return pair.second;
            }
        }

        return { 0, 0 };
    }
}

//void Moveable::move(sf::Time& deltaTime)
//{
//    m_sprite.move(dirFromKey() * m_speed * deltaTime.asSeconds());
//}

void Moveable::move()
{
//    m_direction.x = dirFromKey().x;
//    m_direction.y = dirFromKey().y;
    auto deltaTime = m_clock.restart();
    m_sprite.move(dirFromKey() * m_speed * deltaTime.asSeconds());
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

