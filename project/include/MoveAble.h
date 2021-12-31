#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "GameObj.h"


class Moveable : public GameObj
{
public:
	using GameObj::GameObj;
	virtual ~Moveable() = 0 {}

	//virtual void move(sf::Time& deltaTime);
	virtual void move();
	virtual void moveBack() {};
	//virtual void handleCollis(const GameObj* object);

private:
    static sf::Clock m_clock; //etemept!!

	float m_speed = 150.0f;
};

