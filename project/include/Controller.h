#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
#include "Buttons.h"
#include "My_Button.h"

const float WINDOW_WIDTH = 1400.0f;
const float WINDOW_HEIGHT = 900.0f;

class Controller
{
public:
	Controller();
	void menuAndRun();

private:

	sf::RenderWindow m_window;
	Board m_board;

	Buttons m_buttonsData; //class with all the buttons pictures
	ButtonType getPressedButton(sf::Vector2f& location);
	std::vector <std::unique_ptr <My_Button> > m_buttons;

	sf::Sprite m_backGroundSprite;
	sf::Clock m_timer;

	void loadButtons();
	void drawMenu();
	bool handleButtons(sf::Vector2f& location);
	void handleButtonClick(ButtonType pressedButton);
	void loadLevels();
	void run();
	void draw();
	void handleEvents();
	void handleTimer();
	void updateGameObjects();
	bool handleCollisions();
};