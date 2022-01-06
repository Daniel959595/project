#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
#include "Buttons.h"
#include "My_Button.h"

class Controller
{
public:
	Controller();
	void menuAndRun();

private:

	sf::RenderWindow m_window;
	Board m_board;
	Buttons m_buttonsData;
	std::vector <std::unique_ptr <My_Button> > m_buttons;

	void loadButtons();
	void drawButtons();
	bool handleButtons(sf::Vector2f& location);
	ButtonType getPressedButton(sf::Vector2f& location);
	void handleButtonClick(ButtonType pressedButton);

	void loadLevels();
	void run();
	void draw();
	void handleEvents();
	void updateGameObjects();
	bool handleCollisions();
};