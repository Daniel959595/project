#include "GameObj.h"
#include "Wall.h"
#include "King.h"
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

bool GameObj::checkCollision(const GameObj& other) const
{
	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}

//void GameObj::handleCollision(GameObj& gameObj)
//{
//	if (&gameObj == this) return;
//	// double dispatch
//	gameObj.handleCollision(*this);
//}

//void GameObj::handleCollision(Wall& gameObj)
//{
//	return;
//}
