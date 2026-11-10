#include <iostream>
using namespace std;

#define MAX 10

// Manual Queue
class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void push(int x) {
        if (rear == MAX - 1) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void pop() {
        if (front == -1 || front > rear) return;
        front++;
    }

    int top() {
        return arr[front];
    }

    bool empty() {
        return (front == -1 || front > rear);
    }
};

class Graph {
    int adj[MAX][MAX];
    int n;

public:
    Graph(int nodes) {
        n = nodes;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    void BFS(int start) {
        int visited[MAX] = {0};
        int level[MAX];
        int parent[MAX];

        for (int i = 1; i <= n; i++) {
            level[i] = -1;
            parent[i] = -1;
        }

        Queue q;

        visited[start] = 1;
        level[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.top();
            q.pop();

            for (int v = 1; v <= n; v++) {
                if (adj[u][v] == 1 && !visited[v]) {
                    visited[v] = 1;
                    level[v] = level[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        // Count nodes at each level
        int maxLevel = 0;
        for (int i = 1; i <= n; i++) {
            if (level[i] > maxLevel)
                maxLevel = level[i];
        }

        cout << "BFS Levels:\n";
        for (int l = 0; l <= maxLevel; l++) {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (level[i] == l)
                    count++;
            }
            cout << "Level " << l << ": " << count << " nodes\n";
        }

        // 🔷 Print path from 3 to 6
        int target = 6;
        int path[MAX], idx = 0;

        int temp = target;
        while (temp != -1) {
            path[idx++] = temp;
            temp = parent[temp];
        }

        cout << "\nPath from 3 to 6:\n";
        for (int i = idx - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);

    // Graph edges from the image
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    g.BFS(3);

    return 0;
}
