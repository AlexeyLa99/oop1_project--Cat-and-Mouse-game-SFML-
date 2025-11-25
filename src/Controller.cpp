#include "Controller.h"
#include <thread>
#include <chrono>

//-------------------------------------------------------
Controller::Controller()
	: m_window(sf::VideoMode(WindowWidth, windowHeight), "Mouse & Cat", sf::Style::Close | sf::Style::Titlebar),
	m_level(0)
{
	m_window.setFramerateLimit(60);	
	m_window.setIcon(Resources::getResource().getIcon()->getSize().x, Resources::getResource().getIcon()->getSize().y,
		Resources::getResource().getIcon()->getPixelsPtr());
}

//-------------------------------------------------------
Controller::~Controller()
{
}

//-------------------------------------------------------
void Controller::run()
{
	while (m_window.isOpen())
	{
		updateLevel();
		pollEvent();
		menuRun();
	}
}

//-------------------------------------------------------
void Controller::pollEvent()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				if (m_gameState == GAME_STATE::MAIN_MENU) {
					m_window.close();
				}
				else if (m_gameState == GAME_STATE::GAME)
				{
					m_gameState = GAME_STATE::PAUSE;
				}
				else if (m_gameState == GAME_STATE::PAUSE)
				{
					m_gameState = GAME_STATE::GAME;
				}
				else if (m_gameState == GAME_STATE::HELP)
				{
					m_gameState = GAME_STATE::MAIN_MENU;
				}
			}
			if (event.key.code == sf::Keyboard::M) {
				if (m_soundState == SOUND_STATE::ON)
				{
					m_soundState = SOUND_STATE::OFF;
				}
				else
				{
					m_soundState = SOUND_STATE::ON;
				}
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (m_gameState == GAME_STATE::MAIN_MENU)
			{
				m_gameState = m_mainMenu.buttonPressed(&m_window, event.mouseButton, m_gameState);
				m_soundState = m_mainMenu.soundButtonPressed(&m_window, event.mouseButton, m_soundState);
				break;
			} 
			else if(m_gameState == GAME_STATE::HELP)
			{
				m_gameState = m_mainMenu.buttonPressed(&m_window, event.mouseButton, m_gameState);
				m_soundState = m_mainMenu.soundButtonPressed(&m_window, event.mouseButton, m_soundState);
				break;
			}
			else if (m_gameState == GAME_STATE::PAUSE)
			{
				m_gameState = m_mainMenu.buttonPressed(&m_window, event.mouseButton, m_gameState);
				m_soundState = m_mainMenu.soundButtonPressed(&m_window, event.mouseButton, m_soundState);
				break;
			}
			break;
		default:
			break;
		}
	}
}

//-------------------------------------------------------
void Controller::menuRun()
{
	soundManager(m_soundState);
	m_mainMenu.changeColorWhilePointing(&m_window);
	switch (m_gameState)
	{
	case GAME_STATE::MAIN_MENU:
		returnToMenu();
		m_mainMenu.drawMainMenu(&m_window, m_soundState);
		break;
	case GAME_STATE::GAME:
		m_window.draw(initBackGround());
		m_board.draw(&m_window);
		m_board.handleAndMove();
		break;
	case GAME_STATE::HELP:
		m_mainMenu.drawHelp(&m_window, m_soundState);
		break;
	case GAME_STATE::EXIT:
		m_window.close();
		break;
	case GAME_STATE::PAUSE:
		m_mainMenu.drawPause(&m_window, m_soundState);
		break;
	default:
		break;
	}
	m_window.display();
}



void Controller::screen(int texture)
{
    sf::Sprite s;
    s.setTexture(*Resources::getResource().getTexture(texture));
    m_window.clear();
    m_window.draw(s);
    m_window.display();

    std::this_thread::sleep_for(std::chrono::seconds(5));
}

//-------------------------------------------------------
void Controller::returnToMenu()
{
	m_board.resetClock();
	m_gameState = GAME_STATE::MAIN_MENU;
	m_level = 1;
	m_board.setLevel(m_level);
	m_board.getLevel(m_level);
	m_board.setLives(3);
	m_board.setTime();
	m_board.setPoints(-17);
}

//-------------------------------------------------------
void Controller::soundManager(int soundState)
{
	if (soundState == SOUND_STATE::ON)
	{
		if (m_gameState == GAME_STATE::MAIN_MENU) {
			SoundResources::getSound().stopBackground(BACKGROUND::gameSound);
			SoundResources::getSound().playBackground(BACKGROUND::menuSound);
		}
		else if (m_gameState == GAME_STATE::HELP)
		{
			SoundResources::getSound().playBackground(BACKGROUND::menuSound);
		}
		else if (m_gameState == GAME_STATE::GAME)
		{
			SoundResources::getSound().stopBackground(BACKGROUND::menuSound);
			SoundResources::getSound().playBackground(BACKGROUND::gameSound);
		}
		else if (m_gameState == GAME_STATE::PAUSE)
		{
			SoundResources::getSound().playBackground(BACKGROUND::gameSound);
		}
	}
	else if (soundState == SOUND_STATE::OFF)
	{
		if (m_gameState == GAME_STATE::MAIN_MENU)
		{
			SoundResources::getSound().stopBackground(BACKGROUND::menuSound);
		}
		else if (m_gameState == GAME_STATE::HELP)
		{
			SoundResources::getSound().stopBackground(BACKGROUND::menuSound);
		}
		else if (m_gameState == GAME_STATE::GAME)
		{
			SoundResources::getSound().stopBackground(BACKGROUND::gameSound);
		}
		else if (m_gameState == GAME_STATE::PAUSE)
		{
			SoundResources::getSound().stopBackground(BACKGROUND::gameSound);
		}
	}
}

//-------------------------------------------------------
sf::Sprite Controller::initBackGround()
{
	sf::Sprite background;
	background.setTexture(*Resources::getResource().getTexture(TEXTURE::gameBackGround));
	return background;
}


//-------------------------------------------------------
void Controller::updateLevel()
{
	if (m_gameState == GAME_STATE::GAME)
	{
		if (m_board.getCheese() == 0)
		{
			m_board.resetClock();
			m_level += 1;
			if (!m_board.getLevel(m_level))
			{
				SoundResources::getSound().playSound(SOUND::winGame);
				screen(TEXTURE::winScreen);
				returnToMenu();
			}
			else
			{
				if (m_level > 1)
				{
					SoundResources::getSound().playSound(SOUND::levelUp);
					m_board.resetClock();
					m_board.setLevel(m_level);
					m_board.setLives(m_board.getLives());
					m_board.setPoints(m_board.getPoints() - 17 + CHEESEPOINTS + LVLCMPLT);
				}
			}
		}

		if (m_board.getTime() == 0)
		{
			SoundResources::getSound().playSound(SOUND::gameOver);
			screen(TEXTURE::gameOverScreen);
			m_board.resetClock();
			returnToMenu();
		}
		
		if (m_board.getLives() <= 0)
		{
			SoundResources::getSound().playSound(SOUND::gameOver);
			screen(TEXTURE::gameOverScreen);
			returnToMenu();
		}
	}
}