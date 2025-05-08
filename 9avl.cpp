#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
using namespace std; 
 
class Node { 
public: 
    string key; 
    string value; 
    Node* left; 
    Node* right; 
    int height; 
 
    Node(string k, string v) : key(k), value(v), left(nullptr), right(nullptr), height(1) {} 
}; 
 
class AVLTree { 
private: 
    Node* root; 
 
    int getHeight(Node* node) { 
        return node ? node->height : 0; 
    } 
 
    void updateHeight(Node* node) { 
        node->height = 1 + max(getHeight(node->left), getHeight(node->right)); 
    } 
 
    int getBalance(Node* node) { 
        return node ? getHeight(node->left) - getHeight(node->right) : 0; 
    } 
 
    Node* rotateRight(Node* y) { 
        Node* x = y->left; 
        Node* T2 = x->right; 
 
        x->right = y; 
        y->left = T2; 
 
        updateHeight(y); 
        updateHeight(x); 
 
        return x; 
    } 
 
    Node* rotateLeft(Node* x) { 
        Node* y = x->right; 
        Node* T2 = y->left; 
 
        y->left = x; 
        x->right = T2; 
 
        updateHeight(x); 
        updateHeight(y); 
 
        return y; 
    } 
 
    Node* insert(Node* node, string key, string value) { 
        if (!node) return new Node(key, value); 
 
        if (key < node->key) 
            node->left = insert(node->left, key, value); 
        else if (key > node->key) 
            node->right = insert(node->right, key, value); 
        else { 
            // Key already exists, update value 
            node->value = value; 
            return node; 
        } 
 
        updateHeight(node); 
 
        int balance = getBalance(node); 
 
        if (balance > 1 && key < node->left->key) 
            return rotateRight(node); 
 
        if (balance < -1 && key > node->right->key) 
            return rotateLeft(node); 
 
        if (balance > 1 && key > node->left->key) { 
            node->left = rotateLeft(node->left); 
            return rotateRight(node); 
        } 
 
        if (balance < -1 && key < node->right->key) { 
            node->right = rotateRight(node->right); 
            return rotateLeft(node); 
        } 
 
        return node; 
    } 
 
    Node* minNode(Node* node) { 
        Node* current = node; 
        while (current && current->left) 
            current = current->left; 
        return current; 
    } 
 
    Node* deleteNode(Node* root, string key) { 
        if (!root) return root; 
 
        if (key < root->key) 
            root->left = deleteNode(root->left, key); 
        else if (key > root->key) 
            root->right = deleteNode(root->right, key); 
        else { 
            if (!root->left || !root->right) { 
                Node* temp = root->left ? root->left : root->right; 
                if (!temp) { 
                    temp = root; 
                    root = nullptr; 
                } else 
                    *root = *temp; 
                delete temp; 
            } else { 
                Node* temp = minNode(root->right); 
                root->key = temp->key; 
                root->value = temp->value; 
                root->right = deleteNode(root->right, temp->key); 
            } 
        } 
 
        if (!root) return root; 
 
        updateHeight(root); 
 
        int balance = getBalance(root); 
 
        if (balance > 1 && getBalance(root->left) >= 0) 
            return rotateRight(root); 
 
        if (balance > 1 && getBalance(root->left) < 0) { 
            root->left = rotateLeft(root->left); 
            return rotateRight(root); 
        } 
 
        if (balance < -1 && getBalance(root->right) <= 0) 
            return rotateLeft(root); 
 
        if (balance < -1 && getBalance(root->right) > 0) { 
            root->right = rotateRight(root->right); 
            return rotateLeft(root); 
        } 
 
        return root; 
    } 
 
    Node* search(Node* node, const string& key) { 
        if (!node || node->key == key) 
            return node; 
 
        if (key < node->key) 
            return search(node->left, key); 
        else 
            return search(node->right, key); 
    } 
 
    void inOrder(Node* node, vector<pair<string, string>>& result) { 
        if (node) { 
            inOrder(node->left, result); 
            result.push_back({node->key, node->value}); 
            inOrder(node->right, result); 
        } 
    } 
 
    void reverseInOrder(Node* node, vector<pair<string, string>>& result) { 
        if (node) { 
            reverseInOrder(node->right, result); 
            result.push_back({node->key, node->value}); 
            reverseInOrder(node->left, result); 
        } 
    } 
 
public: 
    AVLTree() : root(nullptr) {} 
 
    void insertKeyValue(const string& key, const string& value) { 
        root = insert(root, key, value); 
    } 
 
    string searchKey(const string& key) { 
        Node* node = search(root, key); 
        return node ? node->value : ""; 
    } 
 
    void deleteKey(const string& key) { 
        root = deleteNode(root, key); 
    } 
 
    vector<pair<string, string>> displaySorted(bool descending = false) { 
        vector<pair<string, string>> result; 
        if (descending) 
            reverseInOrder(root, result); 
        else 
            inOrder(root, result); 
        return result; 
    } 
 
    int findMaxComparisons(int n) { 
        return log2(n) + 1;  // Maximum comparisons in AVL Tree is O(log n) 
    } 
}; 
 
int main() { 
    AVLTree avlTree; 
    string key, value; 
    int choice; 
 
    while (true) { 
        cout << "\nAVL Tree Dictionary Operations: \n"; 
        cout << "1. Insert a new keyword\n"; 
        cout << "2. Search for a keyword\n"; 
        cout << "3. Delete a keyword\n"; 
        cout << "4. Display sorted dictionary (Ascending)\n"; 
        cout << "5. Display sorted dictionary (Descending)\n"; 
        cout << "6. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        if (choice == 1) { 
            // Insert a new keyword 
            cout << "Enter keyword: "; 
            cin >> key; 
            cout << "Enter meaning: "; 
            cin.ignore();  // To ignore newline character left by previous input 
            getline(cin, value); 
            avlTree.insertKeyValue(key, value); 
            cout << "Keyword inserted successfully.\n"; 
        } else if (choice == 2) { 
            // Search for a keyword 
            cout << "Enter keyword to search: "; 
            cin >> key; 
            string meaning = avlTree.searchKey(key); 
            if (meaning != "") 
                cout << "Meaning of " << key << ": " << meaning << endl; 
            else 
                cout << "Keyword not found.\n"; 
        } else if (choice == 3) { 
            // Delete a keyword 
            cout << "Enter keyword to delete: "; 
            cin >> key; 
            avlTree.deleteKey(key); 
            cout << "Keyword deleted successfully.\n"; 
        } else if (choice == 4) { 
            // Display sorted dictionary in ascending order 
            vector<pair<string, string>> sorted = avlTree.displaySorted(); 
            cout << "\nDictionary in Ascending Order:\n"; 
            for (const auto& entry : sorted) { 
                cout << entry.first << ": " << entry.second << endl; 
            } 
        } else if (choice == 5) { 
            // Display sorted dictionary in descending order 
            vector<pair<string, string>> sorted = avlTree.displaySorted(true); 
            cout << "\nDictionary in Descending Order:\n"; 
            for (const auto& entry : sorted) { 
                cout << entry.first << ": " << entry.second << endl; 
            } 
        } else if (choice == 6) { 
            // Exit the program 
            break; 
        } else { 
            cout << "Invalid choice. Please try again.\n"; 
        } 
    } 
 
    return 0; 
} 
 