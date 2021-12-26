#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <fstream>
#include <typeinfo>

#include "Figures.h"
#include "MoveAble.h"
#include "King.h"





class Board
{
public:
    Board();
    void draw(sf::RenderWindow& window);
    void readData(std::ifstream& in);
    GameObj* getType(char letter);

private:
    Figures m_figures;
    std::vector <std::unique_ptr <MoveAble> > m_moveAbles;
};
