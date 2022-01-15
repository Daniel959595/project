#pragma once

#include "Gift.h"

class GiftRmvDwarf : public Gift
{
public:
	using Gift::Gift;

	void activateGift(Board& board);

	virtual void handleCollision(GameObj& gameObj, Board& board) override;
	virtual void handleCollision(King& gameObj, Board& board) override;
	virtual void handleCollision(Thief& gameObj, Board& board) override;
	virtual void handleCollision(Mage& gameObj, Board& board) override;
	virtual void handleCollision(Warrior& gameObj, Board& board) override;
};