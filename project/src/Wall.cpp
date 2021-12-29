#include "Wall.h"

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
