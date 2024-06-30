#ifndef AVL_HPP
#define AVL_HPP
#include <climits>
#include <iostream>

struct Node 
{
    int val;
    Node* left;
    Node* right;

    Node(int val = INT_MIN);
};

class AVL 
{
    private:
    Node* root;

    private:
    //traversal helpers
    void inOrderHelper(Node* root);
    void preOrderHelper(Node* root);
    void postOrderHelper(Node* root);

    //insert, delete, search helpers
    Node* insertNodeHelper(Node* root, int val);
    Node* deleteNodeHelper(Node* root, int val); 
    Node* searchNodeHelper(Node* root, int val);  

    //getHeight, getSize
    int getHeightHelper(Node* root);
    int getSizeHelper(Node* root);

    //balance factor
    int getBalanceFactor(Node* root);

    //rotations
    Node* rightRotate(Node* root);
    Node* leftRotate(Node* root);
    Node* balance(Node* node, int val);

    public:
    AVL();
    //traversals
    void inOrder();
    void preOrder();
    void postOrder();

    //insert, delete, search
    void insertNode(int val);
    void deleteNode(int val);
    Node* searchNode(int val);
 
    //getMin, getMax
    Node* getMin(Node* node);
    Node* getMin();
    Node* getMax(Node* node);
    Node* getMax();

    //getHeight, getSize
    int getHeight();
    int getHeight(Node* node);
    int getSize(); 

    //predecessor, successor
    Node* getPredecessor(int val);
    Node* getSuccessor(int val);

    
};

#include "AVL.cpp"

#endif //AVL_HPP