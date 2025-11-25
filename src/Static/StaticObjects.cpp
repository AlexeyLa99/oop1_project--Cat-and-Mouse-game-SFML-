#include <Static/StaticObjects.h>

StaticObjects::StaticObjects(Vertex loc, Size size) : GameObjects(loc, size), m_isEaten(false)
{
}

//-------------------------------------------------------
bool StaticObjects::isEaten() const
{
	return m_isEaten;
}

//-------------------------------------------------------
void StaticObjects::Eaten()
{
	m_isEaten = true;
}