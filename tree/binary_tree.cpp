#include <iostream>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = new (struct node);
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
};

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        return newNode(data);
    }
    else
    {
        if (data <= node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }

        return node;
    }
}

static int lookup(struct node *node, int key)
{
    if (node == NULL)
    {
        return false;
    }
    else
    {
        if (key == node->data)
        {
            return true;
        }
        else
        {
            if (key < node->data)
            {
                return lookup(node->left, key);
            }
            else
            {
                return lookup(node->right, key);
            }
        }
    }
}

struct node *build123a()
{
    struct node *root = newNode(2);
    struct node *lChild = newNode(1);
    struct node *rChild = newNode(3);

    root->left = lChild;
    root->right = rChild;

    return root;
}

struct node *build123b()
{
    struct node *root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    return root;
}

struct node *build123c()
{
    struct node *root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);

    return root;
}

int size(struct node *node)
{
    int count = 0;

    if (node != NULL)
    {
        count = count + size(node->left);
        count++;
        count = count + size(node->right);
    }

    return count;
}

int maxDepth(struct node *node)
{
    int count = 0;
    int lcount, rcount = 0;

    if (node != NULL)
    {
        lcount = maxDepth(node->left);
        rcount = maxDepth(node->right);
        if (lcount > rcount)
        {
            count = ++lcount;
        }
        else
        {
            count = ++rcount;
        }
    }

    return count;
}

int minValueRecursive(struct node *node)
{
    int value = 0;
    if (node != NULL)
    {
        value = minValueRecursive(node->left);
    }
    else
    {
        value = node->data;
    }

    return value;
}

int minValueLoop(struct node *node)
{
    struct node *current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current->data;
}

int maxValueRecursive(struct node *node)
{
    int value = 0;
    if (node != NULL)
    {
        value = maxValueRecursive(node->right);
    }
    else
    {
        value = node->data;
    }

    return value;
}

int maxValueLoop(struct node *node)
{
    struct node *current = node;

    while (current->right != NULL)
    {
        current = current->right;
    }

    return current->data;
}

void printTree(struct node *node)
{
    if (node != NULL)
    {
        printTree(node->left);
        std::cout << node->data << std::endl;
        printTree(node->right);
    }
}

void printPostorder(struct node *node)
{
    if (node != NULL)
    {
        printPostorder(node->left);
        printPostorder(node->right);
        std::cout << node->data << std::endl;
    }
}

int hasPathSum(struct node *node, int sum)
{
    bool status = false;
    if (node != NULL)
    {
        int subSum = sum - node->data;
        status = (hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum));
    }
    else
    {
        status = (sum == 0);
    }

    return status;
}

void printArray(int path[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        std::cout << path[i];
    }
    std::cout << std::endl;
}

void printPathsRecur(struct node *node, int path[], int pathLen)
{
    if (node != NULL)
    {
        path[pathLen] = node->data;
        pathLen++;

        if (node->left == NULL && node->right == NULL)
        {
            printArray(path, pathLen);
        }
        else
        {
            printPathsRecur(node->left, path, pathLen);
            printPathsRecur(node->right, path, pathLen);
        }
    }
}

void printPaths(struct node *node)
{
    int path[1000];
    printPathsRecur(node, path, 0);
}

void mirror(struct node *node)
{
    if (node != NULL)
    {
        struct node *temp;

        mirror(node->left);
        mirror(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void doubleTree(struct node *node)
{
    if (node != NULL)
    {
        struct node *oldleft;
        doubleTree(node->left);
        doubleTree(node->right);

        oldleft = node->left;
        node->left = newNode(node->data);
        node->left->left = oldleft;
    }
}

int sameTree(struct node *a, struct node *b)
{
    bool status = false;
    if (a == NULL && b == NULL)
    {
        status = true;
    }
    else if (a != NULL && b != NULL)
    {
        status = (a->data == b->data && sameTree(a->left, b->left) && sameTree(a->right, b->right));
    }
    else
    {
        status = false;
    }

    return status;
}

int countTree(int numKeys)
{
    int sum = 0;

    if(numKeys <= 1) {
        sum = 1;
    } else {
        int left, right, root;

        for (root = 1; root <= numKeys; root++) {
            left = countTree(root - 1);
            right = countTree(numKeys - root);

            sum += left * right;
        }
    }

    return sum;
}

int isBST(struct node *node)
{
    bool status = true;
    if (node == NULL) {
        status = true;
    }

    if (node->left != NULL && maxValueLoop(node->left) > node->data) {
        status = false;
    }

    if (node->right != NULL && maxValueLoop(node->right) <= node->data) {
        status = false;
    }

    if(!isBST(node->left) || !isBST(node->right)) {
        status = false;
    }

    return status;
}

int isBSTUtil(struct node *node, int min, int max) {
    if(node == NULL) {
        return true;
    }

    if(node->data < min || node->data > max) {
        return false;
    }

    return (isBSTUtil(node->left, min, node->data) && isBSTUtil(node->right, node->data+1, max));
}

int isBST2(struct node *node)
{
    return isBSTUtil(node, INT8_MIN, INT8_MAX);
}

int main()
{
    struct node *tree = newNode(2);

    tree = insert(tree, 10);
    tree = insert(tree, 100);
    tree = insert(tree, 101);
    tree = insert(tree, 50);
    tree = insert(tree, 1);


    int number = lookup(tree, 10);
    int number2 = lookup(tree, 120);

    std::cout << "Left node: " << number << std::endl;
    std::cout << "Right node: " << number2 << std::endl;

    return 0;
}
