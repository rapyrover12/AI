#include <iostream>
using namespace std;

// Maximum number of vertices and edges
#define MAX_V 100
#define MAX_E 100

// Structure for an edge
struct Edge {
    int u, v; // Vertices (e.g., 0, 1)
    int weight; // Edge weight (e.g., 4)
};

// Parent array for cycle detection
int parent[MAX_V];

// Find the leader (root) of a vertex
int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

// Merge two groups (union)
void unionSets(int u, int v) {
    parent[find(u)] = find(v);
}

// Bubble sort edges by weight
void sortEdges(Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal's Algorithm
void kruskal(Edge edges[], int V, int E) {
    // Initialize parent array
    for (int i = 0; i < V; i++) {
        parent[i] = i; // Each vertex is its own leader
    }

    // Sort edges by weight
    sortEdges(edges, E);

    // Array to store MST edges
    Edge mst[MAX_E];
    int mstCount = 0;
    int totalWeight = 0;

    // Process edges
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        // Check if adding edge creates a cycle
        if (find(u) != find(v)) {
            mst[mstCount] = edges[i]; // Add edge to MST
            mstCount++;
            totalWeight += w;
            unionSets(u, v); // Merge groups
        }
    }

    // Print MST
    cout << "Minimum Spanning Tree edges:\n";
    for (int i = 0; i < mstCount; i++) {
        cout << mst[i].u << " - " << mst[i].v << ": " << mst[i].weight << endl;
    }
    cout << "Total weight: " << totalWeight << endl;
}

int main() {
    int V, E;
    Edge edges[MAX_E];

    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    // Input edges (u, v, weight)
    cout << "Enter edges (u v weight, 0-based vertices):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Run Kruskal's
    kruskal(edges, V, E);

    return 0;
}