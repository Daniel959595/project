#include "Warrior.h"
#include "Board.h"
#include "Wall.h"
#include "Fire.h"
#include "Gate.h"
#include "Dwarf.h"
#include "Teleporter.h"
#include "Gift.h"


void Warrior::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Warrior::handleCollision(Wall& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Warrior::handleCollision(Fire& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Warrior::handleCollision(Gate& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Warrior::handleCollision(Teleporter& gameObj, Board& board)
{
	if (this->isTeleported())
		return;
	this->m_position = gameObj.getTwinPos();
	this->m_sprite.setPosition(m_position);
	this->set_isTeleported(true); //unnecessary!
	board.activateSounds(Sound::teleportSound);
}

void Warrior::handleCollision(Dwarf& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Warrior::handleCollision(Gift& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}
