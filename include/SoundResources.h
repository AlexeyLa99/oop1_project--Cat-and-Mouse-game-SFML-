#pragma once 
#include <SFML/Audio.hpp>
#include "ConstMembers.h"

class SoundResources {
public:
	SoundResources();
	~SoundResources();

	static SoundResources& getSound();
	void playBackground(int);
	void stopBackground(int);

	void playSound(int);

private:
	std::string m_backgroundNames[BACK_SOUND_NUM] = {"menuSound.ogg", "gameSound.ogg"};
	
	std::string m_soundNames[SOUND_NUM] = { "mouseEat.ogg", "catEat.ogg", "doorOpen.ogg",
											"pickKey.ogg", "levelUp.ogg", "addTime.ogg", "freeze.ogg",
											"winGame.ogg", "gameOver.ogg", "addLife.ogg", "pickGift.ogg"};
	sf::Music m_backgroundMusic[BACK_SOUND_NUM];
	sf::SoundBuffer m_buffers[SOUND_NUM];;
	sf::Sound m_sound[SOUND_NUM];
};