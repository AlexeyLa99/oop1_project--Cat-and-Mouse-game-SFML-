#pragma once

#include "GameObjects.h"

class StaticObjects : public GameObjects
{
public:
	StaticObjects(Vertex, Size);
	
	bool isEaten() const;
	void Eaten();

	virtual void handleCollision(GameObjects&) {};
	virtual void handleCollision(Mouse&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Cat&) {};
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Present&) {};

private:
	bool m_isEaten;
};

