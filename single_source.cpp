#include <iostream>
using namespace std;

// Maximum number of vertices
#define MAX_V 100
// Infinity (a large number for unreachable vertices)
#define INF 99999

// Dijkstra's Algorithm
void dijkstra(int graph[MAX_V][MAX_V], int V, int src) {
    // Array to store shortest distances from source
    int dist[MAX_V];
    // Array to track visited vertices
    bool visited[MAX_V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INF;      // Set all distances to infinity
        visited[i] = false; // Mark all vertices unvisited
    }
    dist[src] = 0; // Distance to source is 0

    // Process all vertices
    for (int count = 0; count < V; count++) {
        // Find unvisited vertex with minimum distance
        int minDist = INF, minVertex = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minVertex = i;
            }
        }

        // If no unvisited vertex found, break
        if (minVertex == -1) break;

        // Mark the selected vertex as visited
        visited[minVertex] = true;

        // Update distances to neighbors
        for (int i = 0; i < V; i++) {
            // If neighbor i is unvisited, connected to minVertex, and a shorter path exists
            if (!visited[i] && graph[minVertex][i] != 0 && dist[minVertex] + graph[minVertex][i] < dist[i]) {
                dist[i] = dist[minVertex] + graph[minVertex][i];
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To vertex " << i << ": ";
        if (dist[i] == INF)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int V, E, src;
    // Graph as adjacency matrix (0 means no edge)
    int graph[MAX_V][MAX_V] = {0};

    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    // Input edges (u, v, weight)
    cout << "Enter edges (u v weight, 0-based vertices):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // Directed edge u->v
        graph[v][u] = w; // For undirected graph, add v->u
    }

    // Input source vertex
    cout << "Enter source vertex (0 to " << V-1 << "): ";
    cin >> src;

    // Run Dijkstra's
    dijkstra(graph, V, src);

    return 0;
}