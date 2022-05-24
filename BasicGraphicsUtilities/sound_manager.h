#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include "SFML/Audio.hpp"

namespace GR {
	class SoundManager {
		sf::Music backGroundMusic;
		std::unordered_map<std::string, sf::Sound> sounds;
		std::vector<sf::SoundBuffer> buffers;
	public:
		SoundManager(const std::string& filepath);
		void playSound(const std::string& soundName);
		void setBackgroundMusic(const std::string& musicPath);
		void playBackgroundMusic();
	};
}