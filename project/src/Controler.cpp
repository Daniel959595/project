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
			exit;
		}
		m_board.readData(in);
		run();
		index++;
	};

}
void Controler:: run()
{

}
