#include "SoundResources.h"

//-------------------------------------------------
SoundResources::SoundResources()
{
	for (size_t i = 0; i < BACK_SOUND_NUM; i++)
	{
		m_backgroundMusic[i].openFromFile(m_backgroundNames[i]);
	}
	for (size_t i = 0; i < SOUND_NUM; i++)
	{
		m_buffers[i].loadFromFile(m_soundNames[i]);
		m_sound[i].setBuffer(m_buffers[i]);
	}
	
}

//-------------------------------------------------
SoundResources::~SoundResources()
{
}

//-------------------------------------------------
SoundResources& SoundResources::getSound()
{
	static SoundResources sound;
	return sound;
}

//-------------------------------------------------
void SoundResources::playBackground(int sound)
{
	if (m_backgroundMusic[sound].getStatus() != sf::SoundSource::Playing)
	{
		m_backgroundMusic[sound].setLoop(true);
		m_backgroundMusic[sound].play();
	}
}

//-------------------------------------------------
void SoundResources::stopBackground(int sound)
{
	m_backgroundMusic[sound].stop();
}

//-------------------------------------------------
void SoundResources::playSound(int sound)
{
	m_sound[sound].play();
}