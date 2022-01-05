#pragma once

#include <SFML/Graphics.hpp>


class Button
{
public:
	Button(const sf::Vector2f& position, sf::Texture& texture);
	virtual ~Button() = 0 {}

	bool handleClick(const sf::Vector2f& location);
	void draw(sf::RenderWindow& window) const;

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;


};