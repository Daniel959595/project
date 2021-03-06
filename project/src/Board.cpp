#include <iostream>
#include <stdlib.h>
#include <Time.h>
#include <math.h>

#include "Board.h"
#include "Controller.h"
#include "GiftAddTime.h"
#include "GiftRedTime.h"
#include "GiftRmvDwarf.h"


Board::Board()
{
    backGround.loadFromFile("BackGround2.png");
    m_gameBackGround.setTexture(backGround);

    m_infoFont.loadFromFile("C:/Windows/Fonts/arial.ttf");
    m_infoText.setFont(m_infoFont);
    m_infoText.setCharacterSize(50);
    m_infoText.setFillColor(sf::Color::Black);
    m_infoText.setOutlineThickness(4);
    m_infoText.setOutlineColor(sf::Color::Red);
    m_infoText.setPosition(80, 400);

    m_currentPlayer.setRadius(OBJ_SIZE / 2);
    m_currentPlayer.setFillColor(sf::Color::Transparent);
    m_currentPlayer.setOutlineThickness(3);
    m_currentPlayer.setOutlineColor(sf::Color::Red);
}

namespace
{
    sf::Vector2f dirFromKey()
    {
        static const
            std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
            keyToVectorMapping =
        {
            { sf::Keyboard::Right, { 1, 0 } },
            { sf::Keyboard::Left , { -1, 0 } },
            { sf::Keyboard::Up   , { 0, -1 } },
            { sf::Keyboard::Down , { 0, 1 } },
        };

        for (const auto& pair : keyToVectorMapping)
        {
            if (sf::Keyboard::isKeyPressed(pair.first))
            {
                return pair.second;
            }
        }

        return { 0, 0 };
    }
}

//read the data from the file into an array and from that array
//into the right vector.
void Board::readData(std::ifstream& in)
{
	std::vector<std::string> matrix;

	std::string str;
	getline(in, str);
	while (in)
	{
		matrix.push_back(str);
		getline(in, str);
	}

    m_boardWidth = OBJ_SIZE * matrix[0].size();
    m_boardHeight = OBJ_SIZE * matrix.size();

    float startFromX = ((WINDOW_WIDTH - INFO_AREA) - m_boardWidth) / 2 + INFO_AREA;
    float startFromY = (WINDOW_HEIGHT - m_boardHeight) / 2;

    m_topLeft = sf::Vector2f(startFromX, startFromY);
    m_bottomRight = sf::Vector2f(startFromX + m_boardWidth, startFromY + m_boardHeight);
    
	for (int row = 0; row < matrix.size(); ++row)
		for (int col = 0; col < matrix[row].size(); ++col)
		{
            if (matrix[row][col] == ' ')
                continue;
            loadVectors(matrix[row][col], float(row), float(col));
		}
    initFrame();
    setTeleportTwins();
    setEmptySlots(matrix);
}

void Board::initFrame()
{
    m_frame.setSize(sf::Vector2f(m_boardWidth, m_boardHeight));
    m_frame.setPosition(m_topLeft);
    m_frame.setOutlineThickness(10.0f);
    m_frame.setOutlineColor(sf::Color::Color(210, 105, 30));
    m_frame.setFillColor(sf::Color::Black);
}


void Board::loadVectors(char letter, float row, float col)
{
    sf::Vector2f location(m_topLeft.x + col * OBJ_SIZE , m_topLeft.y + row * OBJ_SIZE);

    switch (letter)
    {
        ///////////////////////////////////m_moveables//////////////////////////////

    case 'K':
    case 'k': 
        m_moveables.push_back(std::make_unique <King>(m_Figures.getFigure(Figure(0)), location));
        break;

    case 'W':
    case 'w':
        m_moveables.push_back(std::make_unique <Warrior>(m_Figures.getFigure(Figure(1)), location));
        break;

    case 'M':
    case 'm':
        m_moveables.push_back(std::make_unique <Mage>(m_Figures.getFigure(Figure(2)), location));
        break;

    case 'T':
    case 't':
        m_moveables.push_back(std::make_unique <Thief>(m_Figures.getFigure(Figure(3)), location));
        break;

    case '^':
        m_dwarf.push_back(std::make_unique <Dwarf>(m_Figures.getFigure(Figure(12)), location));
        break;

        ///////////////////////////////////m_unmoveables//////////////////////////////

    case '!':
        m_unmoveables.push_back(std::make_unique <Ork>(m_Figures.getFigure(Figure(4)), location));
        break;

    case '=':        
        m_unmoveables.push_back(std::make_unique <Wall>(m_Figures.getFigure(Figure(5)), location));
        break;

    case '*':       
        m_unmoveables.push_back(std::make_unique <Fire>(m_Figures.getFigure(Figure(6)), location));
        break;

    case '#':       
        m_unmoveables.push_back(std::make_unique <Gate>(m_Figures.getFigure(Figure(7)), location));
        break;

    case 'F':      
    case 'f':      
        m_unmoveables.push_back(std::make_unique <Key>(m_Figures.getFigure(Figure(8)), location));
        break;

    case 'X':
    case 'x':
        m_unmoveables.push_back(std::make_unique <Teleporter>(m_Figures.getFigure(Figure(9)), location));
        break;

    case '@':
        m_unmoveables.push_back(std::make_unique <Throne>(m_Figures.getFigure(Figure(10)), location));
        break;

    default:
        return;
    }
}

void Board::setTeleportTwins()
{
    std::vector<int> teleportIndex;
    for (int i = 0; i < m_unmoveables.size(); i++)
        if (typeid(*m_unmoveables[i]) == typeid(Teleporter))
        {
            teleportIndex.push_back(i);
        }
    
    for (int i = 0; i < teleportIndex.size(); i++)
    {
        m_unmoveables[teleportIndex[i]]->setTwinPos(m_unmoveables[teleportIndex[teleportIndex.size() - 1 - i]]->getPos());
    }
}

void Board::setEmptySlots(std::vector<std::string>& matrix)
{
    float startFromX = ((WINDOW_WIDTH - 350.0f) - m_boardWidth) / 2 + 350.0f;
    float startFromY = (WINDOW_HEIGHT - m_boardHeight) / 2;

    sf::Vector2f location;
    for (int row = 0; row < matrix.size(); ++row)
        for (int col = 0; col < matrix[row].size(); ++col)
        {
            if (matrix[row][col] == ' ')
            {
                location = sf::Vector2f(startFromX + OBJ_SIZE * col, startFromY + OBJ_SIZE * row);
                m_emptySlots.push_back(std::make_unique <sf::Vector2f>(location));
            }
        }
}

void Board::handleGifts()
{
    int timePassed = m_gameTime.getTimePassed();
    
    for (auto& gift : m_gifts)
    {
        if (gift->handleGiftLife())
            m_isGift = false;
    }

    std::erase_if(m_gifts, [](auto& gift)
        {
            return gift->isDisposed();
        });

    addRandomGift(timePassed);
}

void Board::addRandomGift(int timePassed)
{
    static int index = 1;
    srand(index++);
    int randomGift = rand() % 3;
    int randomPos = rand() % m_emptySlots.size();
    if (timePassed % 10 == 0 && timePassed > 0 && !m_isGift)
    {
        m_isGift = true;
        switch (randomGift)
        {
        case 0:
            m_gifts.push_back(std::make_unique <GiftAddTime> (m_Figures.getFigure(Figure(11)), getRandomPos()));
            break;

        case 1:
            m_gifts.push_back(std::make_unique <GiftRedTime>(m_Figures.getFigure(Figure(11)), getRandomPos()));
            break;

        case 2:
            m_gifts.push_back(std::make_unique <GiftRmvDwarf>(m_Figures.getFigure(Figure(11)), getRandomPos()));
            break;

        default:
            break;
        }
    }
}

sf::Vector2f& Board::getRandomPos()
{
    int randomPos = rand() % m_emptySlots.size();
    return *m_emptySlots[randomPos];
}

void Board::setIsGift()
{
    m_isGift = false;
}

void Board::setIsWin()
{
    m_isWin = !m_isWin;
}

void Board::setIsKey(bool statement)
{
    m_isKey = statement;
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(m_gameBackGround);
    window.draw(m_frame);
    drawInfo(window);
    for (auto &index : m_moveables)
    {
        index->draw(window);
    }

    for (auto& index : m_unmoveables)
    {
        index->draw(window);
    }

    for (auto& index : m_gifts)
    {
        index->draw(window);
    }

    for (auto& index : m_dwarf)
    {
        index->draw(window);
    }
}

void Board::drawInfo(sf::RenderWindow& window)
{
    m_gameTime.draw(window);
    std::string str0("level " + std::to_string(m_levelIndex) );
    std::string str1(".\n\npress P to\nchange player.\n\n");
    std::string str2(m_isKey ? "the thief\nhas a key." : 
                               "the thief\ndosen't have a key.");
    m_infoText.setString(str0 + str1 + str2);
    window.draw(m_infoText);

    drawCurrentPlayer(window);
}

void Board::drawCurrentPlayer(sf::RenderWindow& window)
{
    m_currentPlayer.setPosition(m_moveables[m_playerIndex]->getPos());
    window.draw(m_currentPlayer);
}

void Board::moveObjects()
{
    sf::Vector2f direction(dirFromKey());
    auto deltaTime = m_moveables[m_playerIndex]->getDeltaTime();
    sf::Vector2f playerPos = m_moveables[m_playerIndex]->getPos();

    if (checkBoundsCollis(direction, playerPos))
    {
        m_moveables[m_playerIndex]->move(direction, deltaTime);
    }
    
    for (auto& dwarf : m_dwarf)
    {
        sf::Vector2f dwarfPos = dwarf->getPos();
        if (checkBoundsCollis(dwarf->getDirection(), dwarfPos))
            dwarf->move(deltaTime);
        else
            dwarf->changeDirection();
    }
}

bool Board::checkBoundsCollis(sf::Vector2f& direction, sf::Vector2f& ObjPos)
{    
    if ((direction.x < 0 && ObjPos.x < m_topLeft.x) ||
        (direction.y < 0 && ObjPos.y < m_topLeft.y) ||
        (direction.x > 0 && ObjPos.x > m_bottomRight.x - OBJ_SIZE) ||
        (direction.y > 0 && ObjPos.y > m_bottomRight.y - OBJ_SIZE))
        return false;
    return true;
}

void Board::setPlayer()
{
    static int i = 0;
    m_playerIndex = (++i)%4;
    if (i > 3)
        i = 0;
}

bool Board::handleCollisions()
{
    for (auto& dwarf : m_dwarf)
    {
        checkCollisions(*dwarf);
    }

    for (auto& movable : m_moveables)
    {
        if (checkCollisions(*movable))
            return true;
    }
    
    resetTeleportCollision();

    std::erase_if(m_unmoveables, [](auto& unmovable)
        {
            return unmovable->isDisposed();
        });

    return false;
}

bool Board::checkCollisions(Moveable& obj)
{
    for (auto& unmovable : m_unmoveables)
    {
        if (obj.checkCollision(*unmovable))
        {
            obj.handleCollision(*unmovable, *this);
        }
    }

    if (typeid(obj) == typeid(Dwarf))
    {
        for (auto& moveable : m_moveables)
        {
            if (obj.checkCollision(*moveable))
                obj.handleCollision(*moveable, *this);
        }
    }

    for (auto& gift : m_gifts)
    {
        if (obj.checkCollision(*gift))
            gift->handleCollision(obj, *this);
    }

    for (auto& dwarf : m_dwarf)
    {
        if (obj.checkCollision(*dwarf))
            obj.handleCollision((*dwarf), *this);
    }

    if (m_isWin)
        return true;
    return false;
}

void Board::startTime()
{
    m_gameTime.startGameTime();
}

void Board::setTimers(bool statement)
{
    m_gameTime.setIsTimer(statement, std::sqrt(std::sqrt(
            (m_boardHeight/ OBJ_SIZE)* (m_boardWidth/OBJ_SIZE) )) * 60);
    m_moveables[0]->getDeltaTime(); //restart the deltaTime of the moveables. 
}

void Board::setLevelIndex(int curr_level)
{
    m_levelIndex = curr_level;
}

bool Board::handleTime()
{
    return m_gameTime.handleTime();
}

void Board::resetTeleportCollision()
{
    bool isOnTeleport = false;
    for (auto& unmovable : m_unmoveables)
    {
        if (typeid(*unmovable) == typeid(Teleporter))
        {
            if (m_moveables[m_playerIndex]->checkCollision(*unmovable))
            {
                isOnTeleport = true;
                break;
            }
        }
    }
    m_moveables[m_playerIndex]->set_isTeleported(isOnTeleport);
}

void Board::activateSounds(Sound sound)
{
    m_sounds.activateSound(sound);
}

void Board::createKey(GameObj& obj)
{
    m_unmoveables.push_back(std::make_unique <Key>(m_Figures.getFigure(Figure(8)), obj.getPos()));
}

void Board::clearData()
{
    m_moveables.clear();
    m_unmoveables.clear();
    m_gifts.clear();
    m_dwarf.clear();
    m_emptySlots.clear();
    m_isGift = false;
}

void Board::addTime()
{
    m_gameTime.addTime(30);
}

void Board::redTime()
{
    m_gameTime.redTime(30);
}

void Board::rmvDwarf()
{
    m_dwarf.clear();
}