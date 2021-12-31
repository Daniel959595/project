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
    auto deltaTime = m_clock.restart();
    m_sprite.move(dirFromKey() * m_speed * deltaTime.asSeconds());
}
