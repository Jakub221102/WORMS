#include "SoundOperator.h"
#include <stdexcept>


void SoundOperator::setSF(std::string filename)
{
	std::string path = "SoundEffects\\";
	path += filename;
	path += ".wav";
	sf::SoundBuffer SF_Buffer;
	sf::Sound SF_Sound;
	if (!SF_Buffer.loadFromFile(path))
	{
		throw std::invalid_argument("Error wav file not loaded");
	}
	playSound(SF_Buffer, SF_Sound);
}

void SoundOperator::playSound(sf::SoundBuffer& SF_buffer, sf::Sound &SF_sound)
{
	SF_sound.setBuffer(SF_buffer);
	SF_sound.play();
}

void SoundOperator::play5secTimer() {setSF("5secTimer");}
void SoundOperator::playBaseballBatHit() { setSF("BaseballBatHit"); }
void SoundOperator::playCounting3sec() { setSF("Counting3sec"); }
void SoundOperator::playDynamiteFuse() { setSF("DynamiteFuse"); }
void SoundOperator::playEndingBell() { setSF("EndingBell"); }
void SoundOperator::playGrenadeExplosion() { setSF("GrenadeExplosion"); }
void SoundOperator::playGrenadePin() { setSF("GrenadePin"); }
void SoundOperator::playGroundFall() { setSF("GroundFall"); }
void SoundOperator::playGunReload() { setSF("GunReload"); }
void SoundOperator::playTNTexplosion() { setSF("TNTexplosion"); }

