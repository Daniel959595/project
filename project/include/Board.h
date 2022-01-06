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

    void draw(sf::RenderWindow& window);
    void readData(std::ifstream& in);
    void loadVectors(char letter, float row, float col);
    void setTeleportTwins();
    void movePlayer();
    void setPlayer();
    bool handleCollisions();
    bool checkCollisions(Moveable& obj);
    void teleportCollision();
    void createKey();

    void clearData();

private:

    Figures m_figures;
    int m_playerIndex = 0;
    float m_boardWidth;
    float m_boardHeight;
    std::vector <std::unique_ptr <Moveable> > m_moveables;
    std::vector <std::unique_ptr <Unmoveable> > m_unmoveables;
};
