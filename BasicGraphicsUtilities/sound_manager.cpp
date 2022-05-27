#include "sound_manager.h"
#include <sstream>
#include <fstream>
#include <iostream>

GR::SoundManager::SoundManager(const std::string& filepath)
{
	std::fstream source(filepath);
	std::string line;
	while (std::getline(source, line)) {
		buffers.push_back(sf::SoundBuffer());
		std::cout << buffers.back().loadFromFile(line + ".wav") << std::endl;
		sounds.insert({ line, sf::Sound(buffers.back()) });
	}
}

void GR::SoundManager::playSound(const std::string& soundName)  {
	auto iterator = sounds.find(soundName);
	if (iterator == sounds.end()) {
		std::cout << "Could not find " << iterator->first << " in the library!" << std::endl;
		return;
	}
	iterator->second.play();
}

void GR::SoundManager::setBackgroundMusic(const std::string& musicPath) {
	backGroundMusic.openFromFile(musicPath);
}

void GR::SoundManager::playBackgroundMusic() {
	backGroundMusic.setLoop(true);
	backGroundMusic.play();
}
