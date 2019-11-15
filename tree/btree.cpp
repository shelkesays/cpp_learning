#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    static Node *createNode(int data)
    {
        Node *node = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;

        return node;
    }
};

class BinaryTree
{
private:
    Node *root;

    void destroy_tree(Node *leaf)
    {
        if (leaf != NULL)
        {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }

    void insert(int key, Node *leaf)
    {
        if (key <= leaf->data)
        {
            if (leaf->left != NULL)
            {
                insert(key, leaf->left);
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
                insert(key, leaf->right);
            }
            else
            {
                leaf->right = Node::createNode(key);
            }
        }
    }

    Node *search(int key, Node *leaf)
    {
        if (leaf != NULL)
        {
            if (key == leaf->data)
            {
                return leaf;
            }

            if (key < leaf->data)
            {
                return search(key, leaf->left);
            }
            else
            {
                return search(key, leaf->right);
            }
        }
        else
        {
            // 1. root == empty tree
            // in that case, the target is not found so return NULL
            return NULL;
        }
    }

public:
    BinaryTree()
    {
        root = NULL;
    }

    ~BinaryTree()
    {
        destroy_tree();
    }

    void insert(int key)
    {
        if (root != NULL)
        {
            insert(key, root);
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
    Node *lookup(int key)
    {
        return search(key, root);
    }

    void destroy_tree()
    {
        destroy_tree(root);
    }
};

int main()
{
    BinaryTree tree = BinaryTree();

    tree.insert(100);
    tree.insert(101);
    tree.insert(50);
    tree.insert(50);
    tree.insert(10);
    tree.insert(1);


    Node *found = tree.lookup(10);
    Node *notfound = tree.lookup(120);

    std::cout << "Address of left node: " << found->left << std::endl;
    std::cout << "Address of right node: " << found->right << std::endl;

    std::cout << (notfound == NULL) << std::endl;

    tree.destroy_tree();

    return 0;
}