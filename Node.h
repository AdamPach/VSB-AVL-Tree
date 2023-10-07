//
// Created by adamp on 10/5/2023.
//

#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H


class Node{
public:
    Node(int value);
    void addNode(Node * newNode);
    int getValue();
    void printNode(int recursionLevel);
    Node * findNode(int value);
    int checkBalance();

    //Getters and setters
    Node * getLeftNode();
    Node * getRightNode();
    void setLeftNode(Node * newNode);
    void setRightNode(Node * newNode);
private:
    int value;

    Node * rightNode;
    Node * leftNode;
};


#endif //AVL_TREE_NODE_H
