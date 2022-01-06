#pragma once

#include <SFML/Graphics.hpp>

#include "Buttons.h"

enum class ButtonType
{
	ButtonRun = 0,
	ButtonHelp = 1,
	ButtonExit = 2,
};

class My_Button
{
public:
	My_Button(sf::Texture& texture1, sf::Texture& texture2, const sf::Vector2f& position, ButtonType buttonType);
	virtual ~My_Button() = 0 {}

	bool handleClick(const sf::Vector2f& location);
	void draw(sf::RenderWindow& window) const;

	ButtonType getButtonType();


protected:
	Buttons m_buttons;
	sf::Sprite m_sprite;
	sf::Sprite m_sprite2;
	sf::Vector2f m_position;

	ButtonType m_buttonType;

};