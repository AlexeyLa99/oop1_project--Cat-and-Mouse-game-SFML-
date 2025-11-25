#pragma once

#include "Static/StaticObjects.h"

class Present : public StaticObjects
{
public:
	Present(Vertex, Size);
	virtual ~Present();

	virtual void handleCollision(GameObjects&) {};
	virtual void handleCollision(Mouse&) {};

	//get
	static int getPresents();
private:
	static int m_presents;
};