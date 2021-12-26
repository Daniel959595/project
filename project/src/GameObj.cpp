#include "GameObj.h"

GameObj::GameObj(const sf::Texture& texture, const sf::Vector2f& position)
	:m_sprite(texture), m_position(position)
{
}

void GameObj::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}