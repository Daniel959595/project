#include "GameObj.h"
#include <iostream>

GameObj::GameObj(const sf::Texture& texture, const sf::Vector2f& position)
	:m_sprite(texture), m_position(position)
{
	//::cout << position.x <<  " " << position.y << std::endl;
	m_sprite.setPosition(m_position);
}

void GameObj::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}