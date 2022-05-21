#pragma once

#include "SFML/Graphics.hpp"

#include <unordered_map>
#include <algorithm>
#include <vector>
//#include <iostream>

namespace GR {
	template<class Scope, class KeyType>
	class EventManager {
		std::unordered_map<KeyType, void (Scope::*)()> keyBindings;
		std::unordered_map<KeyType, std::vector<float>> arguments;
	public:
		void use(Scope& object, KeyType keyCode);
		void addBinding(KeyType keyCode, void (Scope::* pointer)());
		void removeBinding(KeyType keyCode);
		void setArguments(KeyType keyCode, const std::vector<float>& arguments);
		std::vector<float> getArguments(KeyType keyCode) const;
		auto getPointer(KeyType keyCode) -> void (Scope::*)() const;
	};

	template<class Scope, class KeyType>
	std::vector<float> EventManager<Scope, KeyType>::getArguments(KeyType keyCode) const {
		auto argumentsList = arguments.find(keyCode);
		if (argumentsList != arguments.end())
			return argumentsList->second;
		return std::vector<float>();
	}

	template<class Scope, class KeyType>
	void EventManager<Scope, KeyType>::setArguments(KeyType keyCode, const std::vector<float>& argument) {
		auto argumentsList = arguments.find(keyCode);
		if (argumentsList != arguments.end())
			argumentsList->second = argument;
	}


	template<class Scope, class KeyCode>
	void EventManager<Scope, KeyCode>::use(Scope& object, KeyCode keyCode) {
		if (keyBindings.find(keyCode) == keyBindings.end()) return;
		(object.*(keyBindings[keyCode]))();
	}

	template<class Scope, class KeyType>
	void EventManager<Scope, KeyType>::addBinding(KeyType keyCode, void (Scope::* pointer)()) {
		keyBindings.insert({ keyCode, pointer });
		arguments.insert({ keyCode, {} });
	}

	template<class Scope, class KeyType>
	void EventManager<Scope, KeyType>::removeBinding(KeyType keyCode) {
		keyBindings.erase(keyCode);
		arguments.erase(keyCode);
	}

	template<class Scope, class KeyType>
	auto EventManager<Scope, KeyType>::getPointer(KeyType keyCode) -> void (Scope::*)() const {
		return keyBindings[keyCode];
	}
}

namespace GR {
	template<class Scope, class KeyType>
	class RealTimeInputManager {
	protected:
		std::vector<std::pair<KeyType, void (Scope::*)()>> keyBindings;
		std::unordered_map<KeyType, std::vector<float>> arguments;
	public:
		void addBinding(KeyType keyCode, void (Scope::* pointer)());
		void removeBinding(KeyType keyCode);
		void setArguments(KeyType keyCode, const std::vector<float>& arguments);
		std::vector<float> getArguments(KeyType keyCode) const;
		auto getPointer(KeyType keyCode) -> void (Scope::*)() const;
	};


	template<class Scope, class KeyType>
	void RealTimeInputManager<Scope, KeyType>::addBinding(KeyType keyCode, void (Scope::* pointer)()) {
		keyBindings.push_back({ keyCode, pointer });
		arguments.insert({ keyCode, {} });
	}

	template<class Scope, class KeyType>
	void RealTimeInputManager<Scope, KeyType>::removeBinding(KeyType keyCode) {
		keyBindings.erase(keyCode);
		arguments.erase(keyCode);
	}

	template<class Scope, class KeyType>
	std::vector<float> RealTimeInputManager<Scope, KeyType>::getArguments(KeyType keyCode) const {
		auto argumentsList = arguments.find(keyCode);
		if (argumentsList != arguments.end())
			return argumentsList->second;
		return std::vector<float>();
	}

	template<class Scope, class KeyType>
	void RealTimeInputManager<Scope, KeyType>::setArguments(KeyType keyCode, const std::vector<float>& argument) {
		auto argumentsList = arguments.find(keyCode);
		if (argumentsList != arguments.end())
			argumentsList->second = argument;
	}

	template<class Scope, class KeyType>
	auto RealTimeInputManager<Scope, KeyType>::getPointer(KeyType keyCode) -> void (Scope::*)() const {
		return keyBindings[keyCode];
	}
}

namespace GR {
	template<class Scope, class KeyType>
	class RealTimeMouseManager : public RealTimeInputManager<Scope, KeyType> {
	public:
		void listenAndUseAllMouseButtons(Scope& object);
	};

	template<class Scope, class KeyType>
	void RealTimeMouseManager<Scope, KeyType>::listenAndUseAllMouseButtons(Scope& object) {
		for (auto& el : this->keyBindings) {
			if (sf::Mouse::isButtonPressed(el.first))
				(object.*(el.second))();
		}
	}
}

namespace GR {
	template<class Scope, class KeyType>
	class RealTimeKeyboardManager : public RealTimeInputManager<Scope, KeyType> {
	public:
		void listenAndUseAllKeys(Scope& object);
	};

	template<class Scope, class KeyType>
	void RealTimeKeyboardManager<Scope, KeyType>::listenAndUseAllKeys(Scope& object) {
		for (auto& el : this->keyBindings) {
			if (sf::Keyboard::isKeyPressed(el.first))
				(object.*(el.second))();
		}
	}
}