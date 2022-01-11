#include "GiftRedTime.h"
#include "Board.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

void GiftRedTime::activateGift(Board& board)
{
	board.redTime();
}

void GiftRedTime::handleCollision(GameObj& gameObj, Board& board)
{
	//	gameObj.handleCollision(*this);
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);

	return;
}

//void Gift::handleGiftLife()
//{
//	if (m_lifetime - m_clock.getElapsedTime().asSeconds() <= 0)
//		m_isDisposed = true;
//}

void GiftRedTime::handleCollision(King& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}

void GiftRedTime::handleCollision(Mage& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}

void GiftRedTime::handleCollision(Warrior& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);

}

void GiftRedTime::handleCollision(Thief& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}

