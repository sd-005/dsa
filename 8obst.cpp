#include<iostream>
#include<climits>
using namespace std;

#define SIZE 10

class OBST {
    int p[SIZE];  // Probabilities of searching for an element
    int q[SIZE];  // Probabilities of not finding an element
    int a[SIZE];  // Elements for building OBST
    int w[SIZE][SIZE];  // Weight matrix
    int c[SIZE][SIZE];  // Cost matrix
    int r[SIZE][SIZE];  // Root matrix
    int n;  // Number of nodes

public:
    // Function to accept input data from the user
    void get_data() {
        cout << "\nOptimal Binary Search Tree\n";
        cout << "\nEnter the number of nodes: ";
        cin >> n;
        
        cout << "\nEnter the data (Elements, p[], q[]):\n";
        
        // Input elements
        for (int i = 1; i <= n; i++) {
            cout << "a[" << i << "]: ";
            cin >> a[i];
        }
        
        // Input search probabilities
        for (int i = 1; i <= n; i++) {
            cout << "p[" << i << "]: ";
            cin >> p[i];
        }
        
        // Input probabilities of not finding elements
        for (int i = 0; i <= n; i++) {
            cout << "q[" << i << "]: ";
            cin >> q[i];
        }
    }

    // Function to compute the minimum value for the cost matrix
    int Min_Value(int i, int j) {
        int min_cost = INT_MAX, k;
        for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++) {
            int cost = c[i][m - 1] + c[m][j];
            if (cost < min_cost) {
                min_cost = cost;
                k = m;
            }
        }
        return k;
    }

    // Function to build the OBST using dynamic programming
    void build_OBST() {
        for (int i = 0; i < n; i++) {
            // Initialize base case for one node
            w[i][i] = q[i];
            r[i][i] = c[i][i] = 0;

            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        }
        w[n][n] = q[n];
        r[n][n] = c[n][n] = 0;

        // Fill the tables for trees with more than one node
        for (int m = 2; m <= n; m++) {
            for (int i = 0; i <= n - m; i++) {
                int j = i + m;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                int k = Min_Value(i, j);
                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
                r[i][j] = k;
            }
        }
    }

    // Function to display the optimal binary search tree
    void build_tree() {
        cout << "The Optimal Binary Search Tree for the given nodes is:\n";
        cout << "Root of the OBST: " << r[0][n] << "\n";
        cout << "Cost of this OBST: " << c[0][n] << "\n";
        cout << "\n\tNODE\tLEFT CHILD\tRIGHT CHILD\n";

        int queue[20], front = -1, rear = -1;
        queue[++rear] = 0;
        queue[++rear] = n;

        while (front != rear) {
            int i = queue[++front];
            int j = queue[++front];
            int k = r[i][j];
            
            cout << "\n\t" << k;

            // Display left child
            if (r[i][k - 1] != 0) {
                cout << "\t\t" << r[i][k - 1];
                queue[++rear] = i;
                queue[++rear] = k - 1;
            } else {
                cout << "\t\t";
            }

            // Display right child
            if (r[k][j] != 0) {
                cout << "\t" << r[k][j];
                queue[++rear] = k;
                queue[++rear] = j;
            } else {
                cout << "\t";
            }
        }
        cout << "\n";
    }
};

// Main function
int main() {
    OBST obj;
    obj.get_data();  // Get data from the user
    obj.build_OBST();  // Build the OBST
    obj.build_tree();  // Display the OBST

    return 0;
}
// Optimal Binary Search Tree

// Enter the number of nodes: 3

// Enter the data (Elements, p[], q[]):
// a[1]: 10
// a[2]: 20
// a[3]: 30

// p[1]: 0.2
// p[2]: 0.3
// p[3]: 0.5

// q[0]: 0.1
// q[1]: 0.15
// q[2]: 0.2
// q[3]: 0.25
// The Optimal Binary Search Tree for the given nodes is:
// Root of the OBST: 2
// Cost of this OBST: 1.85

//         NODE    LEFT CHILD    RIGHT CHILD
//         2       1             3
