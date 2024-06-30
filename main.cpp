#include "AVL.hpp"
#include <iostream>

int main() 
{
    AVL tree;

    // Inserting nodes
    tree.insertNode(10);
    tree.insertNode(20);
    tree.insertNode(30);
    tree.insertNode(40);
    tree.insertNode(50);
    tree.insertNode(25);

    // Traversals
    std::cout << "In-order traversal: ";
    tree.inOrder(); // Should print the nodes in ascending order

    std::cout << "Pre-order traversal: ";
    tree.preOrder(); // Should print the nodes in pre-order

    std::cout << "Post-order traversal: ";
    tree.postOrder(); // Should print the nodes in post-order

    // Get min and max
    std::cout << "Minimum value in the tree: " << tree.getMin()->val << std::endl;
    std::cout << "Maximum value in the tree: " << tree.getMax()->val << std::endl;

    // Search for a node
    int searchVal = 25;
    Node* searchResult = tree.searchNode(searchVal);
    if (searchResult) {
        std::cout << "Node " << searchVal << " found in the tree." << std::endl;
    } else {
        std::cout << "Node " << searchVal << " not found in the tree." << std::endl;
    }

    // Get height and size
    std::cout << "Height of the tree: " << tree.getHeight() << std::endl;
    std::cout << "Size of the tree: " << tree.getSize() << std::endl;

    // Get predecessor and successor
    int predSuccVal = 25;
    Node* predecessor = tree.getPredecessor(predSuccVal);
    if (predecessor) {
        std::cout << "Predecessor of " << predSuccVal << " is " << predecessor->val << std::endl;
    } else {
        std::cout << "No predecessor found for " << predSuccVal << std::endl;
    }

    Node* successor = tree.getSuccessor(predSuccVal);
    if (successor) {
        std::cout << "Successor of " << predSuccVal << " is " << successor->val << std::endl;
    } else {
        std::cout << "No successor found for " << predSuccVal << std::endl;
    }

    // Deleting nodes
    tree.deleteNode(10);
    tree.deleteNode(20);

    std::cout << "In-order traversal after deletions: ";
    tree.inOrder(); // Should reflect the deletions

    return 0;
}
