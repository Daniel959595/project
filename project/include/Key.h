#pragma once

#include <SFML/Graphics.hpp>
#include "Unmoveable.h"


class Key : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;

	virtual void handleCollision(GameObj& gameObj, Board& board) override;
	virtual void handleCollision(Thief& gameObj, Board& board) override;

};
