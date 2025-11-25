 #pragma once

#include "ConstMembers.h"
#include "Resources.h"
#include "SoundResources.h"

#include <SFML/Graphics.hpp>

class Mouse;
class Cat;
class Wall;
class Cheese;
class Key;
class Door;
class Present;

class GameObjects
{
public:
	GameObjects(Vertex, Size);
	virtual ~GameObjects() = default;

	//get
	virtual sf::Vector2f getLocation() const;
	virtual Size getSize() const;
	virtual sf::Sprite& getSprite();

	//set
	virtual void setLocation(sf::Vector2f);
	virtual void setSize(Size);
	virtual void setSprite(int);

	bool collidesWith(const GameObjects&);

	virtual void handleCollision(GameObjects&) = 0;
	virtual void handleCollision(Wall&) = 0;
	virtual void handleCollision(Mouse&) = 0;
	virtual void handleCollision(Cat&) = 0;
	virtual void handleCollision(Cheese&) = 0;
	virtual void handleCollision(Key&) = 0;
	virtual void handleCollision(Door&) = 0;
	virtual void handleCollision(Present&) = 0;
	
private:
	sf::Sprite m_sprite;

	sf::Vector2f m_location;
	Size m_size;
};