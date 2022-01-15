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


void Dwarf::handleCollision(GameObj& gameObj, Board& board)
{
	if (&gameObj == this) return; 

	if (typeid(gameObj) != typeid(King) &&
		typeid(gameObj) != typeid(Mage) &&
		typeid(gameObj) != typeid(Thief) &&
		typeid(gameObj) != typeid(Warrior))
		moveBack(gameObj);   ///func

	changeDirection();
	// double dispatch
	gameObj.handleCollision(*this, board);
}

void Dwarf::handleCollision(Wall& gameObj, Board& board)
{
	moveBack(gameObj);
	changeDirection();
}

void Dwarf::handleCollision(Fire& gameObj, Board& board)
{
	changeDirection();
}

void Dwarf::handleCollision(Ork& gameObj, Board& board)
{
	changeDirection();
}

void Dwarf::handleCollision(Gate& gameObj, Board& board)
{
    changeDirection();
}

void Dwarf::handleCollision(King& gameObj, Board& board)
{
	changeDirection();

	gameObj.handleCollision(*this, board);
}

void Dwarf::handleCollision(Thief& gameObj, Board& board)
{
	changeDirection();

	gameObj.handleCollision(*this, board);
}

void Dwarf::handleCollision(Warrior& gameObj, Board& board)
{
	changeDirection();

	gameObj.handleCollision(*this, board);
}

void Dwarf::handleCollision(Mage& gameObj, Board& board)
{
	changeDirection();

	gameObj.handleCollision(*this, board);
}
