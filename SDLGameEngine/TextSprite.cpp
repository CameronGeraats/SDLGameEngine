#include "TextSprite.h"
#include "SDL_ttf.h"
#include "Shooter.h"


TextSprite::TextSprite()
{
}

TextSprite::TextSprite(const char * text)
{
	char buffer[100];
	std::string instructions = text;
	SDL_Surface* ttfSurface;
	SDL_Texture* ttfTexture;
	sprintf_s(buffer, instructions.c_str());
		
	ttfSurface = TTF_RenderText_Blended(Shooter::textFont, buffer, Shooter::textColour);
	ttfTexture = SDL_CreateTextureFromSurface(Shooter::gRenderer, ttfSurface);

		int texW = 0;
		int texH = 0;
		SDL_QueryTexture(ttfTexture, NULL, NULL, &texW, &texH);
		Rect tempRect({ 0, 0, texW, texH });

		SDL_Rect* temp = new SDL_Rect({ 0, 0, texW, texH });
		SDL_RenderCopy(gamePtr->m_pRenderer, gamePtr->ttfTexture, temp, &(gamePtr->getTextRect()));
		SDL_RenderPresent(gamePtr->m_pRenderer);
		SDL_FreeSurface(ttfSurface);
		delete temp;
}


TextSprite::~TextSprite()
{
}
