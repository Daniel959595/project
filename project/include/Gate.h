#pragma once

#include "Unmoveable.h"


class Gate : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;

	//virtual void handleCollision(GameObj& gameObj) override;
	virtual void handleCollision(King& gameObj) override;
	virtual void handleCollision(Thief& gameObj) override;
	virtual void handleCollision(Mage& gameObj) override;
	virtual void handleCollision(Warrior& gameObj) override;

};
