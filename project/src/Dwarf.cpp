#include <vector>
#include <stdlib.h>
#include <iostream>

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

void Dwarf::changeDirection()
{
	static std::vector <sf::Vector2f> directions { {0,1},{-1,0},
		                                           {0,-1},{1,0} };
	int index = rand() % 4;
	m_direction = directions[index];
}


void Dwarf::handleCollision(GameObj& gameObj)
{
	if (&gameObj == this) return; //?
	moveBack(gameObj);
	changeDirection();
	// double dispatch
	gameObj.handleCollision(*this);
}

void Dwarf::handleCollision(Wall& gameObj)
{
	moveBack(gameObj);
	changeDirection();
}

void Dwarf::handleCollision(Fire& gameObj)
{
	changeDirection();
}

void Dwarf::handleCollision(Ork& gameObj)
{
	changeDirection();
}

void Dwarf::handleCollision(Gate& gameObj)
{
    changeDirection();
}

void Dwarf::handleCollision(King& gameObj)
{
	changeDirection();

	gameObj.handleCollision(*this);
}

void Dwarf::handleCollision(Thief& gameObj)
{
	changeDirection();

	gameObj.handleCollision(*this);
}

void Dwarf::handleCollision(Warrior& gameObj)
{
	changeDirection();

	gameObj.handleCollision(*this);
}

void Dwarf::handleCollision(Mage& gameObj)
{
	changeDirection();

	gameObj.handleCollision(*this);
}
