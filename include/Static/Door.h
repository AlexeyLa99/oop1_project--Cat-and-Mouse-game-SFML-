#pragma once 

#include "Static/StaticObjects.h"
#include "Moving/Mouse.h"

class Door : public StaticObjects
{
public:
	Door(Vertex, Size);
	virtual ~Door();

	//get
	static int getDoor();

	virtual void handleCollision(GameObjects&) override;
	virtual void handleCollision(Mouse&) override;
private:
	static int m_door;
};