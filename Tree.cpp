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
    {
        this->rootNode->addNode(newNode);
        this->balanceTree();
    }
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

void Tree::balanceTree() {
    if(rootNode == nullptr)
        return;

    auto result = rootNode->checkBalance();

    if(result.balance() >= 2)
    {
        if(result.leftRightHeight > result.leftLeftHeight)
        {
            rootNode = rootNode->rotateLeftRight(rootNode, rootNode->getLeftNode(), rootNode->getLeftNode()->getRightNode());
        }
        else
        {
            rootNode = rootNode->rotateRight(rootNode, rootNode->getLeftNode());
        }
    }else if(result.balance() <= -2)
    {
        if(result.rightLeftHeight > result.rightRightHeight)
        {
            rootNode = rootNode->rotateRightLeft(rootNode, rootNode->getRightNode(), rootNode->getRightNode()->getLeftNode());
        }
        else
        {
            rootNode = rootNode->rotateLeft(rootNode, rootNode->getRightNode());
        }
    }
}
