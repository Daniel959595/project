#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


enum class Sound
{
    doorOpenSound = 0,
    trollRoarSound,
    knockSound,
    magicSound,
    teleportSound,
   

};

class ObjectSounds
{
public:
    ObjectSounds();
    void activateSound(Sound soundType);

private:

   sf::Sound sound;
   
   sf::SoundBuffer m_trollRoarSound;
   sf::SoundBuffer m_knockSound;
   sf::SoundBuffer m_doorOpenSound;
   sf::SoundBuffer m_magicSound;
   sf::SoundBuffer m_teleportSound;
   // sf::sf::SoundBuffer m_teleportSound;
   // sf::sf::SoundBuffer m_teleportSound;
};

