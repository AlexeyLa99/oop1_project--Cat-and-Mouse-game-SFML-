#pragma once

#include "Moving/MovingObjects.h"

class Cat : public MovingObjects
{
public:
	Cat(Vertex, Size, int);

	//move
	virtual void move(sf::Time) {};

	virtual void handleCollision(GameObjects&) override;
	virtual void handleCollision(Wall&) override;
	virtual void handleCollision(Mouse&) override;
	virtual void handleCollision(Door&) override;

	

	//set
	static void setFreeze(bool);
	virtual void updateMetWall();

	//get
	static bool getFreeze();
	bool getMetWall() const;

private:
	static bool m_freeze;
	bool m_isMetWall = false;
};