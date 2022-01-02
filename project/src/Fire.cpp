#include "Fire.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

#include <iostream>

void Fire::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Fire::handleCollision(King& gameObj)
{
	gameObj.handleCollision(*this);
}

void Fire::handleCollision(Mage& gameObj)
{
	m_isDisposed = true;
//	gameObj.handleCollision(*this);
}

void Fire::handleCollision(Warrior& gameObj)
{
	gameObj.handleCollision(*this);
}

void Fire::handleCollision(Thief& gameObj)
{
	gameObj.handleCollision(*this);
}