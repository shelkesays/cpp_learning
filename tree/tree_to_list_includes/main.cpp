#include <iostream>
#include "Node.hpp"
#include "TreeList.hpp"


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