#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class GameObj
{
public:
	GameObj(const sf::Texture& texture, const sf::Vector2f& position);
	void draw(sf::RenderWindow& window);
	virtual ~GameObj() = 0 {}

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
};