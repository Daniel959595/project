#include "GameObj.h"
#include <iostream>

GameObj::GameObj(const sf::Texture& texture, const sf::Vector2f& position)
	:m_sprite(texture), m_position(position)
{
	m_sprite.setPosition(m_position);
}

void GameObj::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

const sf::Sprite& GameObj::get_sprite() const
{
	return m_sprite;
}

void GameObj::handleCollision(GameObj& gameObj)
{
    if (&gameObj == this) return;
    // double dispatch
    gameObj.handleCollision(*this);
}
