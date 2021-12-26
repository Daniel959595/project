#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"

class Controler
{
public:
    Controler();
	void menu();
	void loadLevels();
private:
	sf::RenderWindow m_window;
	Board m_board;

	void run();
};