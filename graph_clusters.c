/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAN
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: Array olarak verilen bir graph’da cluster çýkarma.
 */

#include <stdio.h>
#include <stdbool.h>

#define V 5

void DFS(int adj[V][V], int v, bool visited[]) {
    int i;
    visited[v] = true;
    printf("%d ", v);

    for (i = 0; i < V; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(adj, i, visited);
        }
    }
}

void findClusters(int adj[V][V]) {
    int i, v;
    int clusterCount = 0;
    bool visited[V];

    for(i = 0; i < V; i++) visited[i] = false;

    for (v = 0; v < V; v++) {
        if (visited[v] == false) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            DFS(adj, v, visited);
            printf("\n");
        }
    }
}

int main() {
    int adjMatrix[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };

    findClusters(adjMatrix);

    return 0;
}
