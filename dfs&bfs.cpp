#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 100; // Increased for safety
vector<int> graph[MAX];
bool visited[MAX];

// Add edge between u and v (1-based)
void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u); // Undirected
}

// Breadth-First Search
void BFS(int start, int v) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node; // No space for "1234567"

        for (int neighbor : graph[node]) {
            if (neighbor >= 1 && neighbor <= v && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// Depth-First Search
void DFS(int node, int v) {
    visited[node] = true;
    cout << node; // No space

    for (int neighbor : graph[node]) {
        if (neighbor >= 1 && neighbor <= v && !visited[neighbor]) {
            DFS(neighbor, v);
        }
    }
}

// Reset visited array
void resetVisited(int v) {
    for (int i = 1; i <= v; i++) {
        visited[i] = false;
    }
}

int main() {
    int v, e;
    cout << "Enter vertices and edges: ";
    cin >> v >> e;

    // Input edges
    cout << "Enter " << e << " edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 1 && u <= v && v >= 1 && v <= v) {
            addEdge(u, v);
        } else {
            cout << "Invalid edge: " << u << " " << v << endl;
            return 1;
        }
    }

    int start;
    cout << "Enter start node: ";
    cin >> start;
    if (start < 1 || start > v) {
        cout << "Invalid start node" << endl;
        return 1;
    }

    cout << "BFS: ";
    resetVisited(v);
    BFS(start, v);

    cout << "\nDFS: ";
    resetVisited(v);
    DFS(start, v);

    cout << endl;
    return 0;
}
