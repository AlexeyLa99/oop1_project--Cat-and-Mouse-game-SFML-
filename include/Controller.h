#pragma once

#include <SFML/Graphics.hpp>


#include <ConstMembers.h>
#include <MainMenu.h>
#include <Board.h>

class Controller
{
public:
	Controller();
	~Controller();

	void run();

	void updateLevel();
	void pollEvent();
	void menuRun();
	
	void screen(int texture);
	void returnToMenu();

	void soundManager(int soundState);
	sf::Sprite initBackGround();


private:
	sf::RenderWindow m_window;

	sf::Texture m_texture[IMAGE_NUMBER];
	
	MainMenu m_mainMenu;

	Board m_board;

	int m_level;

	int m_gameState = 0;
	int m_soundState = 1;
};
