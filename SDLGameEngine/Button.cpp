#include "Button.h"
//#include "FSM.h"
#include "Game.h"
#include "Shooter.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Rect.h"
#include "Scene1.h"
#include "Vector2.h"

Button::Button(SDL_Rect d, buttonTypes butType)
{
	/// Set the button image. You should have some fail checking just in case. 
//m_pSurf = IMG_Load(s);
		///m_pText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), m_pSurf);
//m_pText = SDL_CreateTextureFromSurface(Game::gRenderer, m_pSurf);
//SDL_FreeSurface(m_pSurf);*/
	m_bReleased = true;
	m_rDst = d;
	m_rSrc.x = m_rSrc.y = 0;
	m_rSrc.w = m_rDst.w;
	m_rSrc.h = m_rDst.h;
	buttonType = butType;
}

//Button::Button(const char* s, SDL_Rect d)
Button::Button(SDL_Rect d, Sprite* sp, buttonTypes butType)
{
					/// Set the button image. You should have some fail checking just in case. 
			//m_pSurf = IMG_Load(s);
					///m_pText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), m_pSurf);
			//m_pText = SDL_CreateTextureFromSurface(Game::gRenderer, m_pSurf);
			//SDL_FreeSurface(m_pSurf);*/
	m_bReleased = true;
	m_rDst = d;
	m_rSrc.x = m_rSrc.y = 0;
	m_rSrc.w = m_rDst.w;
	m_rSrc.h = m_rDst.h;
	m_pSprite = sp;
	buttonType = butType;
}

Button::~Button()
{
	SDL_DestroyTexture(m_pText);
}

void Button::Update()
{
	const Vector2 mouseXY = Input::GetMousePosition();
	if (mouseXY.x < (m_rDst.x + m_rDst.w) && mouseXY.x > m_rDst.x && // If cursor is within X bounds
		mouseXY.y < (m_rDst.y + m_rDst.h) && mouseXY.y > m_rDst.y)   // And cursor is within Y bounds
	{

		if (Input::GetMouseButtonDown(SDL_BUTTON_LEFT) && m_bReleased)
		{
			m_iFrame = MOUSE_DOWN; // For animated buttons
			m_bReleased = false;
			//m_pSprite->ChangeFrame();
			if (buttonType == Button::START_GAME)
				dynamic_cast<Shooter*>(game)->switchSceneTo = new Scene1();
			else if (buttonType == Button::EXIT_GAME)
				Game::quit = true;
			else if (buttonType == Button::INSTRUCTIONS)
				;
		}
		else if (Input::GetMouseButtonUp(SDL_BUTTON_LEFT))
		{
			m_bReleased = true;
			m_iFrame = MOUSE_OVER;
			//m_pSprite->ChangeFrame();
		}
	}
	else
	{
		m_iFrame = MOUSE_UP;
		//if (Input::GetMouseButtonUp(mouse))
			//m_bReleased = true;
	}
}