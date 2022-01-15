#include "Teleporter.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"


void Teleporter::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Teleporter::handleCollision(King& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Teleporter::handleCollision(Mage& gameObj, Board& board)
{
	//gameObj.handleCollision(*this);
}

void Teleporter::handleCollision(Warrior& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Teleporter::handleCollision(Thief& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

sf::Vector2f Teleporter::getTwinPos()
{
	return m_twinPos;
}
