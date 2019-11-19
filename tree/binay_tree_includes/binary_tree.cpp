#include <iostream>
#include "node.hpp"
#include "binary_tree.hpp"


void BinaryTree::destroy_tree(Node *leaf)
{
    if (leaf != NULL)
    {
        BinaryTree::destroy_tree(leaf->left);
        BinaryTree::destroy_tree(leaf->right);
        delete leaf;
    }
}

void BinaryTree::insert(int key, Node *leaf)
{
    if (key <= leaf->data)
    {
        if (leaf->left != NULL)
        {
            BinaryTree::insert(key, leaf->left);
        }
        else
        {
            leaf->left = Node::createNode(key);
        }
    }
    else if (key > leaf->data)
    {
        if (leaf->right != NULL)
        {
            BinaryTree::insert(key, leaf->right);
        }
        else
        {
            leaf->right = Node::createNode(key);
        }
    }
}

Node *BinaryTree::search(int key, Node *leaf)
{
    if (leaf != NULL)
    {
        if (key == leaf->data)
        {
            return leaf;
        }

        if (key < leaf->data)
        {
            return BinaryTree::search(key, leaf->left);
        }
        else
        {
            return BinaryTree::search(key, leaf->right);
        }
    }
    else
    {
        // 1. root == empty tree
        // in that case, the target is not found so return NULL
        return NULL;
    }
}

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    BinaryTree::destroy_tree();
}

void BinaryTree::insert(int key)
{
    if (root != NULL)
    {
        BinaryTree::insert(key, root);
    }
    else
    {
        root = Node::createNode(key);
    }
}

/*
Given a binary tree, return true if a node
with the target data is found in the tree. Recurs
down the tree, chooses the left or right
branch by comparing the target to each node.
*/
Node *BinaryTree::lookup(int key)
{
    return BinaryTree::search(key, root);
}

void BinaryTree::destroy_tree()
{
    BinaryTree::destroy_tree(root);
}
