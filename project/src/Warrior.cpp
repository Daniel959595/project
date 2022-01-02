#include "Warrior.h"
#include "Wall.h"
#include "Fire.h"
#include "Gate.h"
#include "Teleporter.h"


void Warrior::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Warrior::handleCollision(Wall& gameObj)
{
	moveBack(gameObj);
}

void Warrior::handleCollision(Fire& gameObj)
{
	moveBack(gameObj);
}

//void Warrior::handleCollision(Ork& gameObj)
//{
//	moveBack(gameObj);
//}

void Warrior::handleCollision(Gate& gameObj)
{
	moveBack(gameObj);
}

void Warrior::handleCollision(Teleporter& gameObj)
{
	m_position = gameObj.getTwinPos();
	this->m_sprite.setPosition(m_position);
}
