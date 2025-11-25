#pragma once

#include "Moving/MovingObjects.h"
#include "SoundResources.h"

class Mouse : public MovingObjects
{
public:
	Mouse(Vertex, Size, int, int);

	//move
	virtual void move(sf::Time);

	virtual void handleCollision(GameObjects&) override;
	virtual void handleCollision(Wall&) override;
	virtual void handleCollision(Cat&) override;
	virtual void handleCollision(Cheese&) override;
	virtual void handleCollision(Key&) override;
	virtual void handleCollision(Door&) override;
	virtual void handleCollision(Present&) override;
	


	//get
	int getKeys() const;
	int getLives() const;

	void addLife();

private:
	int m_lives;
	int m_keys;

};