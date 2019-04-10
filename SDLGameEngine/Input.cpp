#include "Input.h"
#include <iostream>
#include "Game.h"
#include <algorithm>

std::list<SDL_Keycode> Input::keyDownEvents = std::list<SDL_Keycode>({});
std::list<SDL_Keycode> Input::keyHoldEvents = std::list<SDL_Keycode>({});
std::list<SDL_Keycode> Input::keyUpEvents = std::list<SDL_Keycode>({});

std::list<Uint8> Input::mouseDownEvents = std::list<Uint8>({});
std::list<Uint8> Input::mouseHoldEvents = std::list<Uint8>({});
std::list<Uint8> Input::mouseUpEvents = std::list<Uint8>({});


Input::Input()
{
}


Input::~Input()
{
}

void Input::Update()
{
	/*for (std::list<SDL_Event*>::iterator it = currentEvents.begin(); it != currentEvents.end(); ++it)
	{
		delete *it;
		break;
	}
	currentEvents.clear();*/

	keyDownEvents.clear();
	keyUpEvents.clear();
	mouseDownEvents.clear();
	mouseUpEvents.clear();
	//Event handler
	SDL_Event e;
	int i = 0;
	while (SDL_PollEvent(&e))
	{
		i++;
		switch (e.type)
		{
		case SDL_QUIT:
			Game::quit = true;

		case SDL_KEYDOWN:
			if (!Input::GetKey(e.key.keysym.sym))
			{
				keyDownEvents.push_back(e.key.keysym.sym);
				keyHoldEvents.push_back(e.key.keysym.sym);
			}
			break;

		case SDL_KEYUP:
			keyUpEvents.push_back(e.key.keysym.sym);
			keyHoldEvents.remove(e.key.keysym.sym);
			keyDownEvents.remove(e.key.keysym.sym);
			break;
		
		case SDL_MOUSEMOTION: // Not needed if I just need mouse position and not motion
			//mouseMoveEvents.push_back(e.motion); // unneccesary? useful if tracking delta x/y?
			//SDL_GetMouseState(&m_iMouseX, &m_iMouseY);
			GetMousePosition();
			break;

		case SDL_MOUSEBUTTONDOWN:
			if (!Input::GetKey(e.key.keysym.sym))
			{
				mouseDownEvents.push_back(e.button.button);
				mouseHoldEvents.push_back(e.button.button);
			}
			break;

		case SDL_MOUSEBUTTONUP:
			mouseUpEvents.push_back(e.button.button);
			mouseHoldEvents.remove(e.button.button);
			mouseDownEvents.remove(e.button.button);
			break;

		default:
			break;
		}
	}
	/*if (i > 0)
	{
		std::cout << "No. of events = " << i << std::endl;
	}*/
}

bool Input::GetKeyDown(SDL_Keycode const &key)
{
	return std::find(keyDownEvents.begin(), keyDownEvents.end(), key) != keyDownEvents.end();
}

bool Input::GetKey(SDL_Keycode const &key)
{
	return std::find(keyHoldEvents.begin(), keyHoldEvents.end(), key) != keyHoldEvents.end();
}

bool Input::GetKeyUp(SDL_Keycode const &key)
{
	return std::find(keyUpEvents.begin(), keyUpEvents.end(), key) != keyUpEvents.end();
}

bool Input::GetMouseButtonDown(Uint8 const &button)
{
	return std::find(mouseDownEvents.begin(), mouseDownEvents.end(), button) != mouseDownEvents.end();
}

bool Input::GetMouseButton(Uint8 const &button)
{
	return std::find(mouseHoldEvents.begin(), mouseHoldEvents.end(), button) != mouseHoldEvents.end();
}

bool Input::GetMouseButtonUp(Uint8 const &button)
{
	return std::find(mouseUpEvents.begin(), mouseUpEvents.end(), button) != mouseUpEvents.end();
}

const Vector2 Input::GetMousePosition()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	return Vector2(x, y);
}
