#include "Gate.h"
#include "Board.h"
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
	board.activateSounds(Sound::knockSound);
}

void Gate::handleCollision(Mage& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
	board.activateSounds(Sound::knockSound);
}

void Gate::handleCollision(Warrior& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
	board.activateSounds(Sound::knockSound);
}

void Gate::handleCollision(Thief& gameObj, Board& board)
{
	if (gameObj.isHaveKey())
	{
		m_isDisposed = true;
		board.activateSounds(Sound::doorOpenSound);
	}
	else
		board.activateSounds(Sound::knockSound);

	gameObj.handleCollision(*this, board);
}

