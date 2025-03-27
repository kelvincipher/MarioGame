#ifndef EVENT_H
#define EVENT_H

#define EVENT_OUT false

#define EVENT_IN  true


#include <SDL.h>
#include "Keyboard.h"


class Event
{
private:
	bool event = 0;
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
