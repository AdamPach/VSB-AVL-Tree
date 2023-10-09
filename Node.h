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
        BalanceResult(int left, int right, int leftLeft, int leftRight, int rightLeft, int rightRight);
        BalanceResult();
        int leftHeight;
        int rightHeight;
        int leftLeftHeight;
        int leftRightHeight;
        int rightLeftHeight;
        int rightRightHeight;
        int balance();
        int height();
    };
    Node(int value);
    void addNode(Node * newNode);
    int getValue();
    void printNode(int recursionLevel);
    Node * findNode(int value);
    BalanceResult checkBalance();
    bool deleteNode(int value);

    //Getters and setters
    Node * getLeftNode();
    Node * getRightNode();
    void setLeftNode(Node * newNode);
    void setRightNode(Node * newNode);

    // Rotations
    Node * rotateLeft(Node * x, Node * y);
    Node * rotateRight(Node *x, Node *y);
    Node * rotateLeftRight(Node * x, Node * y, Node * z);
    Node * rotateRightLeft(Node * x, Node * y, Node * z);
private:
    int value;

    Node * rightNode;
    Node * leftNode;

    void processLeftBalanceResult(BalanceResult& result);
    void processRightBalanceResult(BalanceResult& result);

    Node * processDelete();
    Node * getDeepestRightNode();
};


#endif //AVL_TREE_NODE_H
