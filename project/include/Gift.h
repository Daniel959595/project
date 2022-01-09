#pragma once

#include "Board.h"
#include "Unmoveable.h"
#include "Moveable.h"

class Gift : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;
	virtual ~Gift() = 0 {}

	virtual void activateGift(Board& board) {};

    void handleCollision(Moveable& gameObj) ;
};