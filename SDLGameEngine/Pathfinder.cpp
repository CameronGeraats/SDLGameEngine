#include "Pathfinder.h"
#include <time.h>
#include <algorithm>


Pathfinder::Pathfinder(Game* _game, int _width, int _height)
{
	m_width = _width;
	m_height = _height;
	game = _game;

	for (int i = 0; i < m_width; i++)
	{
		grid.push_back(std::vector<PathNode*>());
		for (int j = 0; j < m_height; j++)
		{
			PathNode* node = new PathNode();
			node->xCoordinate = i;
			node->yCoordinate = j;
			node->finder = this;
			if (rand() % 100 < 30)
			{
				node->blocked = true;
				float xLength = (Camera::width / m_width);
				float yLength = (Camera::height / m_height);
				game->Instantiate(game->Prefab("Obstacle"), xLength * i + xLength / 2, yLength * j + yLength / 2);
			}
			grid[i].push_back(node);
		}
	}
}


Pathfinder::~Pathfinder()
{
}

bool Pathfinder::FindPath(PathNode* start, PathNode* finish)
{
	std::list<PathNode*> open;
	std::list<PathNode*> closed;

	start->parent = nullptr;
	start->gCost = 0;
	start->hCost = start->CalculateCost(finish->xCoordinate, finish->yCoordinate);

	open.push_back(start);

	while (open.size() > 0)
	{
		// Find lowest fcost in open
		PathNode* current = *(open.begin());
		for (PathNode* node : open)
		{
			if (node->FCost() < current->FCost())
			{
				current = node;
			}
		}


		open.remove(current);

		closed.push_back(current);

		if (current == finish)
		{
			return true;
		}

		std::list<PathNode*> neighbours = current->Neighbours();

		for (PathNode* neighbour : neighbours)
		{
			// If in closed, do nothing
			if (std::find(closed.begin(), closed.end(), neighbour) != closed.end())
			{
				continue;
			}

			int newGCost = neighbour->CalculateCost(current->xCoordinate, current->yCoordinate);
			int newHCost = neighbour->CalculateCost(finish->xCoordinate, finish->yCoordinate);
			int newFCost = newGCost + newHCost;

			bool inOpen = std::find(open.begin(), open.end(), neighbour) != open.end();
			if (!inOpen || newFCost < neighbour->FCost())
			{
				neighbour->gCost = newGCost;
				neighbour->hCost = newHCost;
				neighbour->parent = current;
				if (!inOpen)
				{
					open.push_back(neighbour);
				}
			}
		}
	}
	return false;
}

