/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAN
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: DFS, BFS uygulamasý
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

void bfs(int adj[MAX][MAX], int start) {
    int i;
    bool visited[MAX] = {false};
    
    visited[start] = true;
    enqueue(start);

    printf("BFS Traversal: ");
    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < MAX; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

void dfsRec(int adj[MAX][MAX], int vertex, bool visited[]) {
    int i;
    visited[vertex] = true;
    printf("%d ", vertex);

    for (i = 0; i < MAX; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfsRec(adj, i, visited);
        }
    }
}

void dfs(int adj[MAX][MAX], int start) {
    bool visited[MAX] = {false};
    printf("DFS Traversal: ");
    dfsRec(adj, start, visited);
    printf("\n");
}

int main() {
    int adjMatrix[MAX][MAX] = {
        {0, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 0}, 
        {1, 0, 0, 1, 0}, 
        {0, 1, 1, 0, 1}, 
        {0, 0, 0, 1, 0}  
    };

    bfs(adjMatrix, 0);
    dfs(adjMatrix, 0);

    return 0;
}
