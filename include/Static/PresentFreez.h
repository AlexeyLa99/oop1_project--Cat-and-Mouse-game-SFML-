#pragma once 

#include "Static/Present.h"

class PresentFreeze : public Present
{
public:
	PresentFreeze(Vertex, Size);

	virtual void handleCollision(GameObjects&);
	virtual void handleCollision(Mouse&);

	static void setPresentFreeze(bool);
	static bool getPresentFreeze();
private:
	static bool m_presentFreeze;
};