#pragma once
#include <SDL.h>
#include "Module.h"
#include <list>
#include "Vector2.h"
class Input :
	public Module
{
public:
	Input();
	~Input();
	//void Start();
	void Update();
	static bool GetMouseButtonDown(Uint8 const &button);
	static bool GetMouseButton(Uint8 const &button);
	static bool GetMouseButtonUp(Uint8 const &button);
	static bool GetKeyDown(SDL_Keycode const &key);
	static bool GetKey(SDL_Keycode const &key);
	static bool GetKeyUp(SDL_Keycode const &key);
	static const Vector2 GetMousePosition();
private:
	//Uint8* keyStates;
	static std::list<SDL_Keycode> keyDownEvents;
	static std::list<SDL_Keycode> keyHoldEvents;
	static std::list<SDL_Keycode> keyUpEvents;

	static std::list<Uint8> mouseDownEvents;
	static std::list<Uint8> mouseHoldEvents;
	static std::list<Uint8> mouseUpEvents;
};
