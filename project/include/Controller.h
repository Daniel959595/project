#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
#include "Button.h"

class Controller
{
public:
	Controller();
	void menuAndRun();

private:

	sf::RenderWindow m_window;
	Board m_board;
	std::vector <std::unique_ptr <Button> > m_buttons;

	void loadLevels();
	void run();
	void draw();
	void handleEvents();
	void updateGameObjects();
	bool handleCollisions();
};