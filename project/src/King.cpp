#include "King.h"
#include "Board.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Dwarf.h"
//#include "Teleporter.h"
#include <iostream>

//bool King::checkCollision(const GameObj& other) 
//{
//	if (typeid(other) == typeid(Teleporter))
//		this->Moveable::set_isTeleported(true);
//}

void King::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return;
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void King::handleCollision(Wall& gameObj, Board& board)
{
	moveBack(gameObj);
}

void King::handleCollision(Fire& gameObj, Board& board)
{
	moveBack(gameObj);
}

void King::handleCollision(Ork& gameObj, Board& board)
{
	moveBack(gameObj);
}

void King::handleCollision(Gate& gameObj, Board& board)
{
	moveBack(gameObj);
}

void King::handleCollision(Teleporter& gameObj, Board& board)
{
	if (this->isTeleported()) return;

	this->m_position = gameObj.getTwinPos();
	this->m_sprite.setPosition(m_position);
	this->set_isTeleported(true); //unnecessary!
	board.activateSounds(Sound::teleportSound);
}

void King::handleCollision(Dwarf& gameObj, Board& board)
{
	//gameObj.handleCollision(*this);
	moveBack(gameObj);
}

void King::handleCollision(Throne& gameObj, Board& board)
{
	board.setIsWin();
}



