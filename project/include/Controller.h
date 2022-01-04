#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"

class Controller
{
public:
	Controller();
	void menuAndRun();

private:

	sf::RenderWindow m_window;
	Board m_board;

	void loadLevels();
	void run();
	void draw();
	void handleEvents();
	void updateGameObjects();
	bool handleCollisions();
};