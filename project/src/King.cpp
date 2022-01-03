#include "King.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Teleporter.h"
#include <iostream>

void King::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void King::handleCollision(Wall& gameObj)
{
	moveBack(gameObj);
}

void King::handleCollision(Fire& gameObj)
{
	moveBack(gameObj);
}

void King::handleCollision(Ork& gameObj)
{
	moveBack(gameObj);
}

void King::handleCollision(Gate& gameObj)
{
	moveBack(gameObj);
}

void King::handleCollision(Teleporter& gameObj)
{
	if (this->isTeleported())
		return;
	this->m_position = gameObj.getTwinPos();
	this->m_sprite.setPosition(m_position);
	this->set_isTeleported(true); //unnecessary!
}



