#include <stdio.h>
#include <stdbool.h>

#define V 5 // Número de vértices
#define INF 99999 // infinito para vértices inacessíveis

int encontrarMenorDistancia(int dist[], bool visitado[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (visitado[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// O algoritmo de Dijkstra em função
void dijkstra(int grafo[V][V], int origem) {
    int dist[V];      // menores distâncias
    bool visitado[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visitado[i] = false;
    }

    dist[origem] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = encontrarMenorDistancia(dist, visitado);

        visitado[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visitado[v] && grafo[u][v] && dist[u] != INF && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    // tabela de distâncias resultantes
    printf("Vértice \t Distância Mínima da Origem (%d)\n", origem);
    for (int i = 0; i < V; i++) {
        printf("%d \t\t ", i);
        if (dist[i] == INF) {
            printf("Inacessível\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

int main() {
    int grafo[V][V] = {
        {0, 4, 2, 0, 0},
        {0, 0, 3, 2, 3},
        {0, 1, 0, 4, 5},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    dijkstra(grafo, 0);

    return 0;
}