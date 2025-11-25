#include "Static/Cheese.h"

Cheese::Cheese(Vertex loc, Size size) : StaticObjects(loc, size)
{
	setSprite(TEXTURE::cheese);
	++m_cheese;
}

//-------------------------------------------------------
Cheese::~Cheese()
{
	--m_cheese;
}

//-------------------------------------------------------
int Cheese::getCheese()
{
	return m_cheese;
}

//-------------------------------------------------------
void Cheese::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}

//-------------------------------------------------------
void Cheese::handleCollision(Mouse&)
{
	Eaten();
}

int Cheese::m_cheese = 0;
