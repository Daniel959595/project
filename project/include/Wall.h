#pragma once

#include <SFML/Graphics.hpp>
#include "Unmoveable.h"




class Wall : public Unmoveable
{
public:
	using Unmoveable::Unmoveable;

	virtual void handleCollision(King& gameObj) override;


};
