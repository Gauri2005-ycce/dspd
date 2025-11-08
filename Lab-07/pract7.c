#include <stdio.h>

int adj[10][10], visited[10];
int n = 9;

void createGraph() {
    int i, row, col;
    for (i = 1; i <= n; i++) {
        row = (i - 1) / 3;
        col = (i - 1) % 3;
        if (col < 2) adj[i][i + 1] = adj[i + 1][i] = 1;
        if (col > 0) adj[i][i - 1] = adj[i - 1][i] = 1;
        if (row < 2) adj[i][i + 3] = adj[i + 3][i] = 1;
        if (row > 0) adj[i][i - 3] = adj[i - 3][i] = 1;
    }
}

void BFS(int start) {
    int q[20], front = 0, rear = 0, i, v;
    for (i = 1; i <= n; i++) visited[i] = 0;
    q[rear++] = start;
    visited[start] = 1;
    printf("BFS Order: ");
    while (front < rear) {
        v = q[front++];
        printf("%d ", v);
        for (i = 1; i <= n; i++) {
            if (adj[v][i] && !visited[i]) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int start) {
    int stack[20], top = -1, i, v;
    for (i = 1; i <= n; i++) visited[i] = 0;
    stack[++top] = start;
    printf("DFS Order: ");
    while (top >= 0) {
        v = stack[top--];
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
            for (i = n; i >= 1; i--)
                if (adj[v][i] && !visited[i])
                    stack[++top] = i;
        }
    }
    printf("\n");
}

int main() {
    createGraph();
    int start = 1;
    BFS(start);
    DFS(start);
    return 0;
}
