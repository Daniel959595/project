#include "Controller.h"
#include <string.h>
#include <iostream>
#include <fstream>



Controller::Controller()
	: m_window(sf::VideoMode(1400, 900), "Save the King")
{
}

void Controller::menuAndRun()
{
	//help();
	//loadLevels();
	while (m_window.isOpen())
	{
		m_window.clear();
		m_board.draw(m_window);
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			sf::Vector2f location;
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseMoved:
				location = m_window.mapPixelToCoords(
					{ event.mouseMove.x, event.mouseMove.y });
				m_board.handleColor(location);
				m_board.handleMove(location);
				break;

			case sf::Event::MouseButtonReleased:
				location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				m_board.handleClick(location);
				break;

			}
		}
	}
}

void Controller::loadLevels()
{
	int index = 1;
	while (true)
	{
		std::string fileName = { "level_" + std::to_string(index) + ".txt" };
		std::ifstream in;
		in.open(fileName);
		if (!in.is_open())
		{
			std::cout << "end!\n";
			exit (0);
		}
		m_board.readData(in);
		run();
		m_board.clearData();
		index++;
	};
}

void Controller:: run()
{
	while (m_window.isOpen())
	{
		draw();
		handleEvents();
		updateGameObjects();
		if (handleCollisions()) //bool:::win level!
			return;
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
	m_board.movePlayer();
	//dwrf
}

bool Controller::handleCollisions()
{
	return m_board.handleCollisions();
}


