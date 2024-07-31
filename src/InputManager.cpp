#include "InputManager.h"

#define JOYSTICK_DEAD_ZONE 7000

bool InputManager::m_mouseIsPressed = bool();

int2 InputManager::m_mouseCoor = int2();
int2 InputManager::m_joystickPosition = int2();
int2 InputManager::m_secondstickPosition = int2();

const Uint8* InputManager::m_keyboardState = nullptr;

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::init()
{
	joysticktest = SDL_JoystickOpen(0);
}

void InputManager::setMouseMultiply(float2 multyplier)
{
	m_mouseMultiply.x = multyplier.x;
	m_mouseMultiply.y = multyplier.y;
}

void InputManager::handleInput()
{
	m_mouseIsPressed = false;
	//Events for the mouse
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&(m_mouseCoor.x), &(m_mouseCoor.y));

			m_mouseCoor.x *= m_mouseMultiply.x;
			m_mouseCoor.y *= m_mouseMultiply.y;

			break;
		case SDL_MOUSEBUTTONDOWN:
			if (m_event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseIsPressed = true;
			}
			break;

		case SDL_JOYAXISMOTION:
			if (m_event.jaxis.axis == 0)
			{
				if ((m_event.jaxis.value < -JOYSTICK_DEAD_ZONE) || (m_event.jaxis.value > JOYSTICK_DEAD_ZONE))
				{
					m_joystickPosition.x = m_event.jaxis.value;

				}
				else
				{
					m_joystickPosition.x = 0;
				}
			}
			if (m_event.jaxis.axis == 1)
			{
				if ((m_event.jaxis.value < -JOYSTICK_DEAD_ZONE) || (m_event.jaxis.value > JOYSTICK_DEAD_ZONE))
				{
					m_joystickPosition.y = m_event.jaxis.value;
				}
				else {
					m_joystickPosition.y = 0;

				}
			}
			if (m_event.jaxis.axis == 2)
			{
				if ((m_event.jaxis.value < -JOYSTICK_DEAD_ZONE) || (m_event.jaxis.value > JOYSTICK_DEAD_ZONE))
				{
					m_secondstickPosition.x = m_event.jaxis.value;
				}
				else {
					m_secondstickPosition.x = 0;

				}
			}

			if (m_event.jaxis.axis == 3)
			{
				if ((m_event.jaxis.value < -JOYSTICK_DEAD_ZONE) || (m_event.jaxis.value > JOYSTICK_DEAD_ZONE))
				{
					m_secondstickPosition.y = m_event.jaxis.value;
				}
				else {
					m_secondstickPosition.y = 0;
				}
			}
			
			
			break;
		}
	}
	m_keyboardState = SDL_GetKeyboardState(NULL);
}

bool InputManager::isMousePressed()
{
	return m_mouseIsPressed;
}

bool isAnyKeyPressed()
{
	int numOfKeys = 322;

	for (int i = 0; i < numOfKeys; i++)
	{
		if (InputManager::m_keyboardState[i])
		{
			return true;
		}
	}

	return false;
}

bool isKeyPressed(SDL_Scancode code)
{
	return InputManager::m_keyboardState[code];
}

