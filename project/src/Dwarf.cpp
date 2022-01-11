#include <vector>
#include <stdlib.h>

#include "Dwarf.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Teleporter.h"


void Dwarf::move(sf::Time& deltaTime)
{
	m_sprite.move(m_direction * m_speed * deltaTime.asSeconds());
}

sf::Vector2f& Dwarf::changeDirection()
{
	static std::vector <sf::Vector2f> directions { {0,1},{-1,0},
		                                           {0,-1},{1,0} };
	int index = rand() % 4;
	return directions[index];
}


void Dwarf::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return;
	changeDirection();
	// double dispatch
	//gameObj.handleCollision(*this);
}

void Dwarf::handleCollision(Wall& gameObj)
{
	m_direction = changeDirection();
}

void Dwarf::handleCollision(Fire& gameObj)
{
	m_direction = changeDirection();
}

void Dwarf::handleCollision(Ork& gameObj)
{
	m_direction = changeDirection();
}

void Dwarf::handleCollision(Gate& gameObj)
{
	m_direction = changeDirection();
}

void Dwarf::handleCollision(King& gameObj)
{
	m_direction = changeDirection();

	gameObj.handleCollision(*this);
}

void Dwarf::handleCollision(Thief& gameObj)
{
	m_direction = changeDirection();

	gameObj.handleCollision(*this);
}

void Dwarf::handleCollision(Warrior& gameObj)
{
	m_direction = changeDirection();

	gameObj.handleCollision(*this);
}

void Dwarf::handleCollision(Mage& gameObj)
{
	m_direction = changeDirection();

	gameObj.handleCollision(*this);
}
