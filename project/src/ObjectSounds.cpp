#include "ObjectSounds.h"
#include <iostream>

#include <thread>

ObjectSounds::ObjectSounds()
{
	m_trollRoarSound.loadFromFile("trollRoarSound.wav");
	m_knockSound.loadFromFile("knockSound.wav"); 
	m_doorOpenSound.loadFromFile("doorOpenSound.wav");
	m_magicSound.loadFromFile("magicSound.wav");
	m_teleportSound.loadFromFile("teleportSound.wav");
}

void ObjectSounds::activateSound(Sound soundType)
{
	if (sound.getStatus() == sf::Sound::Playing)
		return;

	switch (soundType)
	{
	case Sound::doorOpenSound:
		sound.setBuffer(m_doorOpenSound);
		sound.play();
		break;

	case Sound::knockSound:
		sound.setBuffer(m_knockSound);
		sound.play();
		break;

	case Sound::magicSound:
		std::cout << "kuku!\n";
		sound.setBuffer(m_magicSound);
		sound.play();
		break;

	case Sound::teleportSound:
		sound.setBuffer(m_teleportSound);
		sound.play();
		break;

	case Sound::trollRoarSound:
		sound.setBuffer(m_trollRoarSound);
		sound.play();
		break;

	default:
		break;
	}
	//using namespace std::chrono_literals;
	//std::this_thread::sleep_for(5s); // 30 seconds
}
