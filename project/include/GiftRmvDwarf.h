#pragma once

#include "Gift.h"

class GiftRmvDwarf : public Gift
{
public:
	using Gift::Gift;

	virtual void activateGift(Board& board) override;
};