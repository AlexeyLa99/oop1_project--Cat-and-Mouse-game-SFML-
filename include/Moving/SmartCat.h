#include <Moving/Cat.h>

class SmartCat : public Cat
{
public:
	SmartCat(Vertex, Size, int);
	
	virtual void move(sf::Time);

private:
};