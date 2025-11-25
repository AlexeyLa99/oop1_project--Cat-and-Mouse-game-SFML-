#include <Moving/MovingObjects.h>

bool MovingObjects::m_isResetLocation = false;
sf::Vector2f MovingObjects::m_mouseLocation = sf::Vector2f(0, 0);

MovingObjects::MovingObjects(Vertex loc, Size size, int speed)
	: GameObjects(loc, size), m_speed(speed)
{
}

//-------------------------------------------------------
void MovingObjects::remove()
{
	m_isRemove = true;
}

//-------------------------------------------------------
bool MovingObjects::isRemove() const
{
	return m_isRemove;
}

//-------------------------------------------------------
void MovingObjects::directionUp()
{
	m_direction = sf::Vector2f(0, -1);
}

//-------------------------------------------------------
void MovingObjects::directionDown()
{
	m_direction = sf::Vector2f(0, 1);
}

//-------------------------------------------------------
void MovingObjects::directionRight()
{
	m_direction = sf::Vector2f(1, 0);
}

//-------------------------------------------------------
void MovingObjects::directionLeft()
{
	m_direction = sf::Vector2f(-1, 0);
}

//-------------------------------------------------------
void MovingObjects::resetDirection()
{
	m_direction = sf::Vector2f(0, 0);
}

//-------------------------------------------------------
void MovingObjects::borderCollision()
{
	setLocation(getLastLocation());
	getSprite().setPosition(getLastLocation());
}

//-------------------------------------------------------

sf::Vector2f MovingObjects::getDirection() const
{
	return m_direction;
}

//-------------------------------------------------------
float MovingObjects::getSpeed() const
{
	return m_speed;
}

//-------------------------------------------------------
sf::Vector2f MovingObjects::getLastLocation() const
{
	return m_lastLocation;
}

//-------------------------------------------------------
sf::Vector2f MovingObjects::getMouseLocation() const
{
	return m_mouseLocation;
}

//-------------------------------------------------------
sf::Vector2f MovingObjects::getStaterLocation() const
{
	return m_startingLocation;
}

//-------------------------------------------------------
bool MovingObjects::isResetLocation()
{
	return m_isResetLocation;
}

//-------------------------------------------------------
void MovingObjects::setLastLocation(sf::Vector2f loc)
{
	m_lastLocation = loc;
}

//-------------------------------------------------------
void MovingObjects::setResetLocation()
{
	m_isResetLocation = true;
}

//-------------------------------------------------------
void MovingObjects::setInitialLocation()
{
	setLocation(getStaterLocation());
	getSprite().setPosition(getLocation());
}

//-------------------------------------------------------
void MovingObjects::setStarterLocation(sf::Vector2f loc)
{
	m_startingLocation = loc;
}

//-------------------------------------------------------
void MovingObjects::resetLocation()
{
	m_isResetLocation = false;
}

//-------------------------------------------------------
void MovingObjects::setMouseLocation(sf::Vector2f location)
{
	m_mouseLocation = location;
}


