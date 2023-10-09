//
// Created by adamp on 10/5/2023.
//

#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H


#include "Node.h"

class Tree {
public:
    Tree();

    void insertNode(int value);
    void printTree();
    void deleteNode(int value);
    Node * findNode(int value);
    Node * rootNode;
    void balanceTree();
private:
};


#endif //AVL_TREE_TREE_H
