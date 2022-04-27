#pragma once

#include "SFML/Graphics.hpp"

#include <unordered_map>
#include <iostream>

namespace GR {
	template<class KeyType, class Scope>
	class EventManager {
		std::unordered_map<KeyType, void (Scope::*)()> keyBindings;
	public:
		void use(Scope& object, KeyType keyCode);
		void addKeyBinding(KeyType keyCode, void (Scope::* pointer)());
		void removeKeyBinding(KeyType keyCode);
		auto getPointer(KeyType keyCode) -> void (Scope::*)() const;
	};

	template<class KeyType, class Scope>
	void EventManager<KeyType, Scope>::use(Scope& object, KeyType keyCode) {
		if (keyBindings.find(keyCode) == keyBindings.end()) return;
		(object.*(keyBindings[keyCode]))();
	}

	template<class KeyType, class Scope>
	void EventManager<KeyType, Scope>::addKeyBinding(KeyType keyCode, void (Scope::* pointer)()) {
		keyBindings.insert({ keyCode, pointer });
	}

	template<class KeyType, class Scope>
	void EventManager<KeyType, Scope>::removeKeyBinding(KeyType keyCode) {
		keyBindings.erase(keyCode);
	}

	template<class KeyType, class Scope>
	auto EventManager<KeyType, Scope>::getPointer(KeyType keyCode) -> void (Scope::*)() const {
		return keyBindings[keyCode];
	}
}