#include <Moving/Cat.h>
#include <iostream>

bool Cat::m_freeze = false;

//-------------------------------------------------------
Cat::Cat(Vertex loc, Size size, int speed)
	:MovingObjects(loc, size, speed)
{
	setSprite(TEXTURE::cat);
	setLocation(getSprite().getPosition());
	setStarterLocation(getLocation());
}

//-------------------------------------------------------
void Cat::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}

//-------------------------------------------------------
void Cat::handleCollision(Wall&)
{
	updateMetWall();
	setLocation(getLastLocation());
	getSprite().setPosition(getLastLocation());
}

//-------------------------------------------------------
void Cat::handleCollision(Mouse&) {}

//-------------------------------------------------------
void Cat::handleCollision(Door&)
{
	updateMetWall();
	setLocation(getLastLocation());
	getSprite().setPosition(getLastLocation());
}

//-------------------------------------------------------
void Cat::setFreeze(bool b)
{
	m_freeze = b;
}

//-------------------------------------------------------
void Cat::updateMetWall()
{
	if (m_isMetWall)
	{
		m_isMetWall = false;
	}
	else
	{
		m_isMetWall = true;
	}
}

//-------------------------------------------------------
bool Cat::getFreeze()
{
	return m_freeze;
}

//-------------------------------------------------------
bool Cat::getMetWall() const
{
	return m_isMetWall;
}
