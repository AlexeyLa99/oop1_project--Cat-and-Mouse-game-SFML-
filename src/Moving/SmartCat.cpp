#include <Moving/SmartCat.h>
#include <queue>
#include <map>
#include <iostream>

SmartCat::SmartCat(Vertex loc, Size size, int speed)
	:Cat(loc, size, speed)
{
	srand(time(NULL));
}


void SmartCat::move(sf::Time deltaTime)
{
    setLastLocation(getLocation());
    auto s = getSize().m_x / 380;

    auto mouseLoc = getMouseLocation();
    auto catLoc = getLocation();

	int direction = 4;  
	float dx = abs(mouseLoc.x - catLoc.x);
	float dy = abs(mouseLoc.y - catLoc.y);
	
	if (dx > dy)
	{
		if (mouseLoc.x > catLoc.x)
		{
			direction = 2;
		}
		else
		{
			direction = 1;
		}
	}
	else
	{
		if (mouseLoc.y > catLoc.y)
		{
			direction = 0;
		}
		else
		{
			direction = 3;
		}
	}

	if ((dx >= 50 && dy >= 50))
	{

		if (int randomTimeDirection; (randomTimeDirection = rand() % 20) == 10)
		{
			direction = rand() % 4;
		}
	}

	if (getMetWall())
	{
		if (int randomTimeDirection; (randomTimeDirection = rand() % 20) == 10)
		{
			direction = rand() % 4;
		}
		updateMetWall();
	}
    switch (direction)
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
        return; 
    }

    if (Cat::getFreeze())
    {
        resetDirection();
    }

    getSprite().move(getDirection() * getSpeed() * deltaTime.asSeconds());
    setLocation(getSprite().getPosition());
}