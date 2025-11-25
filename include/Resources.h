#pragma once

#include "ConstMembers.h"
#include <SFML/Graphics.hpp>

class Resources
{
public:
	Resources();
	~Resources();

	//get
	static Resources& getResource();
	sf::Texture* getTexture(int);
	sf::Font* getFont();
	sf::Image* getIcon();

private:
	std::string m_imgName[IMAGE_NUMBER] = { "menuBackGround.png", "button.png", "soundButton.png", "helpBackGround.png", "gameBackGround.png",
											"mouse.png", "cat.png", "cheese.png", "wall.png", "door.png", "key.png", "present.png" , "gameOverScreen.png", "winScreen.png", "freezePresent.png",
											"lifePresent.png", "timePresent.png", "Logo.png"};

	sf::Texture m_texture[IMAGE_NUMBER];
	sf::Font m_font;

	sf::Image m_icon;
};