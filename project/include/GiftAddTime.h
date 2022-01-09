#pragma once

#include "Gift.h"

class GiftAddTime : public Gift
{
public:
	using Gift::Gift;

	virtual void activateGift(Board& board) override;
};