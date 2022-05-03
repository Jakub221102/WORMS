#include "texture.h"

GR::Texture::Texture(const std::string& filePath) 
	: filePath(filePath){
	texture.loadFromFile(filePath);
	texture.setSmooth(true);
}

sf::Texture* GR::Texture::getPixels() {
	return &texture;
}