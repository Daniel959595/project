#pragma once

#include "Moveable.h"
#include "GameObj.h"

class Dwarf : public Moveable
{
public:
    using Moveable::Moveable;

    //virtual void handleCollision(GameObj& gameObj) override;
    virtual void handleCollision(Wall& gameObj, Board& board) override;
    virtual void handleCollision(Fire& gameObj, Board& board) override;
    virtual void handleCollision(Ork& gameObj, Board& board) override;
    virtual void handleCollision(Gate& gameObj, Board& board) override;

    virtual void handleCollision(GameObj& gameObj, Board& board) override;
    virtual void handleCollision(King& gameObj, Board& board) override;
    virtual void handleCollision(Thief& gameObj, Board& board) override;
    virtual void handleCollision(Mage& gameObj, Board& board) override;
    virtual void handleCollision(Warrior& gameObj, Board& board) override;
    virtual void move(sf::Time& deltaTime) override;
    sf::Vector2f& getDirection() { return m_direction; }
    void changeDirection();

private:
    sf::Vector2f m_direction = { 1, 0 };
    float m_speed = 100.0f;

};




