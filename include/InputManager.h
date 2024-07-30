#pragma once

#include "Engine.h"
#include "Player.h";


class InputManager
{
public:
	InputManager();
	~InputManager();

	static int2 m_mouseCoor;
	static int2 m_joystickPosition; 
	static const Uint8* m_keyboardState;

	void init();
	void handleInput();
	void setMouseMultiply(float2 multyplier);

	static bool isMousePressed();

	SDL_Joystick* joysticktest;

private:
	SDL_Event m_event;

	float2 m_mouseMultiply;

	static bool m_mouseIsPressed;
};

bool isAnyKeyPressed();

bool isKeyPressed(SDL_Scancode code);
