#include "Keyboard.h"
#include <cstring>

Keyboard::Keyboard()
{
	memset(keys, 0, sizeof(keys));
}

Keyboard::~Keyboard() {}

bool Keyboard::getKey(char key) { return keys[key]; }
void Keyboard::setKey(char key) { keys[key] = true; }
void Keyboard::resetKey(char key) { keys[key] = false; }
