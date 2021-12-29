#include "Controller.h"
#include <string.h>
#include <iostream>
#include <fstream>



Controller::Controller()
	: m_window(sf::VideoMode(1400, 900), "Save the King")
{
}

void Controller::menu()
{
	//help()
	loadLevels();
}

void Controller::loadLevels()
{
	int index = 1;
	while (true)
	{
		std::string fileName = { "level_" + std::to_string(index) + ".txt" };
		//fileName.insert(fileName.begin() + 6, char(48 + index));
		std::ifstream in;
		in.open(fileName);
		if (!in.is_open())
		{
			//menu();  ??
			std::cout << "end!\n";
			exit (0);
		}
		m_board.readData(in);
		run();
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
		m_board.handleCollisions();
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
	auto deltaTime = m_clock.restart();
	m_board.movePlayer(deltaTime);
	//m_board.moveDwarfs(deltaTime);
}


