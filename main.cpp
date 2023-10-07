#include <iostream>
#include "Tree.h"

int main() {
    Tree * tree = new Tree();

    tree->insertNode(3);
    tree->insertNode(4);
    tree->insertNode(5);
    tree->insertNode(2);
    tree->insertNode(6);
    tree->insertNode(7);
    tree->insertNode(1);
    tree->insertNode(8);
    tree->insertNode(9);


    tree->printTree();

    tree->findNode(6);
    tree->findNode(20);


    delete tree;
    return 0;
}
