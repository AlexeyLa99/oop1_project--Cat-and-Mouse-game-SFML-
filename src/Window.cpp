#include "Window.h"

Window::Window()
{
	initWindow();
}

Window::~Window()
{
}

void Window::initWindow()
{
	m_mainWindow.create(sf::VideoMode(1500, 850), "Cat and Mouse", sf::Style::Default);
	m_mainWindow.draw(m_Background);
}


bool Window::windowIsOpen()
{
	return m_mainWindow.isOpen();
}

int Window::pollEvent()
{
	while (m_mainWindow.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
		{
			m_clearWindow = false;
			m_mainWindow.close();
			return 0;
		}
		case sf::Event::MouseButtonPressed:
			return handlerButtonPress();
			break;

		default:
			return 0;
		}

	}
}

int Window::handlerButtonPress()
{
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		if (sf::Event::MouseButtonReleased)
		{
			return CheckSpecificButton(i);
		}
	}
}

void Window::initMenu()
{
	initButtons();
	initTexture();
}

void Window::initTexture()
{
	m_texture.loadFromFile("BackGroundMain.png");

	m_textureButtons[EButtons::start].loadFromFile("ButtonStart.png");
	//m_textureButtons[EButtons::help].loadFromFile("ButtonHelp.png");
	m_textureButtons[EButtons::exit].loadFromFile("ButtonExit.png");
}

void Window::drawButtons()
{
	for (int i = 0; i < MAX_BUTTONS; i++)
	{
		m_mainWindow.draw(m_buttons[i]);
	}
}

void Window::drawBackground()
{
	m_mainWindow.draw(m_Background);
}

int Window::CheckSpecificButton(int button)
{
	switch (button)
	{
	case EButtons::start:

		return 1;

	/**case EButtons::help:

		break;
	*/
	case EButtons::exit:

		return 0;
	default:
		return 0;
	}
}

void Window::render()
{
	m_mainWindow.clear();

	//drew on window
	drawBackground();
	drawButtons();
}

void Window::initButtons()
{
	for (int i = 0; i < MAX_BUTTONS; ++i)
	{
		m_buttons[i].setTexture(m_textureButtons[i]);//texture 150.f, 69.f
		m_buttons[i].setPosition(sf::Vector2f(100.f, 170.f + ((60.f + 50) * i)));
	}
}
