//
// Created by adamp on 10/5/2023.
//

#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H


class Node{
public:
    class BalanceResult
    {
    public:
        BalanceResult(int left, int right);
        BalanceResult();
        int leftHeight;
        int rightHeight;
        int balance();
        int height();
    };
    Node(int value);
    void addNode(Node * newNode);
    int getValue();
    void printNode(int recursionLevel);
    Node * findNode(int value);
    BalanceResult checkBalance();

    //Getters and setters
    Node * getLeftNode();
    Node * getRightNode();
    void setLeftNode(Node * newNode);
    void setRightNode(Node * newNode);
private:
    int value;

    Node * rightNode;
    Node * leftNode;

    void processLeftBalanceResult(BalanceResult& result);
    void processRightBalanceResult(BalanceResult& result);
    // Rotations
    Node * rotateLeft(Node * x, Node * y);
    Node * rotateRight(Node *x, Node *y);
};


#endif //AVL_TREE_NODE_H
