#include "Key.h"
#include "Thief.h"


void Key::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Key::handleCollision(Thief& gameObj, Board& board)
{
	if (gameObj.isHaveKey())
		return;
	m_isDisposed = true;
	gameObj.handleCollision(*this, board);
}