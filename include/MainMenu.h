#pragma once 

#include <SFML/Graphics.hpp>
#include <ConstMembers.h>
#include <Resources.h>
#include <SoundResources.h>

class MainMenu
{
public:
	MainMenu();

	//resource initialization
	void initBackGrounds();
	void initButtons();

	//draw
	void drawMainMenu(sf::RenderWindow* window, int soundState) const;
	void drawHelp(sf::RenderWindow* window, int soundState) const;
	void drawPause(sf::RenderWindow* window, int soundState) const;
	void changeColorWhilePointing(sf::RenderWindow* window);

	//button pressed
	int buttonPressed(sf::RenderWindow* window, const sf::Event::MouseButtonEvent& event, int gameState);
	int soundButtonPressed(sf::RenderWindow* window, const sf::Event::MouseButtonEvent& event, int soundState);


private:
	sf::RectangleShape m_startGameBtn, m_helpBtn, m_exitGameBtn, m_soundBtn, m_backBtn,
						m_mainBg, m_helpBg;

	sf::Text m_startGameTxt, m_helpTxt, m_soundTxt, m_exitGameTxt, m_backTxt, m_menuTxt, m_continueTxt;
};