#include <stdio.h>

#define MAX 30

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void union_set(int a, int b) {
    parent[find(a)] = find(b);
}

void kruskal(Edge edges[], int n, int e) {
    int i, j, total = 0;
    for (i = 0; i < e - 1; i++)
        for (j = 0; j < e - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        if (u != v) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            union_set(u, v);
        }
    }

    printf("Total weight of MST = %d\n", total);
}

int main() {
    int n, e, i;
    Edge edges[MAX];

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    kruskal(edges, n, e);
    return 0;
}
