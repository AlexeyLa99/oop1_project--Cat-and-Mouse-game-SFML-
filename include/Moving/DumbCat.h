#pragma once

#include "Cat.h"

class DumbCat : public Cat
{
private:

public:
	DumbCat(Vertex, Size, int);

	virtual void move(sf::Time);
};