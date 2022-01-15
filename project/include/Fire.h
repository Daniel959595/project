#pragma once

#include <SFML/Graphics.hpp>
#include "Unmoveable.h"


class Fire : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;

	virtual void handleCollision(GameObj& gameObj, Board& board) override;
	virtual void handleCollision(King& gameObj, Board& board) override;
	virtual void handleCollision(Thief& gameObj, Board& board) override;
	virtual void handleCollision(Mage& gameObj, Board& board) override;
	virtual void handleCollision(Warrior& gameObj, Board& board) override;
};
