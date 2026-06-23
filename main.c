#include <stdio.h>
#include <stdbool.h>

#define V 5 // Numero de vertices
#define INF 99999 // Infinito para vertices inacessiveis

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

// O algoritmo de Dijkstra em funcao
void dijkstra(int grafo[V][V], int origem) {
    int dist[V];      // Menores distancias
    bool visitado[V]; // Array para mapear os vertices ja processados

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

    // Tabela de distancias resultantes
    printf("Vertice \t Distancia Minima da Origem (%d)\n", origem);
    for (int i = 0; i < V; i++) {
        printf("%d \t\t ", i);
        if (dist[i] == INF) {
            printf("Inacessivel\n");
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