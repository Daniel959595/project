#include "King.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"

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



