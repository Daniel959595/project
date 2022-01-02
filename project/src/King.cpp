#include "King.h"
#include "Wall.h"
#include <iostream>

void King::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this);
}

void King::handleCollision(Wall& gameObj)
{
	//std::cout << "king collis wall!\n";
	moveBack(gameObj);
}


