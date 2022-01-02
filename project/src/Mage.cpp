#include "Mage.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Teleporter.h"


void Mage::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Mage::handleCollision(Wall& gameObj)
{
	moveBack(gameObj);
}

//void Mage::handleCollision(Fire& gameObj)
//{
//	moveBack(gameObj);
//}

void Mage::handleCollision(Ork& gameObj)
{
	moveBack(gameObj);
}

void Mage::handleCollision(Gate& gameObj)
{
	moveBack(gameObj);
}

//void Mage::handleCollision(Teleporter& gameObj)
//{
//	m_position = gameObj.getTwinPos();
//}