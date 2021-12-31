#include "Board.h"
#include <iostream>
const float size = 50;

//Board::Board()
//{
//
//}

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

//void Board::movePlayer(sf::Time& deltaTime)
//{
//    m_moveables[m_playerIndex]->move(deltaTime);
//}

void Board::movePlayer()
{
    m_moveables[m_playerIndex]->move();
}

void Board::setPlayer()
{
    static int i = 0;
    m_playerIndex = (i++)%4;
    if (i > 3)
        i = 0;
}

void Board::handleCollisions()
{
    for (auto& movable : m_moveables)
    {
        checkCollisions(*movable);
    }

    /*for (auto& unmovable : m_unmoveables)
    {
        if (gameObject.checkCollision(*unmovable))
        {
            gameObject.handleCollision(*unmovable);
        }
    }*/
}

void Board::checkCollisions(Moveable& obj)
{
    for (auto& unmovable : m_unmoveables)
    {
        if (obj.checkCollision(*unmovable))
        {
            //obj.check(other);
            obj.handleCollision(*unmovable);
        }
    }

    /*for (auto& unmovable : m_unmoveables)
    {
        if (obj.get_sprite().getGlobalBounds().intersects((*unmovable).get_sprite().getGlobalBounds()))
        {
            gameObject.handleCollision(*unmovable);
        }
    }*/
}

