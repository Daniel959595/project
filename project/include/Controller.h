#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Board.h"
#include "Buttons.h"
#include "My_Button.h"

const float WINDOW_WIDTH = 1920.0f;
const float WINDOW_HEIGHT = 1080.0f;

enum class Situation
{
	levelSucceed = 0,
	levelFailed,
	gameFinished,
};

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

	sf::Texture m_helpText;
	sf::Sprite m_helpSprite;
	std::vector <std::unique_ptr <My_Button> > m_helpButtons;

	sf::Sprite m_backGroundSprite;

	sf::Music m_menuMusic;

	void loadButtons();
	void drawMenu();
	bool handleButtons(sf::Vector2f& location);
	void handleButtonClick(ButtonType pressedButton);
	void showHelpWindow();
	void loadAndRun();
	Situation run();  //return false if the player fails or pressed es
	void draw();
	void handleEvents();
	void updateGameObjects();
	void updateGifts();
	bool handleCollisions();
	bool handleTime();
};