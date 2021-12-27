#include "Controler.h"
#include <string.h>
#include <iostream>
#include <fstream>



Controler::Controler()
	: m_window(sf::VideoMode(1400, 900), "Save the King")
{
}

void Controler::menu()
{
	loadLevels();
}

void Controler::loadLevels()
{
	int index = 1;
	while (true)
	{
		std::string fileName = { "level_.txt" };
		fileName.insert(fileName.begin() + 6, char(48 + index));
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
void Controler:: run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_board.draw(m_window);
		m_window.display();

		// Handle events
		//sf::Event event;
		for (auto event = sf::Event{}; m_window.pollEvent(event);)
		{
			// Window closed or escape key pressed: exit
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

			}
		}
	}
}
