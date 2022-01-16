#include "Throne.h"
#include "King.h"

void Throne::handleCollision(King& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}
