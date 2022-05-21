#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

namespace GR {
	class World {
		std::vector<sf::Sprite> layers; // stack of layers to be rendered
	public:
		inline std::vector<sf::Sprite>& getLayers() { return layers; }
		inline void addLayer(const sf::Sprite& layer) { layers.push_back(layer); }
		inline void removeLastLayer() { layers.pop_back(); }
	};
}