#pragma once

#include "Gift.h"

class GiftAddTime : public Gift
{
public:
	using Gift::Gift;

	void activateGift(Board& board);

	virtual void handleCollision(GameObj& gameObj, Board& board);
	virtual void handleCollision(King& gameObj, Board& board);
	virtual void handleCollision(Thief& gameObj, Board& board);
	virtual void handleCollision(Mage& gameObj, Board& board);
	virtual void handleCollision(Warrior& gameObj, Board& board);
};