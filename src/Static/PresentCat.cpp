#include "Static/PresentCat.h"

bool PresentCat::m_presentTaken = false;

PresentCat::PresentCat(Vertex loc, Size size) : Present(loc, size)
{
	setSprite(TEXTURE::present);
}

//-------------------------------------------------------
void PresentCat::setPresentTaken(bool taken)
{
	m_presentTaken = taken;
}

//-------------------------------------------------------
bool PresentCat::getPresentTaken()
{
	return m_presentTaken;
}

//-------------------------------------------------------
void PresentCat::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}

//-------------------------------------------------------
void PresentCat::handleCollision(Mouse&)
{
	SoundResources::getSound().playSound(SOUND::present);
	setPresentTaken(true);
	Eaten();
}
