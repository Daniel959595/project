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
	virtual void handleCollision(Key& gameObj) override;

	bool isHaveKey() const { return m_isHaveKey; }

private:
	bool m_isHaveKey = false;

};




