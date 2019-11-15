#include <iostream>


struct  node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = new(struct node);
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
};

struct node *insert(struct node *node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else {
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }

        return node;
    }
}

static int lookup(struct node *node, int key) {
    if (node == NULL) {
        return false;
    } else
    {
        if (key == node->data) {
            return true;
        } else {
            if(key < node->data) {
                return lookup(node->left, key);
            } else
            {
                return lookup(node->right, key);
            }
        }
    }
}

struct node *build123a() {
    struct node *root = newNode(2);
    struct node *lChild = newNode(1);
    struct node *rChild = newNode(3);

    root->left = lChild;
    root->right = rChild;

    return root;
}

struct node *build123b() {
    struct node *root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    return root;
}

struct node *build123c() {
    struct node *root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    
    return root;
}

int size(struct node *node) {
    int count = 0;

    if (node != NULL) {
        count = count + size(node->left);
        count++;
        count = count + size(node->right);
    }
    
    return count;
}
