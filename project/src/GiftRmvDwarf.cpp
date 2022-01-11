#include "GiftRmvDwarf.h"
#include "Board.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

void GiftRmvDwarf::activateGift(Board& board)
{
	board.rmvDwarf();
}

void GiftRmvDwarf::handleCollision(GameObj& gameObj, Board& board)
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

void GiftRmvDwarf::handleCollision(King& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}

void GiftRmvDwarf::handleCollision(Mage& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}

void GiftRmvDwarf::handleCollision(Warrior& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);

}

void GiftRmvDwarf::handleCollision(Thief& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}

