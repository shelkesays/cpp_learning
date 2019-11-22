#include <iostream>
#include "Node.hpp"
#include "TreeList.hpp"

void TreeList::destroy_tree(Node *leaf)
{
    if (leaf != NULL)
    {
        destroy_tree(leaf->small);
        destroy_tree(leaf->large);
        delete leaf;
    }
}

void *TreeList::treeInsert(Node *leaf, int data)
{
    if (data <= leaf->data)
    {
        if (leaf->small != NULL)
        {
            treeInsert(leaf->small, data);
        }
        else
        {
            leaf->small = Node::createNode(data);
        }
    }
    else if (data > leaf->data)
    {
        if (leaf->large != NULL)
        {
            treeInsert(leaf->large, data);
        }
        else
        {
            leaf->large = Node::createNode(data);
        }
    }
}

Node *TreeList::treeToList(Node *leaf)
{
    Node *aList, *bList;

    if (leaf == NULL)
    {
        return NULL;
    }

    aList = treeToList(leaf->small);
    bList = treeToList(leaf->large);

    leaf->small = leaf;
    leaf->large = leaf;

    aList = append(aList, leaf);
    aList = append(aList, bList);

    return aList;
}

TreeList::TreeList()
{
    root = NULL;
}

void TreeList::join(Node *a, Node *b)
{
    a->large = b;
    b->small = a;
}

Node *TreeList::append(Node *a, Node *b)
{
    Node *aLast, *bLast;

    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    aLast = a->small;
    bLast = b->small;

    join(aLast, b);
    join(bLast, a);

    return a;
}

Node *TreeList::treeToList()
{
    return treeToList(root);
}

void *TreeList::treeInsert(int data)
{
    if (root != NULL)
    {
        treeInsert(root, data);
    }
    else
    {
        root = Node::createNode(data);
    }
}

void TreeList::printList(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        std::cout << current->data << std::endl;
        current = current->large;
        if (current == head)
        {
            break;
        }
    }
}

void TreeList::printRoot()
{
    std::cout << root << std::endl;
    std::cout << root->large << std::endl;
    std::cout << root->small << std::endl;
    std::cout << root->data << std::endl;
}
