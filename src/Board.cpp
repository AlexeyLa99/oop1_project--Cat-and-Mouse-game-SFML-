#include <Board.h>

//-------------------------------------------------------
Board::Board() :m_lives(3), m_points(), m_level(1),
				m_cheese(), m_doors(), m_presents(),
				m_cols(), m_rows(), m_timeLimit()
{
	srand(time(NULL));
}

//-------------------------------------------------------
Board::~Board()
{
}

//-------------------------------------------------------
void Board::draw(sf::RenderWindow* window)
{
	initBorder();
	window->draw(m_border);

	m_status.draw(window);

	for (size_t i = 0; i < m_staticObjects.size(); i++)
	{
		window->draw(m_staticObjects[i]->getSprite());
	}
	for (size_t i = 0; i < m_movingObjects.size(); i++)
	{
		window->draw(m_movingObjects[i]->getSprite());
	}
}

//-------------------------------------------------------
bool Board::getLevel(const int level)
{
	std::string currLvl = "Level" + std::to_string(level) + ".txt";

	auto lvl = std::ifstream(currLvl);
	if (!lvl)
	{
		return false;
	}
	m_movingObjects.clear();
	m_staticObjects.clear();


	lvl >> m_rows >> m_cols >> m_timeLimit;

	size_t row = 0;
	for (auto line = std::string(); std::getline(lvl, line); row++)//line == col
	{
		for (size_t col = 0; col < line.size(); col++)
		{
			initVector(line[col], Vertex((float)col, (float)row));
		}
	}
	return true;
}

//-------------------------------------------------------
void Board::initVector(char c, Vertex loc)
{
	double size = (WindowWidth / 4 * 3.5) / std::max(m_rows, m_cols);

	if (c != ' ')
	{
		switch (c)
		{
		case '%': //mouse
			m_movingObjects.push_back(std::make_unique<Mouse>(loc, Size(size, size), 3, MouseSpeed));
			break;
		case '^': //dumbCat
			m_movingObjects.push_back(std::make_unique<DumbCat>(loc, Size(size, size), DumbCatSpeed));
			break;
		case '<': //smartCat
			m_movingObjects.push_back(std::make_unique<SmartCat>(loc, Size(size, size), SmartCatSpeed));
			break;
		case '#': //Wall
			m_staticObjects.push_back(std::make_unique<Wall>(loc, Size(size, size)));
			break;
		case '*': //Cheese
			m_staticObjects.push_back(std::make_unique<Cheese>(loc, Size(size, size)));
			++m_cheese;
			break;
		case 'D': //Door
			m_staticObjects.push_back(std::make_unique<Door>(loc, Size(size, size)));
			break;
		case 'F': //Key
			m_staticObjects.push_back(std::make_unique<Key>(loc, Size(size, size)));
			break;
		case '$': //Present
			m_staticObjects.push_back(std::make_unique<PresentCat>(loc, Size(size, size)));
			break;
		case 'z': //freeze Present
			m_staticObjects.push_back(std::make_unique<PresentFreeze>(loc, Size(size, size)));
			break;
		case '3': //life present
			m_staticObjects.push_back(std::make_unique<PresentLife>(loc, Size(size, size)));
			break;
		case '+': //time Present
			if (m_timeLimit != -1)
			{
				m_staticObjects.push_back(std::make_unique<PresentTime>(loc, Size(size, size)));
			}
			break;
		default:
			break;
		}
	}
}

//-------------------------------------------------------
void Board::initBorder()
{
	float size_x = (windowHeight / 4 * 3.5) / std::max(m_rows, m_cols) * (m_cols + 3);
	float size_y = (WindowWidth / 4 * 3.5) / std::max(m_rows, m_cols) * (m_rows);
	m_border.setSize(sf::Vector2f(size_x, size_y));
	m_border.setPosition(sf::Vector2f(10.f, 75.f));
	m_border.setFillColor(sf::Color::Transparent);
}

//-------------------------------------------------------
void Board::handleAndMove()
{
	auto deltaTime = m_movementClock.restart();

	for (size_t i = 0; i < m_movingObjects.size(); i++)
	{
		m_movingObjects[i]->move(deltaTime);

		for (size_t j = 0; j < m_movingObjects.size(); j++)
		{
			if (m_movingObjects[i]->collidesWith(*m_movingObjects[j]))
			{
				m_movingObjects[i]->handleCollision(*m_movingObjects[j]);
			}
		}

		for (size_t j = 0; j < m_staticObjects.size(); j++)
		{
			if (m_movingObjects[i]->collidesWith(*m_staticObjects[j]))
			{
				m_movingObjects[i]->handleCollision(*m_staticObjects[j]);
				m_staticObjects[j]->handleCollision(*m_movingObjects[i]);

				checkCatWall(m_movingObjects[i].get());
			}
		}
		setToRemove(m_movingObjects[i].get());
		
		updateStatus(m_movingObjects[i].get());
		
		boardCollisions(i);
	}
	setToFreeze();
	resetLocations();

	std::erase_if(m_staticObjects, [](const auto& StaticObjects) { return StaticObjects->isEaten(); });
	std::erase_if(m_movingObjects, [](const auto& movingObjects) { return movingObjects->isRemove(); });
	MovingObjects::resetLocation();
}

//-------------------------------------------------------
void Board::boardCollisions(int i)
{
	if (m_movingObjects[i]->getSprite().getGlobalBounds().left < m_border.getGlobalBounds().left)
	{
		m_movingObjects[i]->borderCollision();
	}
	else if (m_movingObjects[i]->getSprite().getGlobalBounds().top < m_border.getGlobalBounds().top)
	{
		m_movingObjects[i]->borderCollision();
	}
	else if (m_movingObjects[i]->getSprite().getGlobalBounds().left +
		m_movingObjects[i]->getSprite().getGlobalBounds().width >
		m_border.getGlobalBounds().left + m_border.getGlobalBounds().width)
	{
		m_movingObjects[i]->borderCollision();
	}
	else if (m_movingObjects[i]->getSprite().getGlobalBounds().top +
		m_movingObjects[i]->getSprite().getGlobalBounds().height >
		m_border.getGlobalBounds().top + m_border.getGlobalBounds().height)
	{
		m_movingObjects[i]->borderCollision();
	}
}

//-------------------------------------------------------
void Board::resetClock()
{
	m_clock.restart();
}

//-------------------------------------------------------
void Board::updateStatus(MovingObjects* ptr)
{
	Mouse* mouse = dynamic_cast<Mouse*>(ptr);
	if (mouse)
	{
		m_status.setKeys(mouse->getKeys());
		m_lives = mouse->getLives();

		if (PresentTime::getPresentTime())
		{
			m_timeLimit += ADDTIME;
			PresentTime::setPresentTime(false);
			m_presents = Present::getPresents();
		}
		if (m_presents != Present::getPresents())
		{
			m_points += PRESENTPOINTS;
			m_presents = Present::getPresents();
		}
		if (m_cheese != Cheese::getCheese())
		{
			m_points += CHEESEPOINTS;
			m_cheese = Cheese::getCheese();
		}
		if (m_doors != Door::getDoor())
		{
			m_points += DOORPOINTS;
			m_doors = Door::getDoor();
		}
	}
	m_status.setGameLevel(m_level);
	m_status.setLives(m_lives);
	m_status.setPoints(m_points);
	if (m_timeLimit != -1)
	{
		m_status.setTimer(getTime());
	}
	else
	{
		m_status.setTimer(-1);
	}
}

//-------------------------------------------------------
void Board::resetLocations()
{
	for (size_t i = 0; i < m_movingObjects.size(); i++)
	{
		if (MovingObjects::isResetLocation())
		{
			m_movingObjects[i]->setInitialLocation();
		}
	}
}

//-------------------------------------------------------
void Board::checkCatWall(MovingObjects* ptr)
{
	if (dynamic_cast<Cat*>(ptr))
	{
		dynamic_cast<Cat*>(ptr)->updateMetWall();
	}
}

//-------------------------------------------------------
int Board::getCheese() const
{
	return m_cheese;
}

//-------------------------------------------------------
int Board::getTime() const
{
	if (m_timeLimit == -1)
	{
		return -1;
	}
	return m_timeLimit - m_clock.getElapsedTime().asSeconds();
}

//-------------------------------------------------------
int Board::getLives() const
{
	return m_lives;
}

//-------------------------------------------------------
int Board::getPoints() const
{
	return m_points;
}

//-------------------------------------------------------
void Board::setLevel(int level)
{
	m_level = level;
}

//-------------------------------------------------------
void Board::setLives(int lives)
{
	m_lives = lives;
}

//-------------------------------------------------------
void Board::setPoints(int points)
{
	m_points = points;
}

//-------------------------------------------------------
void Board::addPoints(int points)
{
	m_points += points;
}

//-------------------------------------------------------
void Board::setTime()
{
	m_status.setTimer(-1);
}

//-------------------------------------------------------
void Board::setToRemove(MovingObjects* ptr)
{
	if (PresentCat::getPresentTaken())
	{
		Cat* cat = dynamic_cast<Cat*>(ptr);
		if (cat)
		{
			cat->remove();
			PresentCat::setPresentTaken(false);
		}
	}
}

//-------------------------------------------------------
void Board::setToFreeze()
{
	if (PresentFreeze::getPresentFreeze())
	{
		m_clockFreeze.restart();
		Cat::setFreeze(true);

		PresentFreeze::setPresentFreeze(false);
	}
	m_freezeTime = m_clockFreeze.getElapsedTime();
	if (Cat::getFreeze())
	{
		if (m_freezeTime.asSeconds() >= FREEZETIME)
		{
			Cat::setFreeze(false);
		}
	}
}
