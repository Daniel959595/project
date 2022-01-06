#include "My_Button.h"

My_Button::My_Button(sf::Texture& texture1, sf::Texture& texture2, const sf::Vector2f& position, ButtonType buttonType)
        : m_sprite(texture1), m_sprite2(texture2), m_position(position), m_buttonType(buttonType)
{
    m_sprite.setPosition(m_position);
    m_sprite2.setPosition(m_position);
}

void My_Button::draw(sf::RenderWindow& window) const
{
    window.draw(m_sprite);
}

bool My_Button::handleClick(const sf::Vector2f& location)
{
    if (m_sprite.getGlobalBounds().contains(location))
    {
        return true;
    }
    return false;
}

ButtonType My_Button::getButtonType()
{
    return m_buttonType;
}
