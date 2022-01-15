#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "ObjectSounds.h"

class Board;
class King;
class Warrior;
class Mage;
class Thief;
class Key;
class Fire;
class Teleporter;
class Wall;
class Gate;
class Ork;
class Throne;
class Dwarf;


class GameObj
{
public:
	GameObj(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~GameObj() = 0 {}

	void draw(sf::RenderWindow& window);
	bool checkCollision(const GameObj& other) const;

	virtual void handleCollision(GameObj& gameObj, Board& board) {};
	virtual void handleCollision(King& gameObj, Board& board) {};
	virtual void handleCollision(Thief& gameObj, Board& board) {};
	virtual void handleCollision(Mage& gameObj, Board& board) {};
	virtual void handleCollision(Warrior& gameObj, Board& board) {};
	virtual void handleCollision(Wall& gameObj, Board& board) {};
	virtual void handleCollision(Fire& gameObj, Board& board) {};
	virtual void handleCollision(Gate& gameObj, Board& board) {};
	virtual void handleCollision(Teleporter& gameObj, Board& board) {};
	virtual void handleCollision(Ork& gameObj, Board& board) {};
	virtual void handleCollision(Key& gameObj, Board& board) {};
	virtual void handleCollision(Dwarf& gameObj, Board& board) {};

	float getLeftBounds();
	float getWidth();
	float getTopBounds();
	float getHeight();
	sf::Vector2f getPos() { return m_sprite.getPosition(); }
	bool isDisposed() const;

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;

	//ObjectSounds m_sounds;
	
	bool m_isDisposed = false;

};