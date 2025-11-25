#pragma once

#include <SFML/Graphics.hpp>
#include "ConstMembers.h"
#include "Resources.h"

class GameStatus
{
public:
	GameStatus();

	void draw(sf::RenderWindow* window) const;

	//set
	void setLives(int);
	void setKeys(int);
	void setPoints(int);
	void setGameLevel(int);
	void setTimer(int);
	void addTime();

private:
	sf::Text m_gameLevel;
	sf::Text m_keys;
	sf::Text m_lives;
	sf::Text m_points;
	sf::Text m_timer;

};