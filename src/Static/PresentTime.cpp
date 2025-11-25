#include "Static/PresentTime.h"

bool PresentTime::m_presentTime = false;

PresentTime::PresentTime(Vertex loc, Size size) : Present(loc, size)
{
	setSprite(TEXTURE::timePresent);
}

//-------------------------------------------------------
void PresentTime::setPresentTime(bool taken)
{
	m_presentTime = taken;
}

//-------------------------------------------------------
bool PresentTime::getPresentTime()
{
	return m_presentTime;
}

//-------------------------------------------------------
void PresentTime::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}

//-------------------------------------------------------
void PresentTime::handleCollision(Mouse& mouse)
{
	SoundResources::getSound().playSound(SOUND::addTime);
	setPresentTime(true);
	Eaten();
}