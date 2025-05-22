#pragma once
#include "GridCell.h"

class Node
{
public:
    Node() = default;
    Node(GridCell* t_cell) : m_owner(t_cell) { }

    bool m_wasVisited = false;
    GridCell* m_owner = nullptr;

    Node* m_previousNode = nullptr;
};

