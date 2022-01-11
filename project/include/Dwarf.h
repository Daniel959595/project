#pragma once

#include "Moveable.h"
#include "GameObj.h"

class Dwarf : public Moveable
{
public:
    using Moveable::Moveable;

    virtual void handleCollision(GameObj& gameObj) override;
    virtual void handleCollision(Wall& gameObj) override;
    virtual void handleCollision(Fire& gameObj) override;
    virtual void handleCollision(Ork& gameObj) override;
    virtual void handleCollision(Gate& gameObj) override;

    void handleCollision(King& gameObj);
    void handleCollision(Thief& gameObj); 
    void handleCollision(Mage& gameObj);
    void handleCollision(Warrior& gameObj);
 
    virtual void move(sf::Time& deltaTime) override;
    sf::Vector2f& changeDirection();

private:
    sf::Vector2f m_direction = { 1, 0 };
    float m_speed = 150.0f;

};




