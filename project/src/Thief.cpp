#include "Thief.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"


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
