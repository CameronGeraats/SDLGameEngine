#pragma once
#include "Sprite.h"
class TextSprite :
	public Sprite
{
public: // take in a string? and create a text sprite from that
	TextSprite();
	TextSprite(const char* );
	~TextSprite();
};

