#include "Sprite.h"



Sprite::Sprite()
{
}

Sprite::Sprite(Rect* _clipFrame)
{
	clipFrame = _clipFrame;
}

Sprite::Sprite(std::string _imagePath, Rect * _clipFrame)
{
	imagePath = _imagePath;
	clipFrame = _clipFrame;
}

Sprite::~Sprite()
{
}

const std::string& Sprite::GetPath()
{
	return imagePath;
}
Rect* Sprite::GetClipFrame()
{
	return clipFrame;
}

void Sprite::ChangeFrame()
{
	clipFrame->x = 0;
}
