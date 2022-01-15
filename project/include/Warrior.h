#pragma once

#include <SFML/Graphics.hpp>
#include "Moveable.h"


class Warrior : public Moveable
{
public:
	using Moveable::Moveable;

	virtual void handleCollision(GameObj& gameObj, Board& board) override;
	virtual void handleCollision(Wall& gameObj, Board& board) override;
	virtual void handleCollision(Fire& gameObj, Board& board) override;
	virtual void handleCollision(Gate& gameObj, Board& board) override;
	virtual void handleCollision(Teleporter& gameObj, Board& board) override;
	virtual void handleCollision(Dwarf& gameObj, Board& board) override;

};




