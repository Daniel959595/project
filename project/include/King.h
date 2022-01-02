#pragma once

#include <SFML/Graphics.hpp>
#include "Moveable.h"
#include "GameObj.h"


class King : public Moveable
{
public:
	using Moveable::Moveable;

    virtual void handleCollision(GameObj& gameObj) override;
    virtual void handleCollision(Wall& gameObj) override;
    virtual void handleCollision(Fire& gameObj) override;
    virtual void handleCollision(Ork& gameObj) override;
    virtual void handleCollision(Gate& gameObj) override;
    virtual void handleCollision(Teleporter& gameObj) override;

};




