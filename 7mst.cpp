#include <iostream>
#include <climits>
using namespace std;

void primsAlgorithm(int graph[10][10], int V) {
    int parent[10]; // To store MST
    int key[10];    // To pick minimum weight edge
    bool inMST[10]; // To track vertices included in MST

    // Initialize all keys as infinite and inMST as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    key[0] = 0;      // Start from the first vertex
    parent[0] = -1;  // First node is the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;

        // Pick the vertex with the minimum key value
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the result
    int totalCost = 0;
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < V; i++) {
        cout << "Office " << parent[i] + 1 << " - Office " << i + 1
             << " : Cost = " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total minimum cost to connect all offices: " << totalCost << endl;
}

int main() {
    int V;
    cout << "Enter the number of offices (vertices): ";
    cin >> V;

    int graph[10][10];

    cout << "\nEnter the cost matrix for the offices (0 means no connection):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "Cost between office " << i + 1 << " and office " << j + 1 << ": ";
            cin >> graph[i][j];
        }
    }

    primsAlgorithm(graph, V);

    return 0;
}