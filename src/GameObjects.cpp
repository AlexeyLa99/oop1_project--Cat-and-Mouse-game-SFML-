#include "GameObjects.h"

//-------------------------------------------------
GameObjects::GameObjects(Vertex loc, Size size)
	:m_location(), m_size()
{
	setLocation(sf::Vector2f(loc.m_x, loc.m_y));
	setSize(size);
}

//-------------------------------------------------
sf::Vector2f GameObjects::getLocation() const
{
	return m_location;
}

//-------------------------------------------------
Size GameObjects::getSize() const
{
	return m_size;
}

//-------------------------------------------------
sf::Sprite& GameObjects::getSprite()
{
	return m_sprite;
}

//-------------------------------------------------
void GameObjects::setLocation(sf::Vector2f loc)
{
	m_location = loc;
}

//-------------------------------------------------
void GameObjects::setSize(Size size)
{
	m_size = size;
}

//-------------------------------------------------
void GameObjects::setSprite(int obj)
{
	float s = getSize().m_x / 380.f;
	float x = getLocation().x;
	float y = getLocation().y;

	m_sprite.setTexture(*Resources::getResource().getTexture(obj));
	m_sprite.setScale(s, s);
	m_sprite.setOrigin(sf::Vector2f(getSprite().getTexture()->getSize() / 2u));
	m_sprite.setPosition(sf::Vector2f(x * (getSize().m_x + 1) + getSize().m_x / 2 + 10,
		y * (getSize().m_x + 1) + 60));
}

//-------------------------------------------------
bool GameObjects::collidesWith(const GameObjects& obj)
{
	sf::FloatRect a;
	getSprite().getGlobalBounds().intersects(obj.m_sprite.getGlobalBounds(), a);

	if (a.width <= 4.5f || a.height <= 4.5f)
	{
		return false;
	}
	return true;
}