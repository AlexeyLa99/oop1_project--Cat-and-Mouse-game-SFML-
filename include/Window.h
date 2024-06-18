#pragma once

#include <SFML/Graphics.hpp>
#include "ConstMembers.h"

class Window
{
public:
	Window();
	~Window();

	void initWindow();
	
	bool windowIsOpen();

	int pollEvent();
	int handlerButtonPress();

	void initButtons();

	void initMenu();

	//texture of the window
	void initTexture();

	void drawButtons();
	void drawBackground();

	
	//buttons
	int CheckSpecificButton(int);

	void render(); //render window

private:
	sf::Event m_event;
	sf::RenderWindow m_mainWindow; //const window

	sf::Sprite m_buttons[MAX_BUTTONS];

	//background texture
	sf::Texture m_texture;
	sf::Sprite m_Background;
	sf::Texture m_textureButtons[MAX_BUTTONS];

	bool m_clearWindow;
	
};