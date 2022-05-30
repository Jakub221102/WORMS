#include "text.h"
#include <iostream>

GR::Text::Text(const std::string& txt, std::string font_path)
	: translation(0.0f, 0.0f), txt(txt) {
	if (!font.loadFromFile(font_path)) {
		std::cout << "Could not open font file" << std::endl;
	}
	text = sf::Text(txt, font);
}

void GR::Text::setScale(float x, float y) {
	text.setScale({ x, y });
}

void GR::Text::setColor(unsigned char r, unsigned char g, unsigned char b) {
	text.setFillColor({r, g, b});
}

void GR::Text::setString(const std::string& text) {
	this->text.setString(text);
	txt = text;
}

void GR::Text::setRelativeTranslation(float x, float y) {
	translation = { x, y };
}

void GR::Text::setPosition(float x, float y) {
	text.setPosition(sf::Vector2f(x, y) + translation);
}

void GR::Text::setCharackterSize(unsigned int size) {
	text.setCharacterSize(size);
}

std::string GR::Text::getString() const {
	return txt;
}

bool GR::operator==(const GR::Text& first, const GR::Text& second)
{
	return first.text.getString() == second.text.getString();
}

sf::Text& GR::Text::getText() {
	return text;
}

sf::Vector2f GR::Text::getTranslation() {
	return translation;
}

void GR::Text::setOrigin(float x, float y) {
	text.setOrigin(x, y);
}