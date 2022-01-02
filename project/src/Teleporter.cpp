#include "Teleporter.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"


void Teleporter::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Teleporter::handleCollision(King& gameObj)
{
	gameObj.handleCollision(*this);
}

void Teleporter::handleCollision(Mage& gameObj)
{
	//gameObj.handleCollision(*this);
}

void Teleporter::handleCollision(Warrior& gameObj)
{
	gameObj.handleCollision(*this);
}

void Teleporter::handleCollision(Thief& gameObj)
{
	gameObj.handleCollision(*this);
}

sf::Vector2f Teleporter::getTwinPos()
{
	return m_twinPos;
}
