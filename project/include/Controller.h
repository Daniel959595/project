#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"

class Controller
{
public:
	Controller();
	void menu();

private:
	sf::RenderWindow m_window;
	Board m_board;

	sf::Clock m_clock;
	//sf::Clock m_timerClock;

	void loadLevels();

	void run();
	void draw();
	void handleEvents();
	void updateGameObjects();
};