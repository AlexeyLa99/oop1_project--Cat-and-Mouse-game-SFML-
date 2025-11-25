#pragma once 

#include "Static/StaticObjects.h"

class Key : public StaticObjects
{
public:
	Key(Vertex, Size);
	virtual ~Key();

	static int getKeys();
	
	virtual void handleCollision(GameObjects&) override;
	virtual void handleCollision(Mouse&) override;
private:
	static int m_keys;
};