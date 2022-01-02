#include "Thief.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Teleporter.h"


void Thief::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Thief::handleCollision(Wall& gameObj)
{
	moveBack(gameObj);
}

void Thief::handleCollision(Fire& gameObj)
{
	moveBack(gameObj);
}

void Thief::handleCollision(Ork& gameObj)
{
	moveBack(gameObj);
}

void Thief::handleCollision(Gate& gameObj)
{
	moveBack(gameObj);
}

void Thief::handleCollision(Teleporter& gameObj)
{
	m_position = gameObj.getTwinPos();
	this->m_sprite.setPosition(m_position);
}
