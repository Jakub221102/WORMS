#include <SFML/Audio.hpp>
#include <iostream>

#ifndef SOUND_CLASS
#define SOUND_CLASS

class SoundOperator
{
public:
	void play5secTimer();
	void playBaseballBatHit();
	void playCounting3sec();
	void playDynamiteFuse();
	void playEndingBell();
	void playGrenadeExplosion();
	void playGrenadePin();
	void playGroundFall();
	void playGunReload();
	void playTNTexplosion();

	void setSF(std::string filename);
	void playSound(sf::SoundBuffer &SF_buffer, sf::Sound &SF_sound);
	SoundOperator() {}
};

#endif


