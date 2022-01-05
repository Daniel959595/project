#include "Button.h"

Button::Button(const sf::Vector2f& position, sf::Texture& texture)
	: m_position(position), m_sprite(texture)
{
}

void Button::draw(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}

bool Button::handleClick(const sf::Vector2f& location)
{
    if (m_sprite.getGlobalBounds().contains(location))
    {
        return true;
    }
    return false;
}