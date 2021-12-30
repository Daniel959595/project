#pragma once

#include <SFML/Graphics.hpp>
#include "Moveable.h"
#include "GameObj.h"


class King : public Moveable
{
public:
	using Moveable::Moveable;

    void handleCollision(GameObj& gameObj) override;
    void handleCollision(Wall& gameObj) override;
};




