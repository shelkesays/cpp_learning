// Solution for http://cslibrary.stanford.edu/109/TreeListRecursion.pdf

#include <iostream>

class Node
{
public:
    int data;
    Node *small;
    Node *large;

    static Node *createNode(int data)
    {
        Node *node = new Node();
        node->data = data;
        node->small = NULL;
        node->large = NULL;

        return node;
    }
};

class TreeList
{
private:
    Node *root;

    void destroy_tree(Node *leaf)
    {
        if (leaf != NULL)
        {
            destroy_tree(leaf->small);
            destroy_tree(leaf->large);
            delete leaf;
        }
    }

    void *treeInsert(Node *leaf, int data)
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

    Node *treeToList(Node *leaf)
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

public:
    TreeList()
    {
        root = NULL;
    }

    void join(Node *a, Node *b)
    {
        a->large = b;
        b->small = a;
    }

    Node *append(Node *a, Node *b)
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

    Node *treeToList()
    {
        return treeToList(root);
    }

    void *treeInsert(int data)
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

    void printList(Node *head)
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

    void printRoot()
    {
        std::cout << root << std::endl;
        std::cout << root->large << std::endl;
        std::cout << root->small << std::endl;
        std::cout << root->data << std::endl;
    }

    void destroy_tree()
    {
        destroy_tree(root);
    }
};

int main()
{
    TreeList tree = TreeList();

    tree.treeInsert(4);
    tree.treeInsert(1);
    tree.treeInsert(3);
    tree.treeInsert(5);
    tree.treeInsert(2);
    tree.treeInsert(6);

    Node *head = tree.treeToList();

    tree.printList(head);

    return 0;
}
