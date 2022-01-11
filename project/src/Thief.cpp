#include "Thief.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Teleporter.h"
#include "Dwarf.h"


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
	if (m_isHaveKey)
	{
		m_isHaveKey = false;
		return;
	}
	moveBack(gameObj);
}

void Thief::handleCollision(Teleporter& gameObj)
{
	if (this->isTeleported())
		return;
	this->m_position = gameObj.getTwinPos();
	this->m_sprite.setPosition(m_position);
	this->set_isTeleported(true); //unnecessary!
}

void Thief::handleCollision(Key& gameObj)
{
	m_isHaveKey = true;
}

void Thief::handleCollision(Dwarf& gameObj)
{
	std::cout << "thief and dwarf!\n";
	moveBack(gameObj);
}