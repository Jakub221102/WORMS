#include "texture.h"

GR::Texture::Texture(const std::string& filePath, sf::IntRect singleFrame, unsigned int count) 
	: filePath(filePath){
	texture.loadFromFile(filePath, singleFrame);
	texture.setSmooth(true);
}

sf::Texture* GR::Texture::getPixels() {
	return &texture;
}