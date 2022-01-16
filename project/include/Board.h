#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <fstream>
#include <typeinfo>
#include <string.h>

#include "Timers.h"
#include "Figures.h"
#include "ObjectSounds.h"

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
#include "Dwarf.h"



class Board
{
public:
    Board();
    void draw(sf::RenderWindow& window);
    void drawInfo(sf::RenderWindow& window);
    void drawCurrentPlayer(sf::RenderWindow& window);
    void readData(std::ifstream& in);
    void loadVectors(char letter, float row, float col);
    void setTeleportTwins();
    void setEmptySlots(std::vector<std::string>& matrix);
    void handleGifts();
    void addRandomGift(int timePassed);
    void setIsGift();
    void setIsWin();
    void setIsKey(bool statement);
    sf::Vector2f& getRandomPos();
    void moveObjects();
    bool checkBoundsCollis(sf::Vector2f& direction, sf::Vector2f& ObjPos);
    void setPlayer();
    bool handleCollisions();
    bool checkCollisions(Moveable& obj);
    bool handleTime();
    void startTime();
    void setTimers(bool statement);
    void resetTeleportCollision();
    void activateSounds(Sound sound);
    void createKey(GameObj& obj);
    void initFrame();
    void clearData();
    void addTime();
    void redTime();
    void rmvDwarf();

private:

    Figures m_Figures;
    ObjectSounds m_sounds;
    Timers m_gameTime;       //class that hold all the clocks

    sf::RectangleShape m_frame;
    sf::Texture backGround;
    sf::Sprite m_gameBackGround;

    sf::Font m_infoFont;
    sf::Text m_infoText;
    sf::CircleShape m_currentPlayer;

    sf::Vector2f m_topLeft;
    sf::Vector2f m_bottomRight;

    float m_boardWidth = 0;
    float m_boardHeight = 0;

    int m_playerIndex = 0;

    bool m_isGift = false;
    bool m_isWin = false;
    bool m_isKey = false;

    std::vector <std::unique_ptr <sf::Vector2f> > m_emptySlots;
    std::vector <std::unique_ptr <Moveable> > m_moveables;
    std::vector <std::unique_ptr <Unmoveable> > m_unmoveables;
    std::vector <std::unique_ptr <Gift> > m_gifts;
    std::vector <std::unique_ptr <Dwarf> > m_dwarf;
};
