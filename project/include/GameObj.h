#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

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

class GameObj
{
public:
	GameObj(const sf::Texture& texture, const sf::Vector2f& position);
	virtual ~GameObj() = 0 {}

	void draw(sf::RenderWindow& window);
	bool checkCollision(const GameObj& other) const;

	virtual void handleCollision(GameObj& gameObj) {};
	virtual void handleCollision(Wall& gameObj) {};
	virtual void handleCollision(Fire& gameObj) {};
	virtual void handleCollision(Gate& gameObj) {};
	virtual void handleCollision(Teleporter& gameObj) {};
	//virtual void handleCollision(Throne& gameObj);
	virtual void handleCollision(Ork& gameObj) {};
	virtual void handleCollision(King& gameObj) {};
	virtual void handleCollision(Thief& gameObj) {};
	virtual void handleCollision(Mage& gameObj) {};
	virtual void handleCollision(Warrior& gameObj) {};
	//virtual void handleCollision(Dwarf& gameObj);

	float getLeftBounds();
	float getWidth();
	float getTopBounds();
	float getHeight();
	sf::Vector2f getPos() { return m_position; }
	bool isDisposed() const;

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;

	bool m_isDisposed = false;

};