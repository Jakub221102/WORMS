/*
SOURCE CODE WHICH IS RESPONSIBLE FOR EASY TESTING AND DRAWING via sfml

NOT FOR GIT
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "../box2d_code/objects.h"

#include "../BasicGraphicsUtilities/input_manager.h"
#include "../BasicGraphicsUtilities/window.h"
#include "../BasicGraphicsUtilities/static_animated_object.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

void draw(b2World&, float);

void terminalDraw(b2World& , float);

