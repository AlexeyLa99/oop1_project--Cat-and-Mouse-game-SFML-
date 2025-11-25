#include "Static/Key.h"

Key::Key(Vertex loc, Size size) : StaticObjects(loc, size)
{
	setSprite(TEXTURE::key);
	++m_keys;
}

//-------------------------------------------------------
Key::~Key()
{
	--m_keys;
}

//-------------------------------------------------------
int Key::getKeys()
{
	return m_keys;
}

//-------------------------------------------------------
void Key::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}

//-------------------------------------------------------
void Key::handleCollision(Mouse&)
{
	Eaten();
}

int Key::m_keys = 0;