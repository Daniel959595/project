#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <fstream>
#include <typeinfo>

#include "Figures.h"
#include "MoveAble.h"
#include "King.h"
#include "Warrior.h"
#include "Mage.h"
#include "Thief.h"





class Board
{
public:
    //Board();
    void draw(sf::RenderWindow& window);
    void readData(std::ifstream& in);
    void loadVectors(char letter, int row, int col);

private:
    Figures m_figures;

    std::vector <std::unique_ptr <MoveAble> > m_moveAbles;
    //std::vector <std::unique_ptr <UnMoveAble> > m_unmoveAbles;
    //std::vector <std::unique_ptr <Gift> > m_gifts;

};
