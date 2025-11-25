#include "Static/PresentFreez.h"
#include <iostream>

bool PresentFreeze::m_presentFreeze = false;

PresentFreeze::PresentFreeze(Vertex loc, Size size) : Present(loc, size)
{
	setSprite(TEXTURE::freezePresent);
}

//-------------------------------------------------------
void PresentFreeze::setPresentFreeze(bool b)
{
	m_presentFreeze = b;
}

//-------------------------------------------------------
bool PresentFreeze::getPresentFreeze()
{
	return m_presentFreeze;
}

//-------------------------------------------------------
void PresentFreeze::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}

//-------------------------------------------------------
void PresentFreeze::handleCollision(Mouse&)
{
	SoundResources::getSound().playSound(SOUND::freeze);
	setPresentFreeze(true);
	Eaten();
}