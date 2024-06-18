#pragma once

#include <Window.h>

class Controller
{
public:
	Controller();
	virtual ~Controller();

	void run();

private:
	Window m_window;
};
