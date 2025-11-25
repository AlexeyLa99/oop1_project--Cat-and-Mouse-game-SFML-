#pragma once 

#include "Static/Present.h"

class PresentLife : public Present
{
public:
	PresentLife(Vertex, Size);

	virtual void handleCollision(GameObjects&) override;
	virtual void handleCollision(Mouse&) override;

private:
};