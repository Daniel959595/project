#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "GameObj.h"


class Moveable : public GameObj
{
public:
	using GameObj::GameObj;
	virtual ~Moveable() = 0 {}

	sf::Time getDeltaTime() { return m_clock.restart(); }
	virtual void move(sf::Vector2f& direction, sf::Time& deltaTime);
	virtual void moveBack(GameObj& other);
	void set_isTeleported(bool statement) { m_isTeleported = statement; }
	bool isTeleported() { return m_isTeleported; }

private:
    static sf::Clock m_clock;
	//sf::Vector2f m_direction = { 0, 0 };
	float m_speed = 150.0f;
	bool m_isTeleported = false;
};

