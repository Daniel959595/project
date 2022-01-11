#include "Gift.h"
//#include "King.h"
//#include "Mage.h"
//#include "Warrior.h"
//#include "Thief.h"
//
//void Gift::handleCollision(GameObj& gameObj, Board& board)
//{
////	gameObj.handleCollision(*this);
//	return;
//}
//
bool Gift::handleGiftLife()
{
	if (m_lifetime - m_clock.getElapsedTime().asSeconds() <= 0)
	{
		m_isDisposed = true;
		return true;
	}
	return false;
}

//void Gift::handleCollision(King& gameObj, Board& board)
//{
//	m_isDisposed = true;
//	activateGift(board);
//}
//
//void Gift::handleCollision(Mage& gameObj, Board& board)
//{
//	m_isDisposed = true;
//	activateGift(board);
//}
//
//void Gift::handleCollision(Warrior& gameObj, Board& board)
//{
//	m_isDisposed = true;
//	activateGift(board);
//
//}
//
//void Gift::handleCollision(Thief& gameObj, Board& board)
//{
//	m_isDisposed = true;
//	activateGift(board);
//}