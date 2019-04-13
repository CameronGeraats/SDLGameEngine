#pragma once
#include "SDL.h"
#include "Component.h"
#include "Sprite.h"
//#include "TextSprite.h"
#include "TextRenderer.h"

class Button :
	public Component
{
public:
	enum buttonTypes { EXIT_GAME, START_GAME, INSTRUCTIONS, CONTINUE, BUY_DAMAGE, BUY_SPEED, BUY_FIRESPEED, UPGRADE_ARMOUR, HEAL_PLAYER };
	//Button(const char* s, SDL_Rect d);
	Button(SDL_Rect d, buttonTypes = EXIT_GAME);
	Button(SDL_Rect d, Sprite* sp, buttonTypes = EXIT_GAME);
	~Button();
	void Update();
	//void Render(); // New engine separates functionality, redundant
	bool Clicked() { return m_iFrame == 2; }
private:
	enum state { MOUSE_UP, MOUSE_OVER, MOUSE_DOWN };
	buttonTypes buttonType;
	bool m_bReleased;
	int m_iFrame;
	SDL_Rect m_rSrc;
	SDL_Rect m_rDst;
	SDL_Surface* m_pSurf;
	SDL_Texture* m_pText;
	Sprite* m_pSprite;
};