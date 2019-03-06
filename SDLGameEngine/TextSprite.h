#pragma once
#include "Sprite.h"
class Game;
class TextSprite :
	public Sprite
{
public: // take in a string? and create a text sprite from that
	TextSprite(const char* , Game*);
	SDL_Texture* GetTexture();
private:
	SDL_Surface* ttfSurface;
	SDL_Texture* ttfTexture;
};

