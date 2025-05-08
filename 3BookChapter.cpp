#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Node of the tree
struct node {
    string label;               // Name of the book/chapter/section
    int childCount;             // How many children this node has
    node* child[10];            // Array of pointers to child nodes
};

class BookTree {
    node* root;

public:
    BookTree() {
        root = NULL;
    }

    void createTree() {
        int numChapters, numSections;
        root = new node;
        
        cout << "Enter the name of the Book: ";
        cin >> root->label;

        cout << "Enter number of Chapters in book: ";
        cin >> numChapters;
        root->childCount = numChapters;

        for (int i = 0; i < numChapters; i++) {
            root->child[i] = new node;

            cout << "\nEnter name of Chapter " << i + 1 << ": ";
            cin >> root->child[i]->label;

            cout << "Enter number of Sections in Chapter '" << root->child[i]->label << "': ";
            cin >> numSections;
            root->child[i]->childCount = numSections;

            for (int j = 0; j < numSections; j++) {
                root->child[i]->child[j] = new node;

                cout << "Enter name of Section " << j + 1 << " of Chapter '" << root->child[i]->label << "': ";
                cin >> root->child[i]->child[j]->label;

                // You can extend this to add subsections here similarly
                root->child[i]->child[j]->childCount = 0;
            }
        }
    }

    void displayTree() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }

        cout << "\n--- Book Structure ---\n";
        cout << "Book Title: " << root->label << endl;

        for (int i = 0; i < root->childCount; i++) {
            cout << "\n  Chapter " << i + 1 << ": " << root->child[i]->label;

            for (int j = 0; j < root->child[i]->childCount; j++) {
                cout << "\n    Section " << j + 1 << ": " << root->child[i]->child[j]->label;
            }
        }
        cout << endl;
    }
};
int main() {
    BookTree tree;
    int choice;

    while (true) {
        cout << "\n-----------------\nBook Tree Menu\n-----------------\n";
        cout << "1. Create Book Tree\n";
        cout << "2. Display Book Tree\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.createTree();
                break;
            case 2:
                tree.displayTree();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
