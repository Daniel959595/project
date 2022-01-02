#include "Warrior.h"
#include "Wall.h"
#include "Fire.h"
#include "Gate.h"


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
