#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <fstream>
#include <typeinfo>

#include "Figures.h"
#include "Moveable.h"
#include "Unmoveable.h"
#include "King.h"
#include "Warrior.h"
#include "Mage.h"
#include "Thief.h"
#include "Key.h"
#include "Fire.h"
#include "Teleporter.h"
#include "Wall.h"
#include "Gate.h"
#include "Ork.h"
#include "Throne.h"





class Board
{
public:
    //Board();
    void draw(sf::RenderWindow& window);
    void readData(std::ifstream& in);
    void loadVectors(char letter, float row, float col);

private:
    Figures m_figures;

    std::vector <std::unique_ptr <Moveable> > m_moveables;
    std::vector <std::unique_ptr <Unmoveable> > m_unmoveables;
    //std::vector <std::unique_ptr <Gift> > m_gifts;

};