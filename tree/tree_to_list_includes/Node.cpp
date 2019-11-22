#include <iostream>
#include "Node.hpp"

Node *Node::createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->small = NULL;
    node->large = NULL;

    return node;
}