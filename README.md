# AVL Tree Implementation in C++

This project implements an AVL Tree data structure in C++. The AVL Tree is a self-balancing binary search tree where the difference between heights of left and right subtrees cannot be more than one for all nodes.

## Features

- **Insertion**: Insert a node while maintaining the balance of the tree.
- **Deletion**: Delete a node while maintaining the balance of the tree.
- **Search**: Search for a node in the tree.
- **Traversals**: In-order, Pre-order, and Post-order traversals.
- **Get Minimum and Maximum**: Retrieve the minimum and maximum values in the tree.
- **Get Height and Size**: Retrieve the height and size of the tree.
- **Get Predecessor and Successor**: Retrieve the predecessor and successor of a given node.

## Files

- `AVL.hpp`: Header file containing the class definitions for the AVL Tree and its nodes.
- `AVL.cpp`: Source file implementing the methods defined in `AVL.hpp`.
- `main.cpp`: Main file to test the AVL Tree implementation.

## Class Definitions

### Node

Represents a single node in the AVL Tree.

#### Members

- `int val`: Value stored in the node.
- `Node* left`: Pointer to the left child.
- `Node* right`: Pointer to the right child.

#### Constructor

- `Node(int val)`: Initializes a new node with the given value.

### AVL

Represents the AVL Tree.

#### Members

- `Node* root`: Root node of the AVL Tree.

#### Methods

- **Public Methods**:
  - `AVL()`: Constructor to initialize an empty tree.
  - `void inOrder()`: Perform in-order traversal.
  - `void preOrder()`: Perform pre-order traversal.
  - `void postOrder()`: Perform post-order traversal.
  - `void insertNode(int val)`: Insert a node with the given value.
  - `void deleteNode(int val)`: Delete the node with the given value.
  - `Node* searchNode(int val)`: Search for a node with the given value.
  - `Node* getMin()`: Get the node with the minimum value.
  - `Node* getMax()`: Get the node with the maximum value.
  - `int getHeight()`: Get the height of the tree.
  - `int getSize()`: Get the size of the tree.
  - `Node* getPredecessor(int val)`: Get the predecessor of the node with the given value.
  - `Node* getSuccessor(int val)`: Get the successor of the node with the given value.

- **Private Methods**:
  - `void inOrderHelper(Node* root)`: Helper function for in-order traversal.
  - `void preOrderHelper(Node* root)`: Helper function for pre-order traversal.
  - `void postOrderHelper(Node* root)`: Helper function for post-order traversal.
  - `Node* insertNodeHelper(Node* root, int val)`: Helper function for node insertion.
  - `Node* deleteNodeHelper(Node* root, int val)`: Helper function for node deletion.
  - `Node* searchNodeHelper(Node* root, int val)`: Helper function for node search.
  - `int getHeightHelper(Node* root)`: Helper function to get the height of a subtree.
  - `int getSizeHelper(Node* root)`: Helper function to get the size of a subtree.
  - `int getBalanceFactor(Node* root)`: Get the balance factor of a node.
  - `Node* rightRotate(Node* root)`: Perform a right rotation.
  - `Node* leftRotate(Node* root)`: Perform a left rotation.
  - `Node* balance(Node* node, int val)`: Balance the subtree rooted at the given node.
  - `Node* getMin(Node* node)`: Helper function to get the node with the minimum value in a subtree.
  - `Node* getMax(Node* node)`: Helper function to get the node with the maximum value in a subtree.

## Usage

1. **Compile the program**:
    ```bash
    g++ main.cpp AVL.cpp -o avl_tree
    ```

2. **Run the executable**:
    ```bash
    ./avl_tree
    ```


