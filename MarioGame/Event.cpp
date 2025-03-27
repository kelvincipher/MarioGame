#include "Event.h"


Event::Event() : event(0), keyboard(nullptr) {}
Event::~Event() {}

void Event::PollEvent(Keyboard* keyboard)
{
	this->keyboard = keyboard;
	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		// System event
		if (e.type == SDL_QUIT) event = EVENT_OUT;

		// Keyboard event
		if (keyboard) {
			if (e.type == SDL_KEYDOWN) { keyboard->setKey(e.key.keysym.scancode); }
			if (e.type == SDL_KEYUP) { keyboard->resetKey(e.key.keysym.scancode); }
		}
	}
}

bool Event::getEvent(bool event) { return event; }
void Event::setEvent(bool _event) { event = _event; }
void Event::resetEvent(bool event) { event = EVENT_IN; }