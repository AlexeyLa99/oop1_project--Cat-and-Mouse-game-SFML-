#pragma once

#include "GameObjects.h"

class MovingObjects : public GameObjects
{
private:
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	float m_speed;

	sf::Vector2f m_startingLocation;
	sf::Vector2f m_lastLocation;
	static sf::Vector2f m_mouseLocation;
	static bool m_isResetLocation;

	bool m_isRemove = false;

public:
	MovingObjects(Vertex, Size, int);

	void remove();
	bool isRemove() const;

	//move
	virtual void move(sf::Time) = 0;

	//directions
	virtual void directionUp();
	virtual void directionDown();
	virtual void directionLeft();
	virtual void directionRight();
	virtual void resetDirection();
	void borderCollision();

	//get
	virtual sf::Vector2f getDirection() const;
	virtual float getSpeed() const;
	virtual sf::Vector2f getLastLocation() const;
	virtual sf::Vector2f getMouseLocation() const;
	virtual sf::Vector2f getStaterLocation() const;
	static bool isResetLocation();

	//set
	virtual void setLastLocation(sf::Vector2f);
	virtual void setResetLocation();
	virtual void setInitialLocation();
	virtual void setStarterLocation(sf::Vector2f);
	static void resetLocation();
	virtual void setMouseLocation(sf::Vector2f);

	virtual void handleCollision(GameObjects&) {};
	virtual void handleCollision(Mouse&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Cat&) {};
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Present&) {};
};