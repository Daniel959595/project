#pragma once

#include "Unmoveable.h"
#include "Moveable.h"

class Board;

class Gift : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;
	virtual ~Gift() = 0 {}

	//virtual void activateGift(Board& board) {};
	bool handleGiftLife(); //delete the gift after a constant time and return true if deleted.

	virtual void handleCollision(GameObj& gameObj, Board& board) {}
	virtual void handleCollision(King& gameObj, Board& board) {}
	virtual void handleCollision(Thief& gameObj, Board& board) {}
	virtual void handleCollision(Mage& gameObj, Board& board) {}
	virtual void handleCollision(Warrior& gameObj, Board& board) {}

private:
	sf::Clock m_clock;
	int m_lifetime = 15;

};