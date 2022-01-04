#pragma once

#include <SFML/Graphics.hpp>
#include "Unmoveable.h"


class Key : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;

	virtual void handleCollision(GameObj& gameObj) override;
	virtual void handleCollision(Thief& gameObj) override;

};
