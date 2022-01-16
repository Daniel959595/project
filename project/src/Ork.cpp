#include "Ork.h"
#include "Board.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"


void Ork::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Ork::handleCollision(King& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
	board.activateSounds(Sound::trollRoarSound);
}

void Ork::handleCollision(Mage& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
	board.activateSounds(Sound::trollRoarSound);
}

void Ork::handleCollision(Warrior& gameObj, Board& board)
{
	m_isDisposed = true;
	board.createKey(*this);
	//gameObj.handleCollision(*this);
}

void Ork::handleCollision(Thief& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
	board.activateSounds(Sound::trollRoarSound);
}

