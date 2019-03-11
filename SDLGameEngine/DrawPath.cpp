#include "DrawPath.h"
#include "Game.h"
#include "Input.h"
#include "Time.h"


DrawPath::DrawPath()
{
}


DrawPath::~DrawPath()
{
}

void DrawPath::Update()
{
	float x1 = Input::GetKey(SDLK_d) ? 1 : Input::GetKey(SDLK_a) ? -1 : 0;
	float y1 = Input::GetKey(SDLK_s) ? 1 : Input::GetKey(SDLK_w) ? -1 : 0;

	float x2 = Input::GetKey(SDLK_RIGHT) ? 1 : Input::GetKey(SDLK_LEFT) ? -1 : 0;
	float y2 = Input::GetKey(SDLK_DOWN) ? 1 : Input::GetKey(SDLK_UP) ? -1 : 0;

	start += Vector2(x1, y1) * 300 * Time::DeltaTime();
	end += Vector2(x2, y2) * 300 * Time::DeltaTime();

	float width = Camera::width / finder->m_width;
	float height = Camera::height / finder->m_height;

	int startX = floor(start.x / width);
	int startY = floor(start.y / height);

	int endX = floor(end.x / width);
	int endY = floor(end.y / height);

	PathNode* startNode = finder->grid[startX][startY];
	PathNode* endNode = finder->grid[endX][endY];

	SDL_SetRenderDrawColor(Game::gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawPoint(Game::gRenderer, start.x, start.y);
	SDL_RenderDrawPoint(Game::gRenderer, end.x, end.y);
	if (finder->FindPath(startNode, endNode))
	{
		PathNode* node = endNode;
		while (node != startNode || node->parent != nullptr)
		{
			SDL_RenderDrawLine(Game::gRenderer, node->xCoordinate * width + width / 2, 
				node->yCoordinate * height + height / 2, 
				node->parent->xCoordinate * width + width / 2,
				node->parent->yCoordinate * height + height / 2);
			node = node->parent;
		}
	}
}
