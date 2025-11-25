#include "Resources.h"
#include "ConstMembers.h"

//-------------------------------------------------
Resources::Resources()
{
	for (size_t i = 0; i < IMAGE_NUMBER; i++)
	{
		m_texture[i].loadFromFile(m_imgName[i]);
	}
	m_font.loadFromFile("C:/Windows/Fonts/Tahoma.ttf");
	m_icon.loadFromFile(this->m_imgName[TEXTURE::logo]);
}

//-------------------------------------------------
Resources::~Resources()
{
}

//-------------------------------------------------
Resources& Resources::getResource()
{
	static Resources resource;
	return resource;
}

//-------------------------------------------------
sf::Texture* Resources::getTexture(int index)
{
	return &m_texture[index];
}

//-------------------------------------------------
sf::Font* Resources::getFont()
{
	return &m_font;
}

sf::Image* Resources::getIcon()
{
	return &m_icon;
}

