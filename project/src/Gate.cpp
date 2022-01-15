#include "Gate.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"


//void Gate::handleCollision(GameObj& gameObj)
//{
//	if (&gameObj == this) return;
//	// double dispatch
//	gameObj.handleCollision(*this);
//}

void Gate::handleCollision(King& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Gate::handleCollision(Mage& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Gate::handleCollision(Warrior& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Gate::handleCollision(Thief& gameObj, Board& board)
{
	if (gameObj.isHaveKey())
	{
		m_isDisposed = true;
	}
	gameObj.handleCollision(*this, board);
}

