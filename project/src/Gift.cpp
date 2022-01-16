#include "Gift.h"

bool Gift::handleGiftLife()
{
	if (m_lifetime - m_clock.getElapsedTime().asSeconds() <= 0)
	{
		m_isDisposed = true;
		return true;
	}
	return false;
}

