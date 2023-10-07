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

    return Node::BalanceResult(leftResult.height(), rightResult.height(), leftResult.leftHeight, leftResult.rightHeight, rightResult.leftHeight, rightResult.rightHeight);
}

void Node::processLeftBalanceResult(Node::BalanceResult& result) {
    if(result.balance() >= 2)
    {
        std::cout << "The node with value " << leftNode->getValue() << " is left overweight" << std::endl;
        if(result.leftRightHeight > result.leftLeftHeight)
        {
            this->setLeftNode(this->rotateLeftRight(this->getLeftNode(), this->getLeftNode()->getLeftNode(), this->getLeftNode()->getLeftNode()->getRightNode()));
        }
        else
        {
            this->setLeftNode(this->rotateRight(this->getLeftNode(), this->getLeftNode()->getLeftNode()));
        }
    } else if(result.balance() <= -2)
    {
        std::cout << "The node with value " << leftNode->getValue() << " is right overweight" << std::endl;
        if(result.rightLeftHeight > result.rightRightHeight)
        {
            this->setLeftNode(this->rotateRightLeft(this->getLeftNode(), this->getLeftNode()->getRightNode(), this->getLeftNode()->getRightNode()->getLeftNode()));
        }
        else
        {
            this->setLeftNode(this->rotateLeft(this->getLeftNode(), this->getLeftNode()->getRightNode()));
        }
    }
}

void Node::processRightBalanceResult(Node::BalanceResult& result) {
    if(result.balance() >= 2)
    {
        std::cout << "The node with value " << rightNode->getValue() << " is left overweight" << std::endl;
        if(result.leftRightHeight > result.leftLeftHeight)
        {
            this->setRightNode(this->rotateLeftRight(this->getRightNode(), this->getRightNode()->getLeftNode(), this->getRightNode()->getLeftNode()->getRightNode()));
            result.leftHeight --;
            result.rightHeight ++;
        }
        else
        {
            this->setRightNode(this->rotateRight(this->getRightNode(), this->getRightNode()->getLeftNode()));
        }
    } else if(result.balance() <= -2)
    {
        std::cout << "The node with value " << rightNode->getValue() << " is right overweight" << std::endl;
        if(result.rightLeftHeight > result.rightRightHeight)
        {
            this->setRightNode(this->rotateRightLeft(this->getRightNode(), this->getRightNode()->getRightNode(), this->getRightNode()->getRightNode()->getLeftNode()));
        }
        else
        {
            this->setRightNode(this->rotateLeft(this->getRightNode(), this->getRightNode()->getRightNode()));
        }
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

Node *Node::rotateLeftRight(Node *x, Node *y, Node *z) {
    x->setLeftNode(this->rotateLeft(y, z));
    return this->rotateRight(x,z);
}

Node *Node::rotateRightLeft(Node *x, Node *y, Node *z) {
    x->setRightNode(this->rotateRight(y, z));
    return rotateLeft(x,z);
}

int Node::BalanceResult::balance() {
    return leftHeight - rightHeight;
}

int Node::BalanceResult::height() {
    return std::max(leftHeight, rightHeight) + 1;
}

Node::BalanceResult::BalanceResult(int left, int right, int leftLeft, int leftRight, int rightLeft, int rightRight) {
    leftHeight = left;
    rightHeight = right;
    leftLeftHeight = leftLeft;
    leftRightHeight = leftRight;
    rightLeftHeight = rightLeft;
    rightRightHeight = rightRight;
}

Node::BalanceResult::BalanceResult() {
    leftHeight = -1;
    rightHeight = -1;
}
