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

Node::BalanceResult Node::checkBalance() {
    Node::BalanceResult leftResult, rightResult;
    if(leftNode != nullptr)
        leftResult = leftNode->checkBalance();

    if(rightNode != nullptr)
        rightResult = rightNode->checkBalance();

    processLeftBalanceResult(leftResult);
    processRightBalanceResult(rightResult);

    return Node::BalanceResult(leftResult.height(), rightResult.height());
}

void Node::processLeftBalanceResult(Node::BalanceResult& result) {
    if(result.balance() >= 2)
    {
        std::cout << "The node with value " << leftNode->getValue() << " is left overweight" << std::endl;
        this->setLeftNode(this->rotateRight(this->getLeftNode(), this->getLeftNode()->getLeftNode()));
    } else if(result.balance() <= -2)
    {
        std::cout << "The node with value " << leftNode->getValue() << " is right overweight" << std::endl;
        this->setLeftNode(this->rotateLeft(this->getLeftNode(), this->getLeftNode()->getRightNode()));
    }
}

void Node::processRightBalanceResult(Node::BalanceResult& result) {
    if(result.balance() >= 2)
    {
        std::cout << "The node with value " << rightNode->getValue() << " is left overweight" << std::endl;
        this->setRightNode(this->rotateRight(this->getRightNode(), this->getRightNode()->getLeftNode()));
    } else if(result.balance() <= -2)
    {
        std::cout << "The node with value " << rightNode->getValue() << " is right overweight" << std::endl;
        this->setRightNode(this->rotateLeft(this->getRightNode(), this->getRightNode()->getRightNode()));
    }
}

Node * Node::rotateLeft(Node *x, Node *y) {
    x->setRightNode(y->getLeftNode());
    y->setLeftNode(x);
    return y;
}

Node * Node::rotateRight(Node *x, Node *y) {
    x->setLeftNode(y->getRightNode());
    y->setRightNode(x);
    return y;
}

int Node::BalanceResult::balance() {
    return leftHeight - rightHeight;
}

int Node::BalanceResult::height() {
    return std::max(leftHeight, rightHeight) + 1;
}

Node::BalanceResult::BalanceResult(int left, int right) {
    leftHeight = left;
    rightHeight = right;
}

Node::BalanceResult::BalanceResult() {
    leftHeight = -1;
    rightHeight = -1;
}
