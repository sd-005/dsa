#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert a new node
    Node* insert(Node* root, int val) {
        if (root == NULL)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Search for a value
    bool search(Node* root, int key) {
        if (root == NULL)
            return false;
        if (root->data == key)
            return true;
        else if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // Longest path (height of tree)
    int longestPath(Node* root) {
        if (root == NULL)
            return 0;
        int left = longestPath(root->left);
        int right = longestPath(root->right);
        return max(left, right) + 1;
    }

    // Minimum value
    int findMin(Node* root) {
        if (root == NULL)
            return -1;
        while (root->left != NULL)
            root = root->left;
        return root->data;
    }

    // Mirror the tree
    void mirror(Node* root) {
        if (root == NULL)
            return;
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
};

int main() {
    BST tree;
    int choice, val;

    while (true) {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Search a Value\n";
        cout << "4. Longest Path from Root\n";
        cout << "5. Find Minimum Value\n";
        cout << "6. Mirror the Tree\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            tree.root = tree.insert(tree.root, val);
            break;

        case 2:
            cout << "Inorder Traversal: ";
            tree.inorder(tree.root);
            cout << endl;
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            if (tree.search(tree.root, val))
                cout << "Value found in tree.\n";
            else
                cout << "Value not found in tree.\n";
            break;

        case 4:
            cout << "Longest path (height) is: " << tree.longestPath(tree.root) << endl;
            break;

        case 5:
            cout << "Minimum value in tree is: " << tree.findMin(tree.root) << endl;
            break;

        case 6:
            tree.mirror(tree.root);
            cout << "Tree mirrored. Inorder now: ";
            tree.inorder(tree.root);
            cout << endl;
            break;

        case 7:
            cout << "Exiting program. Thank you.\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

