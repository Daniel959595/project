#include "Mage.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Dwarf.h"


void Mage::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Mage::handleCollision(Wall& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Mage::handleCollision(Ork& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Mage::handleCollision(Gate& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Mage::handleCollision(Dwarf& gameObj, Board& board)
{
	moveBack(gameObj);
}