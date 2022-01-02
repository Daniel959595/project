#pragma once

#include <SFML/Graphics.hpp>
#include "Moveable.h"


class Thief : public Moveable
{
public:
	using Moveable::Moveable;

	virtual void handleCollision(GameObj& gameObj) override;
	virtual void handleCollision(Wall& gameObj) override;
	virtual void handleCollision(Fire& gameObj) override;
	virtual void handleCollision(Ork& gameObj) override;
	virtual void handleCollision(Gate& gameObj) override;
	virtual void handleCollision(Teleporter& gameObj) override;

	bool isKey() const { return m_isKey; }

private:
	bool m_isKey = false;

};




