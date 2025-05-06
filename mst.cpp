#include <iostream>
using namespace std;

const int MAX = 100;

struct Edge {
    int u, v, weight;
};

// Function to sort edges by weight (Bubble Sort for simplicity)
void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Disjoint set (Union-Find)
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

int main() {
    int V, E;
    Edge edges[MAX];

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Initialize parent array
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight
    sortEdges(edges, E);

    cout << "\nMinimum Spanning Tree:\n";
    int mstWeight = 0;
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) 
        {
            cout << u << " - " << v << " : " << w << endl;
            mstWeight += w;
            unionSets(u, v);
        }
    }

    cout << "Total weight of MST: " << mstWeight << endl;
    return 0;
}
