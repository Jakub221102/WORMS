#pragma once
#include "SFML/Graphics.hpp"
#include "input_manager.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace GR {
	class GameObject;
	const std::vector<std::pair<unsigned int, unsigned int>> resolutions = {
		{1920, 1080},
		{1440, 1080},
		{1280, 1080},
		{1280, 720},
		{720, 576},
		{704, 576},
		{544, 576},
		{480, 576}
	};

	//const std::vector<std::pair<float, float>> resolutionScales = {
	//	{1.0f, 1.0f},
	//	{1440.0f / 1920.0f, 1080.0f / 1080.0f},
	//	{1280.0f / 1920.0f, 1080.0f / 1080.0f},
	//	{1280.0f / 1920.0f, 720.0f / 1080.0f},
	//	{720.0f / 1920.0f, 576.0f / 1080.0f},
	//	{704.0f / 1920.0f, 576.0f / 1080.0f},
	//	{544.0f / 1920.0f, 576.0f / 1080.0f},
	//	{480.0f / 1920.0f, 576.0f / 1080.0f}
	//};

	class Window {
		void setup(const std::string& title, int resolutionPointer, unsigned int MSAlevel = 16);
		void destroy();
		void create();

		sf::RenderWindow window;
		sf::ContextSettings settings;
		sf::Vector2u windowSize;
		std::string windowTitle;
		sf::Vector2f resolutionScale;
		sf::Vector2i mousePosition;
		const sf::FloatRect confines;
		sf::View view;
		int resolutionPointer;
		bool isWinDone;
		bool isWinFullscreen;
		const float& deltaTime;
		float mouseWheelSpeed = 1.0f;
		float mZoom;
		//std::unordered_map<sf::Keyboard::Key, void (GR::Window::*)()> keyBindings;
		GR::EventManager<sf::Keyboard::Key, GR::Window> keyBindings;
		GR::RealTimeInputManager<sf::Mouse::Button, GR::Window> mouseButtonBindings;
	public:
		Window(float& deltaTime, sf::FloatRect confines, const std::string& title = "Window");
		~Window();

		void addKeyBinding(sf::Keyboard::Key keyCode, void (GR::Window::*pointer)());
		//void addMouseButtonBinding(sf::Mouse::Button button, void (GR::Window::* pointer)());
		void removeKeyBinding(sf::Keyboard::Key keyCode);
		//void removeMouseButtonKeyBinding(sf::Mouse::Button button);

		void beginDraw(unsigned char r=0, unsigned char g=0, unsigned char b=0, unsigned char a = 255);
		void endDraw();
		void update(float time);
		void setFramesPerSecond(unsigned int fps);

		bool isDone() const;
		bool isFullscreen() const;
		sf::Vector2u getWindowSize() const;
		void setBackGroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255);
		sf::Vector2f getMouseWorldCoords() const;

		void draw(GR::GameObject& drawable);

		// member functions to bind keys
		void toggleFullScreen();
		void close();
		void upscaleResolution();
		void downscaleResolution();
		void setMultisamplingLevel(unsigned int level);
		void setView(float x, float y, float w, float h);
		void zoom(float scale);
		void setZoomSpeed(float speed);
	};
}