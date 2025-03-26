#ifndef EVENT_H
#define EVENT_H

#define EVENT_OUT true
#define EVENT_IN  false

#include <SDL.h>
#include "Keyboard.h"


class Event
{
private:
	bool event;
	Keyboard* keyboard;

public:
	Event();
	~Event();
	void PollEvent(Keyboard*);
	bool getEvent(bool);
	void setEvent(bool);
	void resetEvent(bool);
};

#endif //EVENT_H
