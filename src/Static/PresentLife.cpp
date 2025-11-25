#include "Static/PresentLife.h"
#include "Moving/Mouse.h"

PresentLife::PresentLife(Vertex loc, Size size) : Present(loc, size)
{
	setSprite(TEXTURE::lifePresent);
}

void PresentLife::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}

void PresentLife::handleCollision(Mouse& mouse)
{
	SoundResources::getSound().playSound(SOUND::addLife);
	mouse.addLife();
	Eaten();
}
