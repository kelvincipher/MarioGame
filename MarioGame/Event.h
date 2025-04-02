#ifndef EVENT_H
#define EVENT_H

#define EVENT_IN	false		// Still in the game
#define EVENT_OUT	true		// Out of the game


#include <SDL.h>
#include "Keyboard.h"


class Event
{
private:
	bool event = EVENT_IN;
	Keyboard* keyboard;

public:
	Event();
	~Event();
	void PollEvent(Keyboard*);
	bool getEvent() const;
};

#endif //EVENT_H
