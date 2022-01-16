#include "GiftAddTime.h"
#include "Board.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

void GiftAddTime::activateGift(Board& board)
{
	board.addTime();
}

void GiftAddTime::handleCollision(GameObj& gameObj, Board& board)
{
	/*m_isDisposed = true;
	board.setIsGift();
	activateGift(board);*/
	gameObj.handleCollision(*this, board);
}

void GiftAddTime::handleCollision(King& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}

void GiftAddTime::handleCollision(Mage& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}

void GiftAddTime::handleCollision(Warrior& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);

}

void GiftAddTime::handleCollision(Thief& gameObj, Board& board)
{
	m_isDisposed = true;
	board.setIsGift();
	activateGift(board);
}