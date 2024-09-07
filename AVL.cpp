#include "AVL.hpp"

Node::Node(int val) 
        : val(val), left(nullptr), right(nullptr) 
        {}


AVL::AVL()
        : root(nullptr) 
        {}


//PRIVATE HELPERS


//traversal helpers
void AVL::inOrderHelper(Node* root)
{
    if (!root) {
        return;
    }
    inOrderHelper(root -> left);
    std::cout << root -> val << " ";
    inOrderHelper(root -> right);
}

void AVL::preOrderHelper(Node* root)
{
    if (!root) {
        return;
    }
    std::cout << root -> val << " ";
    preOrderHelper(root -> left);
    preOrderHelper(root -> right);
}

void AVL::postOrderHelper(Node* root)
{
    if (!root) {
        return;
    }
    postOrderHelper(root -> left);
    postOrderHelper(root -> right);
    std::cout << root -> val << " ";
}

//insert, delete, search helpers
Node* AVL::insertNodeHelper(Node* root, int val) 
{
    if (!root) {
        return new Node(val);
    } 

    if (val > root -> val) {
        root -> right = insertNodeHelper(root->right, val);
    } else if (val <= root -> val) {
        root -> left = insertNodeHelper(root -> left, val);
    } 

    return balance(root, val);
} 

Node* AVL::deleteNodeHelper(Node* root, int val)
{
    if (!root) {
        return root;
    }

    if (!(root -> left)) {
        Node* tmp = root -> right;
        delete root;
        return tmp;
    } else if (!(root -> right)) {
        Node* tmp = root -> left;
        delete root;
        return tmp;
    } 
    Node* temp = getMin(root -> right);
    root -> val = temp -> val;
    root -> right = deleteNodeHelper(root -> right, temp->val);

    int bf = getBalanceFactor(root);
    if (bf >= -1 && bf <= 1) {
        return root;
    }
    if (bf > 1 && getBalanceFactor(root -> left) > 0) {
        return rightRotate(root);
    }
    if (bf > 1 && getBalanceFactor(root -> left) < 0) {
        root -> left = leftRotate(root -> left);
        return rightRotate(root);
    }
    if (bf < -1 && getBalanceFactor(root -> right) < 0) {
        return leftRotate(root);
    }
    if (bf < -1 && getBalanceFactor(root -> right) > 0) {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }
    return root;



}

Node* AVL::searchNodeHelper(Node* root, int val)
{
    if (!root || root -> val == val) {
        return root;
    } 

    if(val > root -> val) {
        return searchNodeHelper(root -> right, val);
    } else {
        return searchNodeHelper(root -> left, val);
    }

    return root;
}


//getHeight, getSize helpers
int AVL::getHeightHelper(Node* root)
{
    if (!root) {
        return 0;
    } 
    int left = getHeightHelper(root -> left);
    int right = getHeightHelper(root -> right);
    return std::max(left,right) + 1;
}

int AVL::getSizeHelper(Node* root)
{
    if (!root) {
        return 0;
    }

    int left = getSizeHelper(root -> left);
    int right = getSizeHelper(root -> right);
    return left + right + 1;
}

//balance factor 
int AVL::getBalanceFactor(Node* root)
{
    if (!root) return 0;
    return getHeightHelper(root -> left) - getHeightHelper(root -> right);
}

//rotations
Node* AVL::rightRotate(Node* root)
{
    Node* y = root -> left;
    Node* T = y -> right;
    y -> right = root;
    root -> left = T;
    return y;
}

Node* AVL::leftRotate(Node* root)
{
    Node* y = root -> right;
    Node* T = y -> left;
    y -> left = root;
    root -> right = T;
    return y;
}

Node* AVL::balance(Node* node, int val) {
    int bf = getBalanceFactor(node);
    
    //LL case
    if (bf > 1 && node->left && getBalanceFactor(node -> left) >= 0) {
        return rightRotate(node);
    } 

    //LR case 
    if (bf > 1 && node->left && getBalanceFactor(node -> left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //RR case
    if (bf < -1 && node->right && getBalanceFactor(node -> left) <= 0) {
        return leftRotate(node);
    }

    //RL case
    if (bf < -1 && node->right && getBalanceFactor(node -> left) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

//PUBLIC FUNCTIONS
//traversals
void AVL::inOrder()
{
    inOrderHelper(root);
    std::cout << std::endl;
}

void AVL::preOrder()
{
    preOrderHelper(root);
    std::cout << std::endl;
}

void AVL::postOrder()
{
    postOrderHelper(root);
    std::cout << std::endl;
}


//insert, delete, search
void AVL::insertNode(int val)
{
    root = insertNodeHelper(root, val);
}

void AVL::deleteNode(int val) 
{
    root = deleteNodeHelper(root, val);
}

Node* AVL::searchNode(int val)
{
    return searchNodeHelper(root, val);
}


//getMin, getMax
Node* AVL::getMin(Node* node)
{
    while (node && node -> left) {
        node = node -> left;
    }
    return node;
}

Node* AVL::getMin()
{
    return getMin(root);
}

Node* AVL::getMax(Node* node)
{
    while (node && node -> right) {
        node = node -> right;
    }
    return node;
}

Node* AVL::getMax()
{
    return getMax(root);
}


//getHeight, getSize
int AVL::getHeight()
{
    return getHeightHelper(root);
}

int AVL::getHeight(Node* node)
{
    return getHeightHelper(node);
}

int AVL::getSize()
{
    return getSizeHelper(root);
}

//predecessor, successor
Node* AVL::getPredecessor(int val)
{
    Node* current = searchNode(val);
    if (!current) {
        std::cerr << "Error. Node with value " << val << " was not found. " << std::endl;
        exit(1);
    }

    if (current -> left) {
        return getMax(current -> left);
    } 

    Node* predecessor = nullptr;
    Node* ancestor = root;
    
    while (ancestor != current) {
        if (current->val > ancestor->val) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

Node* AVL::getSuccessor(int val)
{
    Node* current = searchNode(val);
    if (!current) {
        std::cerr << "Error. Node with value " << val << " was not found. " << std::endl;
        exit(1);
    }

    if (current -> right) {
        return getMin(current -> right);
    }
    
    Node* ancestor = root;
    Node* successor = nullptr;
    while (ancestor != current) {
        if (ancestor -> val > val) {
            successor = ancestor;
            ancestor = ancestor -> left;
        } else {
            ancestor = ancestor -> right;
        }
    }
    return successor;

}


