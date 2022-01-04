#include "Key.h"
#include "Thief.h"


void Key::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Key::handleCollision(Thief& gameObj)
{
	if (gameObj.isHaveKey())
		return;
	m_isDisposed = true;
	gameObj.handleCollision(*this);
}