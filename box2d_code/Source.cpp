#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "../BasicGraphicsUtilities/window.h"
#include "../BasicGraphicsUtilities/animated_object.h"
#include "objects.h"

using std::string;
using std::cout;
using std::endl;

float deltaTime;


int main() {
	cout << "Hello World" << endl;
	GR::Window wormsWindow(deltaTime, { 0.0, 0.0, 200.0f, 200.0f });

	return 0;
}

