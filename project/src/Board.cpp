#include "Board.h"
#include <iostream>
const float size = 50;


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

	for (int row = 0; row < matrix.size(); ++row)
		for (int col = 0; col < matrix[row].size(); ++col)
		{
            if (matrix[row][col] == ' ')
                continue;
            loadVectors(matrix[row][col], float(row), float(col));
		}
    setTeleportTwins();
}

void Board::loadVectors(char letter, float row, float col)
{

    sf::Vector2f location(col * size, row * size);

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


void Board::draw(sf::RenderWindow& window)
{
    for (auto &index : m_moveables)
    {
        index->draw(window);
    }

    for (auto& index : m_unmoveables)
    {
        index->draw(window);
    }
}

void Board::movePlayer()
{
    m_moveables[m_playerIndex]->move();
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
    return false;
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
}