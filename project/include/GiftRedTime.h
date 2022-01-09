#pragma once

#include "Gift.h"

class GiftRedTime : public Gift
{
public:
	using Gift::Gift;

	virtual void activateGift(Board& board) override;
};