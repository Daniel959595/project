#include "Controller.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include "ButtonRun.h"
#include "ButtonHelp.h"
#include "ButtonExit.h"
#include "ButtonReturn.h"




Controller::Controller()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save the King") , m_backGroundSprite(m_buttonsData.getBackGround())
{
	m_window.setFramerateLimit(60);
	m_helpText.loadFromFile("helpWindow.png");
	m_helpSprite.setTexture(m_helpText);
	m_helpSprite.setPosition(0, 0);
	loadButtons();

	m_menuMusic.openFromFile("menuMusic.wav");
	m_menuMusic.setLoop(true);
}

void Controller::menuAndRun()
{
	ButtonType pressedButton;
	while (m_window.isOpen())
	{
		if (m_menuMusic.getStatus() != sf::Music::Playing)
			m_menuMusic.play();
		m_window.clear();
		drawMenu();
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			sf::Vector2f location;
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			//case sf::Event::MouseMoved:
			//	location = m_window.mapPixelToCoords(
			//		{ event.mouseMove.x, event.mouseMove.y });
			//	m_board.handleColor(location);
			//	m_board.handleMove(location);
			//	break;

			case sf::Event::MouseButtonReleased:
				location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if (handleButtons(location))
				{
					pressedButton = getPressedButton(location);
					handleButtonClick(pressedButton);
				}
				break;

			}
		}
	}
}

void Controller::loadButtons()
{
	int buttonWidth = 300;
	sf::Vector2f location;
	auto yPos = m_window.getSize().y / 5;
	auto xPos = (m_window.getSize().x / 2) - (buttonWidth / 2);
	int i = 1;
	location = sf::Vector2f(xPos, i++ * yPos);
	m_buttons.push_back(std::make_unique <ButtonRun>(m_buttonsData.getButton(Button(0)), m_buttonsData.getButton(Button(1)), location, ButtonType(0)));
	location = sf::Vector2f(xPos, i++ * yPos);
	m_buttons.push_back(std::make_unique <ButtonHelp>(m_buttonsData.getButton(Button(2)), m_buttonsData.getButton(Button(3)), location, ButtonType(1)));
	location = sf::Vector2f (xPos, i * yPos);
	m_buttons.push_back(std::make_unique <ButtonExit>(m_buttonsData.getButton(Button(4)), m_buttonsData.getButton(Button(5)), location, ButtonType(2)));

	location = sf::Vector2f(100, 100);
	m_helpButtons.push_back(std::make_unique <ButtonReturn>(m_buttonsData.getButton(Button(6)), m_buttonsData.getButton(Button(6)), location, ButtonType(6)));
}

void Controller::drawMenu()
{
	m_window.draw(m_backGroundSprite);
	for (auto& button : m_buttons)
	{
		button->draw(m_window);
	}
}

bool Controller::handleButtons(sf::Vector2f& location)
{
	for (auto& button : m_buttons)
	{
		if (button->handleClick(location))
			return true;
	}
	return false;
}

ButtonType Controller::getPressedButton(sf::Vector2f& location)
{
	ButtonType pressedButton;
	for (auto& button : m_buttons)
	{
		if (button->handleClick(location))
			pressedButton = button->getButtonType();
	}
	return pressedButton;
}

void Controller::handleButtonClick(ButtonType pressedButton)
{
	switch (pressedButton)
	{
	case ButtonType::ButtonRun:
		loadAndRun();
		break;
	case ButtonType::ButtonHelp:
		showHelpWindow();
		break;
	case ButtonType::ButtonExit:
		m_window.close();
		break;
	default:
		break;
	}
}
/// <buttons>
/////////////////////////////////////////////////////////////

void Controller::showHelpWindow()
{
	ButtonType pressedButton;

	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(m_helpSprite);
		m_helpButtons[0]->draw(m_window);
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			sf::Vector2f location;
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonReleased:
				location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if (m_helpButtons[0]->handleClick(location))
				{
					return;
				}
				break;
			}
		}
	}	
}

void Controller::loadAndRun()
{
	m_menuMusic.pause();
	
	int index = 1; 
	Situation situation;
	m_board.startTime(); 
	while (m_window.isOpen())
	{
		std::string fileName = { "level_" + std::to_string(index) + ".txt" };
		std::ifstream in;
		in.open(fileName);
		if (!in.is_open())
		{
			std::cout << "end!\n";
			situation = Situation::gameFinished;
			return;
		}
		m_board.readData(in);
		m_board.setTimers(true); 
		situation = run();
		switch (situation)
		{
		case Situation::levelSucceed:
			index++;
			m_board.setIsWin();
			break;
		case Situation::levelFailed:
			break;
		default:
			break;
		}
		m_board.clearData();
	};
}

Situation Controller::run()
{
	while (m_window.isOpen())
	{
		draw();
		handleEvents();
		updateGameObjects();
		updateGifts();
		if (!handleTime()) return Situation::levelFailed;
		if (handleCollisions()) return Situation::levelSucceed;
	}
}

void Controller::draw()
{
	m_window.clear();
	m_board.draw(m_window);
	m_window.display();
}

void Controller::handleEvents()
{
	for (auto event = sf::Event(); m_window.pollEvent(event); )
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_window.close();
				break;
			}
			else if (event.key.code == sf::Keyboard::P)
				m_board.setPlayer();
			break;
		}
	}
}

void Controller::updateGameObjects()
{
	m_board.moveObjects();
}

void Controller::updateGifts()
{
	m_board.handleGifts();
}

bool Controller::handleCollisions()
{
	return m_board.handleCollisions();
}

bool Controller::handleTime()
{
	return m_board.handleTime();
}

