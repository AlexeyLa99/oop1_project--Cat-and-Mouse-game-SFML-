#pragma once 

#include "Static/StaticObjects.h"

class Wall : public StaticObjects
{	
public:
	Wall(Vertex, Size);

	virtual void handleCollision(GameObjects&) override;
private:
};
