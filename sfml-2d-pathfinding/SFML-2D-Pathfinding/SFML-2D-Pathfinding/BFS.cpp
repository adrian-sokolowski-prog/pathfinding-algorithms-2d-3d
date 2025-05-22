#include "BFS.h"
#include <queue>
#include "Globals.h"
#include "Node.h"

BFS::BFS(GridCell& t_startNode, GridCell& t_endNode, std::vector<GridCell>& t_grid)
	: m_startNode(t_startNode), m_endNode(t_endNode), m_grid(t_grid)
{
	m_path = findPath();
}

std::vector<GridCell*> BFS::findPath()
{
	std::queue<Node*> queue;
	std::vector<Node> nodes(m_grid.size());
	
	for(int i = 0; i < m_grid.size(); ++i)
	{
		nodes[i] = Node(&m_grid[i]);
	}
	Node* startNode = &nodes[getIndex(m_startNode.m_index)];
	Node* endNode = &nodes[getIndex(m_endNode.m_index)];

	
	queue.push(startNode);
	startNode->m_wasVisited = true;
	
	while (!queue.empty())
	{
		Node* currentNode = queue.front();
		queue.pop();

		if(currentNode->m_owner == endNode->m_owner)
		{
			std::vector<GridCell*> path;

			while (currentNode != nullptr)
			{
				path.push_back(currentNode->m_owner);
				currentNode = currentNode->m_previousNode;
			}
			std::reverse(path.begin(), path.end());
			return path;
		}

		for (sf::Vector2i direction : m_directions)
		{
			sf::Vector2i newIndex = currentNode->m_owner->m_index + direction;
			
			if(indexIsValid(newIndex))
			{
				Node* neighborNode = &nodes[getIndex(newIndex)];

				if (!neighborNode->m_wasVisited && neighborNode->m_owner->IsWalkable())
				{
					neighborNode->m_owner->SetColor(sf::Color::Yellow);
					neighborNode->m_wasVisited = true;
					neighborNode->m_previousNode = currentNode;
					queue.push(neighborNode);
				}
			}
		}
	}

	return std::vector<GridCell*>();

}

bool BFS::indexIsValid(sf::Vector2i t_index) const
{
	return t_index.x >= 0 &&
		t_index.y >= 0 &&
		t_index.x < Globals::CELL_AMOUNT.x &&
		t_index.y < Globals::CELL_AMOUNT.y;
}

int BFS::getIndex(sf::Vector2i t_index) const
{
	// Multiply rows by column amount and add column index to get 1d Index
	return (t_index.y * Globals::CELL_AMOUNT.x) + t_index.x;
}