#include <Moving/Mouse.h>

Mouse::Mouse(Vertex loc, Size size, int lives, int speed)
	:MovingObjects(loc, size, speed), m_lives(lives), m_keys(0)
{
	setSprite(TEXTURE::mouse);
	setLocation(getSprite().getPosition());
	setStarterLocation(getLocation());
}

void Mouse::move(sf::Time deltaTime)
{
	setLastLocation(getLocation());

	auto s = getSize().m_x / 380;

	getSprite().setOrigin(sf::Vector2f(getSprite().getTexture()->getSize() / 2u));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		directionUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		directionDown();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		directionRight();
		getSprite().setScale(s, s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		directionLeft();
		getSprite().setScale(-s, s);
	}
	getSprite().move(getDirection() * getSpeed() * deltaTime.asSeconds());

	setMouseLocation(getLocation());

	setLocation(getSprite().getPosition());

	resetDirection();
}

//-------------------------------------------------------
int Mouse::getKeys() const
{
	return m_keys;
}

//-------------------------------------------------------
int Mouse::getLives() const
{
	return m_lives;
}

//-------------------------------------------------------
void Mouse::addLife()
{
	++m_lives;
}

//-------------------------------------------------------
void Mouse::handleCollision(GameObjects& other)
{
	return other.handleCollision(*this);
}

//-------------------------------------------------------
void Mouse::handleCollision(Wall&)
{
	setLocation(getLastLocation());
	getSprite().setPosition(getLastLocation());
}

//-------------------------------------------------------
void Mouse::handleCollision(Cat&)
{
	SoundResources::getSound().playSound(SOUND::catEat);
	--m_lives;
	setResetLocation();
}

//-------------------------------------------------------
void Mouse::handleCollision(Cheese&)
{
	SoundResources::getSound().playSound(SOUND::mouseEat);
}

void Mouse::handleCollision(Key&)
{
	SoundResources::getSound().playSound(SOUND::pickKey);
	++m_keys;

}

//-------------------------------------------------------
void Mouse::handleCollision(Door&)
{
	if (m_keys > 0)
	{
		SoundResources::getSound().playSound(SOUND::doorOpen);
		--m_keys;
	}
	else
	{
		setLocation(getLastLocation());
		getSprite().setPosition(getLastLocation());
	}
}

void Mouse::handleCollision(Present&)
{
	SoundResources::getSound().playSound(SOUND::present);
}
