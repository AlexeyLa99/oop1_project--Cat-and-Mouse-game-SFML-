#include "MainMenu.h"
#include <iostream>

//-------------------------------------------------
MainMenu::MainMenu()
{
	initBackGrounds();
	initButtons();
}

//-------------------------------------------------
void MainMenu::initBackGrounds()
{
	// set background
	m_mainBg.setPosition(0.f, 0.f);
	m_mainBg.setSize(sf::Vector2f(WindowWidth, windowHeight));
	m_mainBg.setTexture(Resources::getResource().getTexture(TEXTURE::menuBackGround));

	// set help background
	m_helpBg.setPosition(0.f, 0.f);
	m_helpBg.setSize(sf::Vector2f(WindowWidth, windowHeight));
	m_helpBg.setTexture(Resources::getResource().getTexture(TEXTURE::helpBackGround));
}

//-------------------------------------------------
void MainMenu::initButtons()
{
	// set buttons
	//----------------------------------------------
	// start game button
	m_startGameBtn.setPosition(380.f, 400.f);
	m_startGameBtn.setSize(sf::Vector2f(200.f, 70.f));
	m_startGameBtn.setTexture(Resources::getResource().getTexture(TEXTURE::button));
	m_startGameTxt.setFont(*Resources::getResource().getFont());
	m_startGameTxt.setString("PLAY");
	m_startGameTxt.setStyle(sf::Text::Bold);
	m_startGameTxt.setPosition(445.f, 415.f);

	//help button
	m_helpBtn.setPosition(380.f, 500.f);
	m_helpBtn.setSize(sf::Vector2f(200.f, 70.f));
	m_helpBtn.setTexture(Resources::getResource().getTexture(TEXTURE::button));
	m_helpTxt.setFont(*Resources::getResource().getFont());
	m_helpTxt.setString("HELP");
	m_helpTxt.setStyle(sf::Text::Bold);
	m_helpTxt.setPosition(445.f, 515.f);

	// exit game button
	m_exitGameBtn.setPosition(380.f, 600.f);
	m_exitGameBtn.setSize(sf::Vector2f(200.f, 70.f));
	m_exitGameBtn.setTexture(Resources::getResource().getTexture(TEXTURE::button));
	m_exitGameTxt.setFont(*Resources::getResource().getFont());
	m_exitGameTxt.setString("EXIT");
	m_exitGameTxt.setStyle(sf::Text::Bold);
	m_exitGameTxt.setPosition(445.f, 615.f);


	//sound button
	m_soundBtn.setPosition(50.f, 750.f);
	m_soundBtn.setSize(sf::Vector2f(60.f, 60.f));
	m_soundBtn.setTexture(Resources::getResource().getTexture(TEXTURE::soundButton));
	m_soundTxt.setFont(*Resources::getResource().getFont());
	m_soundTxt.setString("X");
	m_soundTxt.setFillColor(sf::Color::Red);
	m_soundTxt.setStyle(sf::Text::Bold);
	m_soundTxt.setPosition(70.f, 760.f);

	//back button
	m_backBtn.setPosition(380.f, 750.f);
	m_backBtn.setSize(sf::Vector2f(200.f, 70.f));
	m_backBtn.setTexture(Resources::getResource().getTexture(TEXTURE::button));
	m_backTxt.setFont(*Resources::getResource().getFont());
	m_backTxt.setString("BACK");
	m_backTxt.setStyle(sf::Text::Bold);
	m_backTxt.setPosition(445.f, 765.f);

	//pause buttons
	m_continueTxt.setFont(*Resources::getResource().getFont());
	m_continueTxt.setString("CONTINUE");
	m_continueTxt.setStyle(sf::Text::Bold);
	m_continueTxt.setPosition(405.f, 415.f);

	m_menuTxt.setFont(*Resources::getResource().getFont());
	m_menuTxt.setString("MENU");
	m_menuTxt.setStyle(sf::Text::Bold);
	m_menuTxt.setPosition(445.f, 615.f);
}

//-------------------------------------------------
void MainMenu::drawMainMenu(sf::RenderWindow* window, int soundState) const
{
	window->draw(m_mainBg);
	window->draw(m_startGameBtn);
	window->draw(m_startGameTxt);
	window->draw(m_helpBtn);
	window->draw(m_helpTxt);
	window->draw(m_soundBtn);
	if (soundState == OFF)
	{
		window->draw(m_soundTxt);
	}
	window->draw(m_exitGameBtn);
	window->draw(m_exitGameTxt);
}

//-------------------------------------------------
void MainMenu::drawHelp(sf::RenderWindow* window, int soundState) const
{
	window->draw(m_helpBg);
	window->draw(m_backBtn);
	window->draw(m_backTxt);
	window->draw(m_soundBtn);
	if (soundState == OFF)
	{
		window->draw(m_soundTxt);
	}
}

//-------------------------------------------------
void MainMenu::drawPause(sf::RenderWindow* window, int soundState) const
{
	window->draw(m_startGameBtn);
	window->draw(m_continueTxt);
	window->draw(m_soundBtn);
	if (soundState == OFF)
	{
		window->draw(m_soundTxt);
	}
	window->draw(m_exitGameBtn);
	window->draw(m_menuTxt);
}

//-------------------------------------------------
void MainMenu::changeColorWhilePointing(sf::RenderWindow* window)
{
	//menu buttons
	//----------------------------------------------
	sf::Vector2i mouseLoc = sf::Mouse::getPosition(*window);
	if (m_startGameBtn.getGlobalBounds().contains(mouseLoc.x, mouseLoc.y))
	{
		m_startGameTxt.setFillColor(sf::Color::Green);
		m_continueTxt.setFillColor(sf::Color::Green);
	}
	else
	{
		m_startGameTxt.setFillColor(sf::Color::White);
		m_continueTxt.setFillColor(sf::Color::White);
	}

	if (m_helpTxt.getGlobalBounds().contains(mouseLoc.x, mouseLoc.y))
	{
		m_helpTxt.setFillColor(sf::Color::Green);
	}
	else
	{
		m_helpTxt.setFillColor(sf::Color::White);
	}

	if (m_exitGameBtn.getGlobalBounds().contains(mouseLoc.x, mouseLoc.y))
	{
		m_exitGameTxt.setFillColor(sf::Color::Green);
		m_menuTxt.setFillColor(sf::Color::Green);
		m_backTxt.setFillColor(sf::Color::Green);
	}
	else
	{
		m_exitGameTxt.setFillColor(sf::Color::White);
		m_menuTxt.setFillColor(sf::Color::White);
		m_backTxt.setFillColor(sf::Color::White);
	}
	
	//help buttons
	//----------------------------------------------
	if (m_backBtn.getGlobalBounds().contains(mouseLoc.x, mouseLoc.y))
	{
		m_backTxt.setFillColor(sf::Color::Green);
	}
	else
	{
		m_backTxt.setFillColor(sf::Color::White);
	}
}

//-------------------------------------------------
int MainMenu::buttonPressed(sf::RenderWindow* window, const sf::Event::MouseButtonEvent& event, int gameState)
{
	if (gameState == MAIN_MENU) {
		if (m_startGameBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
		{
			return GAME;
		}
		else if (m_helpBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
		{
			return HELP;
		}
		else if (m_exitGameBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
		{
			return EXIT;
		}
	}
	else if(gameState == HELP)
	{
		if (m_backBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
		{
			return MAIN_MENU;
		}
		return HELP;
	}
	else if (gameState == PAUSE)
	{
		if (m_startGameBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
		{
			return GAME;
		}
		else if (m_exitGameBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
		{
			return MAIN_MENU;
		}
		return PAUSE;
	}
	return MAIN_MENU;
}

//-------------------------------------------------
int MainMenu::soundButtonPressed(sf::RenderWindow* window, const sf::Event::MouseButtonEvent& event, int soundState)
{
	if (m_soundBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
	{
		if (soundState == ON)
		{
			return OFF;
		}
		return ON;
	}
	return soundState;
}
