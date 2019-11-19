#include <iostream>
#include "node.hpp"
#include "binary_tree.hpp"

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
