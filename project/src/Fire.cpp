#include "Fire.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

#include <iostream>

void Fire::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Fire::handleCollision(King& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Fire::handleCollision(Mage& gameObj, Board& board)
{
	m_isDisposed = true;
	//m_sounds.activateSound(Sound(3));
}

void Fire::handleCollision(Warrior& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}

void Fire::handleCollision(Thief& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}