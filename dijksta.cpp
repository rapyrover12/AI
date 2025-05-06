#include <iostream>
using namespace std;

// Maximum number of vertices
#define MAX_V 100
// Infinity for unreachable vertices
#define INF 99999

// Dijkstra's Algorithm
void dijkstra(int graph[MAX_V][MAX_V], int V, int src) {
    int dist[MAX_V];    // Shortest distances from source
    bool visited[MAX_V]; // Track visited vertices

    // Initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INF;      // All distances unknown
        visited[i] = false; // All unvisited
    }
    dist[src] = 0; // Source distance is 0

    // Process all vertices
    for (int count = 0; count < V; count++) {
        // Find unvisited vertex with minimum distance
        int minDist = INF, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        // If no unvisited vertex, break
        if (u == -1) break;

        // Mark vertex u as visited
        visited[u] = true;

        // Update distances to neighbors
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print results
    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To vertex " << i << ": ";
        if (dist[i] == INF) cout << "Unreachable\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    int V, E, src;
    int graph[MAX_V][MAX_V] = {0}; // Adjacency matrix

    // Input
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v weight, 0-based vertices):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // Directed edge
        graph[v][u] = w; // For undirected graph
    }
    cout << "Enter source vertex (0 to " << V-1 << "): ";
    cin >> src;

    // Run Dijkstra's
    dijkstra(graph, V, src);

    return 0;
}