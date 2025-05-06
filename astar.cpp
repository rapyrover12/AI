#include <iostream>
using namespace std;

const int MAX = 20; // Maximum grid size
int grid[MAX][MAX]; // Grid array
int n; // User-defined grid size (n x n)

// Arrays to store g, h, f scores
int g[MAX][MAX]; // Cost from start to current cell
int h[MAX][MAX]; // Heuristic (estimated cost to goal)
int f[MAX][MAX]; // Total cost (g + h)

// Parent array to trace the path
int parentX[MAX][MAX];
int parentY[MAX][MAX];

// Open list (nodes to explore) and closed list (visited nodes)
int openX[MAX * MAX], openY[MAX * MAX]; // Store coordinates
int closed[MAX][MAX]; // 1 if in closed list, 0 otherwise
int openCount; // Number of nodes in open list

// Directions for movement (up, right, down, left)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// Calculate Manhattan distance as heuristic
int calculateH(int x, int y, int goalX, int goalY) {
    return abs(x - goalX) + abs(y - goalY);
}

// Check if a position is valid
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && closed[x][y] == 0;
}

// Add a node to the open list
void addToOpen(int x, int y) {
    openX[openCount] = x;
    openY[openCount] = y;
    openCount++;
}

// Find the node in open list with the lowest f-score
bool findLowestF(int& x, int& y) {
    if (openCount == 0) return false;
    int minF = 9999, index = -1;
    for (int i = 0; i < openCount; i++) {
        int fx = f[openX[i]][openY[i]];
        if (fx < minF) {
            minF = fx;
            index = i;
        }
    }
    x = openX[index];
    y = openY[index];
    for (int i = index; i < openCount - 1; i++) {
        openX[i] = openX[i + 1];
        openY[i] = openY[i + 1];
    }
    openCount--;
    return true;
}

// A* algorithm
void aStar(int startX, int startY, int goalX, int goalY) {
    // Initialize
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            g[i][j] = 9999;
            h[i][j] = calculateH(i, j, goalX, goalY);
            f[i][j] = 9999;
            closed[i][j] = 0;
            parentX[i][j] = -1;
            parentY[i][j] = -1;
        }

    openCount = 0;
    g[startX][startY] = 0;
    f[startX][startY] = h[startX][startY];
    addToOpen(startX, startY);

    // Main loop
    while (openCount > 0) {
        int currentX, currentY;
        if (!findLowestF(currentX, currentY)) break;

        closed[currentX][currentY] = 1;

        if (currentX == goalX && currentY == goalY) {
            cout << "Path found!\n";
            int pathX[MAX * MAX], pathY[MAX * MAX], pathLen = 0;
            int x = goalX, y = goalY;
            while (x != -1 && y != -1) {
                pathX[pathLen] = x;
                pathY[pathLen] = y;
                pathLen++;
                int px = parentX[x][y], py = parentY[x][y];
                x = px;
                y = py;
            }
            cout << "Path (from start to goal): ";
            for (int i = pathLen - 1; i >= 0; i--)
                cout << "(" << pathX[i] << "," << pathY[i] << ") ";
            cout << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];
            if (isValid(newX, newY)) {
                int newG = g[currentX][currentY] + 1;
                if (newG < g[newX][newY]) {
                    g[newX][newY] = newG;
                    f[newX][newY] = g[newX][newY] + h[newX][newY];
                    parentX[newX][newY] = currentX;
                    parentY[newX][newY] = currentY;
                    addToOpen(newX, newY);
                }
            }
        }
    }
    cout << "No path found!\n";
}

int main() {
    // Input grid size
    cout << "Enter grid size (n for n x n, max 20): ";
    cin >> n;
    if (n <= 0 || n > MAX) {
        cout << "Invalid size!\n";
        return 1;
    }

    // Input grid
    cout << "Enter grid (" << n << "x" << n << ", 0 = open, 1 = wall):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0 && grid[i][j] != 1) {
                cout << "Invalid cell value! Use 0 or 1.\n";
                return 1;
            }
        }

    // Input start and goal positions
    int startX, startY, goalX, goalY;
    cout << "Enter start position (x y, 0 to " << n-1 << "): ";
    cin >> startX >> startY;
    cout << "Enter goal position (x y, 0 to " << n-1 << "): ";
    cin >> goalX >> goalY;

    // Validate start and goal
    if (startX < 0 || startX >= n || startY < 0 || startY >= n ||
        goalX < 0 || goalX >= n || goalY < 0 || goalY >= n) {
        cout << "Start or goal out of bounds!\n";
        return 1;
    }
    if (grid[startX][startY] == 1 || grid[goalX][goalY] == 1) {
        cout << "Start or goal is on a wall!\n";
        return 1;
    }

    // Print the grid
    cout << "\nGrid (0 = open, 1 = wall):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

    cout << "Finding path from (" << startX << "," << startY << ") to (" << goalX << "," << goalY << "):\n";
    aStar(startX, startY, goalX, goalY);

    return 0;
}