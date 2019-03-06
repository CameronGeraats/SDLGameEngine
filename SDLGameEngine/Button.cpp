#include "Button.h"
//#include "FSM.h"
#include "Game.h"
#include "Shooter.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Rect.h"
#include "Scene1.h"

Button::Button(SDL_Rect d)
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
}

//Button::Button(const char* s, SDL_Rect d)
Button::Button(SDL_Rect d, Sprite* sp)
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
}

Button::~Button()
{
	SDL_DestroyTexture(m_pText);
}

void Button::Update()
{
	SDL_Rect mouseXY = Input::GetMousePosition();
	SDL_MouseButtonEvent mouse; // Temporary event that is used for finding specific mouse events (LEFT or RIGHT button, Up or Down State, etc)
	mouse.button = SDL_BUTTON_LEFT;

	if (mouseXY.x < (m_rDst.x + m_rDst.w) && mouseXY.x > m_rDst.x && // If cursor is within X bounds
		mouseXY.y < (m_rDst.y + m_rDst.h) && mouseXY.y > m_rDst.y)   // And cursor is within Y bounds
	{
		
		if (Input::GetMouseButtonDown(mouse) && m_bReleased)
		{
			m_iFrame = MOUSE_DOWN; // For animated buttons
			m_bReleased = false;
			//Rect r();
			//m_pSprite->ChangeFrame();
			dynamic_cast<Shooter*>(game)->switchSceneTo = new Scene1();
		}
		else if (Input::GetMouseButtonUp(mouse))
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
	//int mx = Game::Instance()->GetMouseX();
	//int my = Game::Instance()->GetMouseY();
	//if (mx < (m_rDst.x + m_rDst.w) && mx > m_rDst.x && // If cursor is within X bounds
	//	my < (m_rDst.y + m_rDst.h) && my > m_rDst.y)   // And cursor is within Y bounds
	//{
	//	if (Game::Instance()->GetLeftMouse() && m_bReleased)
	//	{
	//		m_iFrame = MOUSE_DOWN;
	//		m_bReleased = false;
	//	}
	//	else if (!Game::Instance()->GetLeftMouse())
	//	{
	//		m_bReleased = true;
	//		m_iFrame = MOUSE_OVER;
	//	}
	//}
	//else
	//	m_iFrame = MOUSE_UP;
}

/*void Button::Render()
{
	//m_rSrc.x = m_rDst.w * m_iFrame; // Not needed if I dont have animation
		SDL_RenderCopy(Game::gRenderer, m_pText, &m_rSrc, &m_rDst);
	//m_rSrc.x = m_rDst.w * m_iFrame;
	//SDL_RenderCopy(Game::Instance()->GetRenderer(), m_pText, &m_rSrc, &m_rDst);
}*/