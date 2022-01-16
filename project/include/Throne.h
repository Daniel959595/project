#pragma once

#include <SFML/Graphics.hpp>
#include "Unmoveable.h"


class Throne : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;
	virtual void handleCollision(King& gameObj, Board& board) override;

};
