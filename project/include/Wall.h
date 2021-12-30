#pragma once

#include <SFML/Graphics.hpp>
#include "Unmoveable.h"
#include "GameObj.h"





class Wall : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;

	virtual void handleCollision(GameObj& gameObj) override;
	virtual void handleCollision(King& gameObj) override;


};
