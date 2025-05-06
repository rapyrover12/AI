#include <iostream>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX];     // Adjacency matrix
bool visited[MAX];       // Visited array for both DFS and BFS

// -------- DFS (Recursive) --------
void DFS(int node, int vertices) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

// -------- BFS (Using array as queue) --------
void BFS(int start, int vertices) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

// -------- Main Program --------
int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    cout << "Enter " << edges << " edges (e.g., u v for edge between 0 and " << vertices - 1 << "):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u][v] = 1;
            graph[v][u] = 1; // Undirected
        } else {
            cout << "Invalid edge! Try again.\n";
            i--; // repeat the edge
        }
    }

    int start;
    cout << "Enter starting node (0 to " << vertices - 1 << "): ";
    cin >> start;

    // -------- DFS Traversal --------
    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    cout << "DFS traversal: ";
    DFS(start, vertices);
    cout << endl;

    // -------- BFS Traversal --------
    cout << "BFS traversal: ";
    BFS(start, vertices);
    cout << endl;

    return 0;
}
