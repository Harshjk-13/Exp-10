#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array for DFS and BFS

// Queue for BFS (circular queue implementation)
int queue[MAX], front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front++];
}

// BFS function
void BFS(int start, int vertices) {
    int i;
    printf("BFS Traversal: ");
    
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Traverse the adjacent vertices of the current node
        for (i = 0; i < vertices; i++) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS function (recursive)
void DFS(int vertex, int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    // Traverse the adjacent vertices
    for (int i = 0; i < vertices; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

// Helper function to reset the visited array
void resetVisited(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
}

// Main function
int main() {
    int vertices, edges;
    int u, v, start;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    // Input the edges
    printf("Enter the edges (from -> to) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // Directed graph
    }

    // Input the start vertex for BFS and DFS
    printf("Enter the start vertex for traversal: ");
    scanf("%d", &start);

    // Perform BFS
    resetVisited(vertices);
    BFS(start, vertices);

    // Perform DFS
    resetVisited(vertices);
    printf("DFS Traversal: ");
    DFS(start, vertices);
    printf("\n");

    return 0;
}
