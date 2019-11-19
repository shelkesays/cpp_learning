#include <iostream>
#include "node.hpp"


Node *Node::createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}