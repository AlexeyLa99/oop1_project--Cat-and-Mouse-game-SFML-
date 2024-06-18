#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::run()
{
	Window window;

	while (window.windowIsOpen()) {
		window.render();
		int menuAction = window.pollEvent();
		switch (menuAction)
		{
			case START_GAME:
			{
				break;
			}
			/*case OPEN_HELP:
			{
				break;
			}*/
			case EXIT_GAME:
			{
				break;
			}
			default:
				break;
			}
	}
}

