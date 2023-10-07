//
// Created by adamp on 10/5/2023.
//

#include <iostream>
#include "Tree.h"

Tree::Tree() {
    this->rootNode = nullptr;
}

void Tree::insertNode(int value) {
    Node * newNode = new Node(value);
    if(this->rootNode == nullptr)
        this->rootNode = newNode;
    else
        this->rootNode->addNode(newNode);
}

void Tree::printTree() {
    if(rootNode == nullptr)
    {
        std::cout << "Empty tree";
        return;
    }

    rootNode->printNode(0);
}

Node *Tree::findNode(int value) {
    if(rootNode == nullptr)
    {
        std::cout << "Tree is empty" << std::endl;
        return nullptr;
    }

    Node * foundNode = rootNode->findNode(value);
    if(foundNode != nullptr)
        std::cout << "Node is found" << std::endl;
    else
        std::cout << "Node is not found" << std::endl;

    return foundNode;
}