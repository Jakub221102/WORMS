#pragma once

#include "SFML/Graphics.hpp"

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

namespace GR {
	template<class KeyType, class Scope>
	class EventManager {
		std::unordered_map<KeyType, void (Scope::*)()> keyBindings;
	public:
		void use(Scope& object, KeyType keyCode);
		void addBinding(KeyType keyCode, void (Scope::* pointer)());
		void removeBinding(KeyType keyCode);
		auto getPointer(KeyType keyCode) -> void (Scope::*)() const;
	};

	template<class KeyType, class Scope>
	void EventManager<KeyType, Scope>::use(Scope& object, KeyType keyCode) {
		if (keyBindings.find(keyCode) == keyBindings.end()) return;
		(object.*(keyBindings[keyCode]))();
	}

	template<class KeyType, class Scope>
	void EventManager<KeyType, Scope>::addBinding(KeyType keyCode, void (Scope::* pointer)()) {
		keyBindings.insert({ keyCode, pointer });
	}

	template<class KeyType, class Scope>
	void EventManager<KeyType, Scope>::removeBinding(KeyType keyCode) {
		keyBindings.erase(keyCode);
	}

	template<class KeyType, class Scope>
	auto EventManager<KeyType, Scope>::getPointer(KeyType keyCode) -> void (Scope::*)() const {
		return keyBindings[keyCode];
	}
}

namespace GR {
	template<class KeyType, class Scope>
	class RealTimeInputManager {
		std::vector<std::pair<KeyType, void (Scope::*)()>> keyBindings;
	public:
		void listenAndUseAll(Scope& object);
		void addBinding(KeyType keyCode, void (Scope::* pointer)());
		void removeBinding(KeyType keyCode);
	};

	template<class KeyType, class Scope>
	void RealTimeInputManager<KeyType, Scope>::addBinding(KeyType keyCode, void (Scope::* pointer)()) {
		keyBindings.push_back({ keyCode, pointer });
	}

	template<class KeyType, class Scope>
	void RealTimeInputManager<KeyType, Scope>::removeBinding(KeyType keyCode) {
		std::remove_if(keyBindings.begin(), keyBindings.end(),
			[&keyCode](const std::pair<KeyType, void (Scope::*)()>& element) -> bool { return element.first == keyCode; });
	}

	template<class KeyType, class Scope>
	void RealTimeInputManager<KeyType, Scope>::listenAndUseAll(Scope& object) {
		for (auto& el : keyBindings) {
			if (sf::Keyboard::isKeyPressed(el.first))
				(object.*(el.second))();
		}
	}
}