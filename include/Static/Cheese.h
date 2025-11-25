#pragma once 

#include "Static/StaticObjects.h"

class Cheese : public StaticObjects
{
public:
	Cheese(Vertex, Size);
	virtual ~Cheese();

	static int getCheese();

	virtual void handleCollision(GameObjects&) override;
	virtual void handleCollision(Mouse&) override;
private:
	static int m_cheese;
};