#include "Gate.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"


void Gate::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Gate::handleCollision(King& gameObj)
{
	gameObj.handleCollision(*this);
}

void Gate::handleCollision(Mage& gameObj)
{
	gameObj.handleCollision(*this);
}

void Gate::handleCollision(Warrior& gameObj)
{
	gameObj.handleCollision(*this);
}

void Gate::handleCollision(Thief& gameObj)
{
	if (gameObj.isHaveKey())
	{
		m_isDisposed = true;
	}
	gameObj.handleCollision(*this);
}

