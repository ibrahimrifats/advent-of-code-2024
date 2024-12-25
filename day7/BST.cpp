#include <iostream>
using namespace std;

// Node structure for the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// BST class
class BST {
private:
    Node* root;

    // Helper function for inserting a node
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Helper function for in-order traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;

        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Helper function for searching a value
    bool searchNode(Node* node, int value) {
        if (node == nullptr) return false;

        if (node->data == value) return true;
        if (value < node->data) return searchNode(node->left, value);

        return searchNode(node->right, value);
    }

    // Helper function to find the minimum value node
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function for deleting a node
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    bool search(int value) {
        return searchNode(root, value);
    }

    void displayInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

// Main function
int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order Traversal: ";
    bst.displayInOrder();

    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 25: " << (bst.search(25) ? "Found" : "Not Found") << endl;

    cout << "Deleting 20...\n";
    bst.remove(20);
    cout << "In-order Traversal after deletion: ";
    bst.displayInOrder();

    cout << "Deleting 30...\n";
    bst.remove(30);
    cout << "In-order Traversal after deletion: ";
    bst.displayInOrder();

    return 0;
}
