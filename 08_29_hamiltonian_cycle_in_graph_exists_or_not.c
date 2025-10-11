#include <stdio.h>

int g[20][20], path[20], vis[20], n, e, found = 0;

void hamilton(int pos) {
    if (found) return;
    if (pos == n && g[path[pos - 1]][path[0]]) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < n; i++) printf("%d ", path[i]);
        printf("%d\n", path[0]);
        found = 1;
        return;
    }
    for (int v = 1; v < n; v++)
        if (!vis[v] && g[path[pos - 1]][v]) {
            vis[v] = 1; path[pos] = v;
            hamilton(pos + 1);
            vis[v] = 0;
        }
}

int main() {
    printf("n e: "); scanf("%d %d", &n, &e);
    for (int i = 0, u, v; i < e; i++) scanf("%d %d", &u, &v), g[u][v] = g[v][u] = 1;
    path[0] = 0; vis[0] = 1;
    hamilton(1);
    if (!found) printf("No Hamiltonian cycle.\n");
}
