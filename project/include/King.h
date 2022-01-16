#pragma once

#include <SFML/Graphics.hpp>
#include "Moveable.h"
#include "GameObj.h"


class King : public Moveable
{
public:
	using Moveable::Moveable;

    //virtual bool checkCollision(const GameObj& other) ;

    virtual void handleCollision(GameObj& gameObj, Board& board) override;
    virtual void handleCollision(Wall& gameObj, Board& board) override;
    virtual void handleCollision(Fire& gameObj, Board& board) override;
    virtual void handleCollision(Ork& gameObj, Board& board) override;
    virtual void handleCollision(Gate& gameObj, Board& board) override;
    virtual void handleCollision(Teleporter& gameObj, Board& board) override;
    virtual void handleCollision(Dwarf& gameObj, Board& board) override;
    virtual void handleCollision(Throne& gameObj, Board& board) override;
    virtual void handleCollision(Gift& gameObj, Board& board) override;

    bool isReachThrone() { return m_reachThrone; }
private:
    bool m_reachThrone = false;

};




