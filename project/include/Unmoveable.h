#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "GameObj.h"


class Unmoveable : public GameObj
{
public:
	using GameObj::GameObj;

	virtual ~Unmoveable() = 0 {}
	//virtual void move();
	//virtual void handleCollis(const GameObj* object);
protected:

};