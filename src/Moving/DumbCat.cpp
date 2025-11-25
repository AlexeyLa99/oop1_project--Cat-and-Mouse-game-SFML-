#include <Moving/DumbCat.h>

DumbCat::DumbCat(Vertex loc, Size size, int speed)
	:Cat(loc, size, speed)
{
	srand(time(NULL));
}

void DumbCat::move(sf::Time deltaTime)
{
	int randNumber = 4;

	if (int randomTimeDirection; (randomTimeDirection = rand() % 20) == 10)
	{
		randNumber = rand() % 4;
	}

	setLastLocation(getLocation());
	auto s = getSize().m_x / 380;
	switch (randNumber)
	{
	case 0:
		directionDown();
		
		break;
	case 1:
		directionLeft();
		getSprite().setScale(s, s);
		break;
	case 2:
		directionRight();
		getSprite().setScale(-s, s);
		break;
	case 3:
		directionUp();
		break;
	default:
		break;
	}

	if (Cat::getFreeze())
	{
		resetDirection();
	}

	getSprite().move(getDirection() * getSpeed() * deltaTime.asSeconds());

	setLocation(getSprite().getPosition());
}
