#include "TextSprite.h"
#include "SDL_ttf.h"
//#include "Game.h"
#include "Shooter.h"

TextSprite::TextSprite(const char * text, Game* game) : Sprite(new Rect(0,0,0,0))
{
	Shooter* shoot = dynamic_cast<Shooter*>(game);
	//char buffer[100];
	//sprintf_s(buffer, text);

	TTF_Font* textFont = TTF_OpenFont("Assets/arial.ttf", 28);
	SDL_Color textColour = { 255, 0, 0 };
	ttfSurface = TTF_RenderText_Blended(textFont, text, textColour);

	//ttfSurface = TTF_RenderText_Blended(Shooter::textFont, text, Shooter::textColour);
	ttfTexture = SDL_CreateTextureFromSurface(shoot->gRenderer, ttfSurface);
	SDL_FreeSurface(ttfSurface);

	int texW = 0, texH = 0;
	SDL_QueryTexture(ttfTexture, NULL, NULL, &texW, &texH);
	GetClipFrame()->x = 0;
	GetClipFrame()->y = 0;
	GetClipFrame()->w = texW;
	GetClipFrame()->h = texH;
}


SDL_Texture * TextSprite::GetTexture()
{
	return ttfTexture;
}
