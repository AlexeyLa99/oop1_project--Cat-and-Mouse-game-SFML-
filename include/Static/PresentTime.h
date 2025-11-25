#pragma once 

#include "Static/Present.h"

class PresentTime : public Present
{
public:
	PresentTime(Vertex, Size);

	//get
	static void setPresentTime(bool);
	static bool getPresentTime();

	virtual void handleCollision(GameObjects&) override;
	virtual void handleCollision(Mouse&) override;
private:
	static bool m_presentTime;
};
