#include "Wall.h"
#include "King.h"

#include <iostream>

void Wall::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void Wall::handleCollision(King& gameObj)
{
	gameObj.handleCollision(*this);
}

//void Wall::handleCollision(Warrior& gameObj)
//{
//	gameObj.handleCollision(*this);
//}
//
//void Wall::handleCollision(Mage& gameObj)
//{
//	gameObj.handleCollision(*this);
//}
//
//void Wall::handleCollision(Thief& gameObj)
//{
//	gameObj.handleCollision(*this);
//}
