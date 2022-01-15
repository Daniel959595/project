#include "King.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Dwarf.h"
#include "Teleporter.h"
#include <iostream>

void King::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void King::handleCollision(Wall& gameObj, Board& board)
{
	moveBack(gameObj);
}

void King::handleCollision(Fire& gameObj, Board& board)
{
	moveBack(gameObj);
}

void King::handleCollision(Ork& gameObj, Board& board)
{
	moveBack(gameObj);
}

void King::handleCollision(Gate& gameObj, Board& board)
{
	moveBack(gameObj);
}

void King::handleCollision(Teleporter& gameObj, Board& board)
{
	if (this->isTeleported()) return;

	this->m_position = gameObj.getTwinPos();
	this->m_sprite.setPosition(m_position);
	this->set_isTeleported(true); //unnecessary!
}

void King::handleCollision(Dwarf& gameObj, Board& board)
{
	//gameObj.handleCollision(*this);
	moveBack(gameObj);
}




