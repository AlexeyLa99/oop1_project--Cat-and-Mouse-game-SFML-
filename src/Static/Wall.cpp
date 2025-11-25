#include "Static/Wall.h"

Wall::Wall(Vertex loc, Size size) : StaticObjects(loc, size)
{
	setSprite(TEXTURE::wall);
}

void Wall::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}
