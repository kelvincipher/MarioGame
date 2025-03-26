#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Defs.h"

class Keyboard
{
private:
	bool keys[KEY_MAX];
public:
	Keyboard();
	~Keyboard();
	bool getKey(char);
	void setKey(char);
	void resetKey(char);
};

#endif //KEYBOARD_H
