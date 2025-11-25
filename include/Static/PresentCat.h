#pragma once 

#include "Static/Present.h"

class PresentCat : public Present
{
public:
	PresentCat(Vertex, Size);

	static void setPresentTaken(bool);
	static bool getPresentTaken();

	virtual void handleCollision(GameObjects&) override;
	virtual void handleCollision(Mouse&) override;
private:
	static bool m_presentTaken;
};
