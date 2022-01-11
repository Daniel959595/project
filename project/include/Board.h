#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <fstream>
#include <typeinfo>

#include "Timers.h"
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
#include "Gift.h"



class Board
{
public:
    Board();
    void draw(sf::RenderWindow& window);
    void readData(std::ifstream& in);
    void loadVectors(char letter, float row, float col);
    void setTeleportTwins();
    void setEmptySlots(std::vector<std::string>& matrix);
    void handleGifts();
    void addRandomGift(int timePassed);
    void setIsGift();
    sf::Vector2f& getRandomPos();
    void movePlayer();
    bool checkBoundsCollis(sf::Vector2f& direction);
    void setPlayer();
    bool handleCollisions();
    bool checkCollisions(Moveable& obj);
    bool handleTime();
    void startTime();
    void setTimer(bool statement);
    void teleportCollision();
    void createKey();
    void initFrame();
    void clearData();
    void addTime();
    void redTime();
    void rmvDwarf();

private:

    Figures m_figures;
    int m_playerIndex = 0;

    sf::RectangleShape m_frame;
    sf::Texture backGround;
    sf::Sprite m_gameBackGround;

    sf::Vector2f m_topLeft;
    sf::Vector2f m_bottomRight;

    float m_boardWidth;
    float m_boardHeight;

    Timers m_gameTime;       //class that hold all the clocks

    bool m_isGift = false;

    std::vector <std::unique_ptr <sf::Vector2f> > m_emptySlots; //save empty positions for the random gifts;

    std::vector <std::unique_ptr <Moveable> > m_moveables;
    std::vector <std::unique_ptr <Unmoveable> > m_unmoveables;
    std::vector <std::unique_ptr <Gift> > m_gifts;
    //std::vector <std::unique_ptr <Dwarf> > m_dwarf;
};
