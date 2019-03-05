#pragma once
#include <SDL.h>
#include "Module.h"
#include <list>
class Input:
	public Module
{
public:
	Input();
	~Input();
	//void Start();
	void Update();
	//bool GetMouseButtonDown(SDL_MouseButtonEvent button);
	static bool GetMouseButtonDown(SDL_MouseButtonEvent button);
	bool GetMouseButton(SDL_MouseButtonEvent button);
	//bool GetMouseButtonUp(SDL_MouseButtonEvent button);
	static bool GetMouseButtonUp(SDL_MouseButtonEvent button);
	static bool GetKeyDown(SDL_Keycode const &key);
	static bool GetKey(SDL_Keycode const &key);
	static bool GetKeyUp(SDL_Keycode const &key);
	static SDL_Rect GetMousePosition();
private:
	//static int m_iMouseX, m_iMouseY;
	Uint8* keyStates;
	static std::list<SDL_Keycode> keyDownEvents;
	static std::list<SDL_Keycode> keyHoldEvents;
	static std::list<SDL_Keycode> keyUpEvents;
	static std::list<SDL_MouseButtonEvent> mouseDownEvents;
	static std::list<SDL_MouseButtonEvent> mouseUpEvents;
	static std::list<SDL_MouseMotionEvent> mouseMoveEvents;
};

