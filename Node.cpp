//
// Created by adamp on 10/5/2023.
//

#include <iostream>
#include "Node.h"

void Node::addNode(Node *newNode) {
    if(newNode->getValue() < value)
    {
        if(leftNode == nullptr)
            leftNode = newNode;
        else leftNode->addNode(newNode);
    }
    else
    {
        if(rightNode == nullptr)
            rightNode = newNode;
        else rightNode->addNode(newNode);
    }
}

Node::Node(int value) {
    this->value = value;
    this->rightNode = nullptr;
    this->leftNode = nullptr;
}

int Node::getValue() {
    return this->value;
}

void Node::printNode(int recursionLevel) {
    std::cout << value << std::endl;
    if(leftNode != nullptr)
    {

        for(int i = 0; i < recursionLevel; i++)
            std::cout << " ";
        std::cout << "|_ ";
        leftNode->printNode(recursionLevel + 1);
    }
    if (rightNode != nullptr)
    {
        for(int i = 0; i < recursionLevel; i++)
            std::cout << " ";
        std::cout << "|_ ";
        rightNode->printNode( recursionLevel + 1);
    }
}

Node *Node::findNode(int value) {
    if(value == this->value)
        return this;

    Node * foundNode = nullptr;
    if(rightNode != nullptr)
        foundNode = rightNode->findNode(value);
    if(leftNode != nullptr && foundNode == nullptr)
        foundNode = leftNode->findNode(value);

    return foundNode;
}

Node *Node::getLeftNode() {
    return leftNode;
}

Node *Node::getRightNode() {
    return rightNode;
}

void Node::setLeftNode(Node *newNode) {
    this->leftNode = newNode;
}

void Node::setRightNode(Node *newNode) {
    this->rightNode = newNode;
}

int Node::checkBalance() {
    int leftHeight = -1, rightHeight = -1;

    if(leftNode != nullptr)
        leftHeight = leftNode->checkBalance();

    if(rightNode != nullptr)
        rightHeight = rightNode->checkBalance();

    int balance = leftHeight - rightHeight;

    if(balance >= 2)
    {
        //Left overweight
    } else if (balance <= - 2)
    {
        //Right overweight
    }

    return std::max(leftHeight, rightHeight) + 1;
}
