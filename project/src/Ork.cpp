#include "Ork.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"


void Ork::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Ork::handleCollision(King& gameObj)
{
	gameObj.handleCollision(*this);
}

void Ork::handleCollision(Mage& gameObj)
{
	gameObj.handleCollision(*this);
}

void Ork::handleCollision(Warrior& gameObj)
{
	m_isDisposed = true;
	//gameObj.handleCollision(*this);
}

void Ork::handleCollision(Thief& gameObj)
{
	gameObj.handleCollision(*this);
}

