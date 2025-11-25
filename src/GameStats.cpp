#include "GameStats.h"

//-------------------------------------------------------
GameStatus::GameStatus()
{
	//level
	m_gameLevel.setFont(*Resources::getResource().getFont());
	m_gameLevel.setString(": " + std::to_string(1));
	m_gameLevel.setStyle(sf::Text::Bold);
	m_gameLevel.setPosition(sf::Vector2f(130.f, 25.f));
	
	//lives
	m_lives.setFont(*Resources::getResource().getFont());
	m_lives.setString(": " + std::to_string(3));
	m_lives.setStyle(sf::Text::Bold);
	m_lives.setPosition(sf::Vector2f(280.f, 25.f));
	
	//keys
	m_keys.setFont(*Resources::getResource().getFont());
	m_keys.setString(": " + std::to_string(0));
	m_keys.setStyle(sf::Text::Bold);
	m_keys.setPosition(sf::Vector2f(405.f, 25.f));
	
	//points
	m_points.setFont(*Resources::getResource().getFont());
	m_points.setString(": " + std::to_string(0));
	m_points.setStyle(sf::Text::Bold);
	m_points.setPosition(sf::Vector2f(600.f, 25.f));

	//timer
	m_timer.setFont(*Resources::getResource().getFont());
	m_timer.setString(": --");
	m_timer.setStyle(sf::Text::Bold);
	m_timer.setPosition(sf::Vector2f(825.f, 25.f));
}

//-------------------------------------------------------
void GameStatus::draw(sf::RenderWindow* window) const
{
	window->draw(m_gameLevel);
	window->draw(m_keys);
	window->draw(m_lives);
	window->draw(m_points);
	window->draw(m_timer);
}

//-------------------------------------------------------
void GameStatus::setGameLevel(int level)
{
	m_gameLevel.setString(": " + std::to_string(level));
}

//-------------------------------------------------------
void GameStatus::setKeys(int keys)
{
	m_keys.setString(": " + std::to_string(keys));
}

//-------------------------------------------------------
void GameStatus::setLives(int lives)
{
	m_lives.setString(": " + std::to_string(lives));
}

//-------------------------------------------------------
void GameStatus::setPoints(int points)
{
	m_points.setString(": " + std::to_string(points));
}

//-------------------------------------------------------
void GameStatus::setTimer(int time)
{
	if (time == -1)
	{
		m_timer.setString(": --");
	}
	else
	{
		m_timer.setString(": " + std::to_string(time));
	}
}

void GameStatus::addTime()
{
	
}
