#pragma once
#include <iostream>
#include "Color.h"
#include "Rect.h"
class Sprite
{
public:
	Sprite();
	Sprite(Rect* _clipFrame);
	Sprite(std::string _imagePath, Rect * _clipFrame =  NULL);
	~Sprite();

	const std::string& GetPath();
	Rect* GetClipFrame();
	void ChangeFrame();

private:
	std::string imagePath;
	Rect* clipFrame;
};

