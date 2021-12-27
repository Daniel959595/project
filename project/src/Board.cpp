#include "Board.h"

const int size = 50;

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
            loadVectors(matrix[row][col], row, col);
		}
}

void Board::loadVectors(char letter, int row, int col)
{
    sf::Vector2f location(col * size, row * size);

    switch (letter)
    {
    case 'K':
    case 'k': 
        m_moveAbles.push_back(std::make_unique <King>(m_figures.getFigure(Figure(0)), location));
        break;

    case 'W':
    case 'w':
        m_moveAbles.push_back(std::make_unique <Warrior>(m_figures.getFigure(Figure(1)), location));
        break;

    case 'M':
    case 'm':
        m_moveAbles.push_back(std::make_unique <Mage>(m_figures.getFigure(Figure(2)), location));
        break;

    case 'T':
    case 't':
        m_moveAbles.push_back(std::make_unique <Thief>(m_figures.getFigure(Figure(3)), location));
        break;
        
  /*  case '!':
    case '=':        
    case '*':       
    case '#':       
    case 'F':      
    case 'X':
    case 'x':        
    case '@':*/
        
    default:
        m_moveAbles.push_back(std::make_unique <King>(m_figures.getFigure(Figure(0)), location));
        break;

    }
}


