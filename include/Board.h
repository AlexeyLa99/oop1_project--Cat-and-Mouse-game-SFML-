#pragma once

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ConstMembers.h>


#include "GameStats.h"

#include "Moving/Mouse.h"
#include "Moving/DumbCat.h"
#include "Moving/SmartCat.h"
#include "Static/Cheese.h"
#include "Static/Door.h"
#include "Static/Key.h"
#include "Static/Wall.h"
#include "Static/PresentCat.h"
#include "Static/PresentFreez.h"
#include "Static/PresentLife.h"
#include "Static/PresentTime.h"

class Board
{
public:
	Board();
	~Board();

	void draw(sf::RenderWindow*);

	//init level
	bool getLevel(const int);
	void initVector(char, Vertex);
	void initBorder();
	void handleAndMove();
	void boardCollisions(int);

	void resetClock();
	void updateStatus(MovingObjects*);
	void resetLocations();
	void checkCatWall(MovingObjects*);

	//get
	int getCheese() const;
	int getTime() const;
	int getLives() const;
	int getPoints() const;

	//set
	void setLevel(int);
	void setLives(int);
	void setPoints(int);
	void addPoints(int);
	void setTime();
	void setToRemove(MovingObjects*);
	void setToFreeze();
	//void setCurrentObj();
	//void setNextObj();
private:
	std::vector<std::unique_ptr<MovingObjects>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;

	sf::Clock m_clock, m_movementClock;
	sf::RectangleShape m_border;

	int m_rows, m_cols, m_timeLimit;

	GameStatus m_status;

	int m_level, m_cheese, m_lives, m_points, m_presents, m_doors;

	sf::Clock m_clockFreeze;
	sf::Time m_freezeTime;
};