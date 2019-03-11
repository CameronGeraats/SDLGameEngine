#include "DrawPath.h"
#include "Game.h"


DrawPath::DrawPath()
{
}


DrawPath::~DrawPath()
{
}

void DrawPath::Update()
{
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
