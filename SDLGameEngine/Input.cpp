#include "Input.h"
#include <iostream>
#include "Game.h"
#include <algorithm>

std::list<SDL_Keycode> Input::keyDownEvents = std::list<SDL_Keycode>({});
std::list<SDL_Keycode> Input::keyHoldEvents = std::list<SDL_Keycode>({});
std::list<SDL_Keycode> Input::keyUpEvents = std::list<SDL_Keycode>({});
std::list<SDL_MouseButtonEvent> Input::mouseUpEvents = std::list<SDL_MouseButtonEvent>({});
std::list<SDL_MouseButtonEvent> Input::mouseDownEvents = std::list<SDL_MouseButtonEvent>({});
std::list<SDL_MouseMotionEvent> Input::mouseMoveEvents = std::list<SDL_MouseMotionEvent>({});


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
		
		case SDL_MOUSEBUTTONDOWN:
			//if (e.button.button == SDL_BUTTON_LEFT)
				//m_bLeftMouse = true;
			// if()
			mouseDownEvents.push_back(e.button);
			break;

		case SDL_MOUSEBUTTONUP:
			//if (e.button.button == SDL_BUTTON_LEFT)
				//m_bLeftMouse = false;
			mouseUpEvents.push_back(e.button);
			break;

		case SDL_MOUSEMOTION: // Not needed if I just need mouse position and not motion
			//mouseMoveEvents.push_back(e.motion); // unneccesary? useful if tracking delta x/y?
			//SDL_GetMouseState(&m_iMouseX, &m_iMouseY);
			GetMousePosition();
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

//bool Input::GetMouseButtonDown(SDL_MouseButtonEvent button)
//{
//	for (SDL_Event* e : currentEvents)
//	{
//		if (e->type == SDL_MOUSEBUTTONDOWN && e->button.type == button.type)
//		{
//
//		}
//	}
//	return true;
//}
bool Input::GetMouseButtonDown(SDL_MouseButtonEvent button)
{
	for (SDL_MouseButtonEvent mbe : mouseDownEvents)
	{
		if (mbe.type == SDL_MOUSEBUTTONDOWN && mbe.button == button.button)
		{ 
			return true;
		}
	}
	return false;
	//button.button = SDL_BUTTON_LEFT;
}

bool Input::GetMouseButtonUp(SDL_MouseButtonEvent button)
{
	for (SDL_MouseButtonEvent mbe : mouseUpEvents)
	{
		if (mbe.type == SDL_MOUSEBUTTONUP && mbe.button == button.button)
		{
			return true;
		}
	}
	return false;
}

//SDL_Rect Input::GetMousePosition()
//{
//	int m_iMouseX, m_iMouseY;
//	SDL_GetMouseState(&m_iMouseX, &m_iMouseY);
//	SDL_Rect xy;
//	xy.h = xy.w = 0;
//	xy.x = m_iMouseX;
//	xy.y = m_iMouseY;
//	return xy;
//}

//Transform* Input::GetMousePosition()
//{
//	int m_iMouseX, m_iMouseY;
//	SDL_GetMouseState(&m_iMouseX, &m_iMouseY);
//	static Transform* xy = new Transform;
//	xy->SetAbsolutePosition(Vector2(m_iMouseX,m_iMouseY));
//	return xy;
//}

Transform* Input::GetMousePosition()
{
	int m_iMouseX, m_iMouseY;
	SDL_GetMouseState(&m_iMouseX, &m_iMouseY);
	static Transform* xy = new Transform;
	xy->SetAbsolutePosition(Vector2(m_iMouseX ,m_iMouseY));
	return xy;
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
