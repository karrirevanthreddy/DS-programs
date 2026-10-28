#include <stdio.h>

#define MAX 20

int n, adj[MAX][MAX], visited[MAX];

void bfs(int s)
{
    int q[MAX], f = 0, r = 0, u, v;
    for (v = 0; v < n; v++) visited[v] = 0;
    visited[s] = 1;
    q[r++] = s;
    while (f < r) {
        u = q[f++];
        printf("%d ", u);
        for (v = 0; v < n; v++)
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                q[r++] = v;
            }
    }
}

void dfs(int u)
{
    int v;
    visited[u] = 1;
    printf("%d ", u);
    for (v = 0; v < n; v++)
        if (adj[u][v] && !visited[v])
            dfs(v);
}

int main()
{
    int i, j, s;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting node: ");
    scanf("%d", &s);
    printf("Nodes reachable using BFS: ");
    bfs(s);
    for (i = 0; i < n; i++) visited[i] = 0;
    printf("\nNodes reachable using DFS: ");
    dfs(s);
    printf("\n");
    return 0;
}
