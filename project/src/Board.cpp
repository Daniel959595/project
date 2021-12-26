#include "Board.h"


//Board::Board()
//{
//
//}

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

    int moveIndex;
	for (int i = 0; i < matrix.size(); ++i)
		for (int j = 0; j < matrix[i].size(); ++j)
		{
            sf::Vector2f location(sf::Vector2f(0.0f, 10.0f));
            if (typeid(*getType(matrix[i][j])) == typeid(MoveAble))
            {
                //auto newObj = ;
               // auto newObj = ;
                //m_movebles.push_back(std::make_unique<King>(Figure::m_king, { 0, 0 }));
                m_moveAbles.push_back(std::make_unique <King>> (m_figures.getFigure(Figure(0)), { 0,0 }));
            }
		}
}

GameObj* Board::getType(char letter)
{
    switch (letter)
    {
    case 'K':
    case 'k':   
    case 'W':
    case 'w':
    case 'M':
    case 'm':
    case 'T':
    case 't':
        MoveAble * ptr;
        return ptr;
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
        MoveAble* ptr;
        return ptr;
        break;

    }
}


