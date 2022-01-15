#include "Wall.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"


void Wall::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Wall::handleCollision(King& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Wall::handleCollision(Mage& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Wall::handleCollision(Warrior& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Wall::handleCollision(Thief& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

