#pragma once

#include <SFML/Graphics.hpp>
#include "Unmoveable.h"


class Teleporter : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;
	
	virtual void handleCollision(GameObj& gameObj) override;
	virtual void handleCollision(King& gameObj) override;
	virtual void handleCollision(Thief& gameObj) override;
	virtual void handleCollision(Mage& gameObj) override;
	virtual void handleCollision(Warrior& gameObj) override;
	
	virtual sf::Vector2f getTwinPos() override;
	virtual void setTwinPos(sf::Vector2f position) { m_twinPos = position; }

private:
	sf::Vector2f m_twinPos;

};
