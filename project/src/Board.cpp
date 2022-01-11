#include <iostream>
#include <stdlib.h>
#include <Time.h>

#include "Board.h"
#include "Controller.h"
#include "GiftAddTime.h"
#include "GiftRedTime.h"
#include "GiftRmvDwarf.h"

const float OBJ_SIZE = 50.0f;

Board::Board()
{
    backGround.loadFromFile("BackGround2.png");
    m_gameBackGround.setTexture(backGround);
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
    float startFromX = ((WINDOW_WIDTH - 350.0f) - m_boardWidth) / 2 + 350.0f;
    float startFromY = (WINDOW_HEIGHT - m_boardHeight) / 2;

    m_topLeft = sf::Vector2f(startFromX, startFromY);
    m_bottomRight = sf::Vector2f(startFromX + m_boardWidth, startFromY + m_boardHeight);

    sf::Vector2f location(startFromX + col * OBJ_SIZE , startFromY + row * OBJ_SIZE);

    switch (letter)
    {
    case 'K':
    case 'k': 
        m_moveables.push_back(std::make_unique <King>(m_figures.getFigure(Figure(0)), location));
        break;

    case 'W':
    case 'w':
        m_moveables.push_back(std::make_unique <Warrior>(m_figures.getFigure(Figure(1)), location));
        break;

    case 'M':
    case 'm':
        m_moveables.push_back(std::make_unique <Mage>(m_figures.getFigure(Figure(2)), location));
        break;

    case 'T':
    case 't':
        m_moveables.push_back(std::make_unique <Thief>(m_figures.getFigure(Figure(3)), location));
        break;
        
    case '!':
        m_unmoveables.push_back(std::make_unique <Ork>(m_figures.getFigure(Figure(4)), location));
        break;

    case '=':        
        m_unmoveables.push_back(std::make_unique <Wall>(m_figures.getFigure(Figure(5)), location));
        break;

    case '*':       
        m_unmoveables.push_back(std::make_unique <Fire>(m_figures.getFigure(Figure(6)), location));
        break;

    case '#':       
        m_unmoveables.push_back(std::make_unique <Gate>(m_figures.getFigure(Figure(7)), location));
        break;

    case 'F':      
    case 'f':      
        m_unmoveables.push_back(std::make_unique <Key>(m_figures.getFigure(Figure(8)), location));
        break;

    case 'X':
    case 'x':
        m_unmoveables.push_back(std::make_unique <Teleporter>(m_figures.getFigure(Figure(9)), location));
        break;

    case '@':
        m_unmoveables.push_back(std::make_unique <Throne>(m_figures.getFigure(Figure(10)), location));
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
    static int i = 0;
    if (timePassed % 10 == 0 && timePassed > 0 && !m_isGift)
    {
        std::cout << "adding a gift!" << i++ << std::endl;
        m_isGift = true;
        switch (randomGift)
        {
        case 0:
            m_gifts.push_back(std::make_unique <GiftAddTime> (m_figures.getFigure(Figure(11)), getRandomPos()));
            break;

        case 1:
            m_gifts.push_back(std::make_unique <GiftRedTime>(m_figures.getFigure(Figure(11)), getRandomPos()));
            break;

        case 2:
            m_gifts.push_back(std::make_unique <GiftRmvDwarf>(m_figures.getFigure(Figure(11)), getRandomPos()));
            break;

        default:
            m_gifts.push_back(std::make_unique <GiftAddTime>(m_figures.getFigure(Figure(11)), getRandomPos()));
            break;
        }
    }
}

sf::Vector2f& Board::getRandomPos()
{
    int index = m_emptySlots.size();
    int randomPos = rand() % index;
    return *m_emptySlots[randomPos];
}

void Board::setIsGift()
{
    m_isGift = false;
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(m_gameBackGround);
    window.draw(m_frame);
    m_gameTime.draw(window);
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
}

void Board::movePlayer()
{
    sf::Vector2f direction(dirFromKey());
    auto deltaTime = m_moveables[m_playerIndex]->getDeltaTime();
    if (checkBoundsCollis(direction))
    {
        m_moveables[m_playerIndex]->move(direction, deltaTime);
    }
    
        
}

bool Board::checkBoundsCollis(sf::Vector2f& direction)
{
    sf::Vector2f playerPos = m_moveables[m_playerIndex]->getPos();
    
    if ((direction.x < 0 && playerPos.x < m_topLeft.x) ||
        (direction.y < 0 && playerPos.y < m_topLeft.y) ||
        (direction.x > 0 && playerPos.x > m_bottomRight.x - OBJ_SIZE) ||
        (direction.y > 0 && playerPos.y > m_bottomRight.y - OBJ_SIZE))
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
    for (auto& movable : m_moveables)
    {
        if (checkCollisions(*movable))
            return true;
    }
    
    teleportCollision();
    createKey();

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
            if (typeid(obj) == typeid(King) && typeid(*unmovable) == typeid(Throne))
                return true;
            obj.handleCollision(*unmovable);
        }
    }

    for (auto& gift : m_gifts)
    {
        if (obj.checkCollision(*gift))
            gift->handleCollision(obj, *this);
    }

    return false;
}

void Board::startTime()
{
    m_gameTime.startGameTime();
}

void Board::setTimer(bool statement)
{
    m_gameTime.setIsTimer(statement);
}


bool Board::handleTime()
{
    return m_gameTime.handleTime();
}

void Board::teleportCollision()
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

void Board::createKey()
{
    for (auto& unmovable : m_unmoveables)
    {
        if (typeid(*unmovable) == typeid(Ork) && unmovable->isDisposed())//static_cast?
            m_unmoveables.push_back(std::make_unique <Key>(m_figures.getFigure(Figure(8)), unmovable->getPos()));
    }
}

void Board::clearData()
{
    m_moveables.clear();
    m_unmoveables.clear();
    m_gifts.clear();
    m_emptySlots.clear();
    m_isGift = false;
    //m_gameTime.restartTimer(); ?
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
    //m_dwarf.clear(); ?
    return;
}