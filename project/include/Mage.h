#pragma once

#include <SFML/Graphics.hpp>
#include "Moveable.h"


class Mage : public Moveable
{
public:
	using Moveable::Moveable;

	virtual void handleCollision(GameObj& gameObj, Board& board) override;
	virtual void handleCollision(Wall& gameObj, Board& board) override;
	virtual void handleCollision(Ork& gameObj, Board& board) override;
	virtual void handleCollision(Gate& gameObj, Board& board) override;
	virtual void handleCollision(Dwarf& gameObj, Board& board) override;
	virtual void handleCollision(Gift& gameObj, Board& board) override;

};




