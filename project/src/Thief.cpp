#include "Thief.h"
#include "Board.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Teleporter.h"
#include "Dwarf.h"
#include "Gift.h"


void Thief::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Thief::handleCollision(Wall& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Thief::handleCollision(Fire& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Thief::handleCollision(Ork& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Thief::handleCollision(Gate& gameObj, Board& board)
{
	if (m_isHaveKey)
	{
		m_isHaveKey = false;
		board.setIsKey(false);
		return;
	}
	moveBack(gameObj);
}

void Thief::handleCollision(Teleporter& gameObj, Board& board)
{
	if (this->isTeleported())
		return;
	this->m_position = gameObj.getTwinPos();
	this->m_sprite.setPosition(m_position);
	this->set_isTeleported(true); //unnecessary!
	board.activateSounds(Sound::teleportSound);
}

void Thief::handleCollision(Key& gameObj, Board& board)
{
	m_isHaveKey = true;
	board.setIsKey(true);
}

void Thief::handleCollision(Dwarf& gameObj, Board& board)
{
	moveBack(gameObj);
}

void Thief::handleCollision(Gift& gameObj, Board& board)
{
	gameObj.handleCollision(*this, board);
}
