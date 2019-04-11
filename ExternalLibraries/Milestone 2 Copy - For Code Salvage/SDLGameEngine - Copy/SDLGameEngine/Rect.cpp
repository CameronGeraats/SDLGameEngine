#include "Rect.h"

Rect::Rect()
{

}

Rect::Rect(Rect &b)
{
	x = b.x;
	y = b.y;
	w = b.w;
	h = b.h;
}

Rect::Rect(int _x, int _y, int _w, int _h)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}

Rect::~Rect()
{

}