#pragma once

#define windowHeight 890
#define WindowWidth 950

#define MouseSpeed 165.f
#define DumbCatSpeed 100.f
#define SmartCatSpeed 75.f

#define ADDTIME 5
#define LVLCMPLT 25
#define CHEESEPOINTS 10
#define PRESENTPOINTS 5
#define DOORPOINTS 2

#define FREEZETIME 3

const int IMAGE_NUMBER = 18;
const int MAX_BUTTONS = 5;

const int BACK_SOUND_NUM = 2;
const int SOUND_NUM = 11;

namespace BACKGROUND
{
	constexpr int menuSound = 0;
	constexpr int gameSound = 1;
}

namespace SOUND
{
	constexpr int mouseEat = 0;
	constexpr int catEat = 1;
	constexpr int doorOpen = 2;
	constexpr int pickKey = 3;
	constexpr int levelUp = 4;
	constexpr int addTime = 5;
	constexpr int freeze = 6;
	constexpr int winGame = 7;
	constexpr int gameOver = 8;
	constexpr int addLife = 9;
	constexpr int present = 10;
}


namespace TEXTURE
{
	constexpr int menuBackGround = 0;
	constexpr int button = 1;
	constexpr int soundButton = 2;
	constexpr int helpBackGround = 3;
	constexpr int gameBackGround = 4;
	constexpr int mouse = 5;
	constexpr int cat = 6;
	constexpr int cheese = 7;
	constexpr int wall = 8;
	constexpr int door = 9;
	constexpr int key = 10;
	constexpr int present = 11;
	constexpr int gameOverScreen = 12;
	constexpr int winScreen = 13;
	constexpr int freezePresent = 14;
	constexpr int lifePresent = 15;
	constexpr int timePresent = 16;
	constexpr int logo = 17;
}



enum GAME_STATE { MAIN_MENU, GAME, HELP, EXIT, PAUSE};
enum SOUND_STATE { OFF, ON };

struct Vertex {
	float m_x;
	float m_y;
};

struct Size {
	float m_x;
	float m_y;
};