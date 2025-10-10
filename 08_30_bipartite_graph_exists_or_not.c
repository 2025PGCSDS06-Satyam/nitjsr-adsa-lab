#include <stdio.h>

int g[100][100], c[100], n, e;

int bipartite() {
    for (int i = 0; i < n; i++) c[i] = -1;
    for (int s = 0; s < n; s++) if (c[s] == -1) {
        int q[100], f = 0, r = 0; q[r++] = s; c[s] = 0;
        while (f < r) {
            int u = q[f++];
            for (int v = 0; v < n; v++) if (g[u][v]) {
                if (c[v] == -1) c[v] = 1 - c[u], q[r++] = v;
                else if (c[v] == c[u]) return 0;
            }
        }
    }
    return 1;
}

int main() {
    printf("n e: "); scanf("%d %d", &n, &e);
    for (int i = 0, u, v; i < e; i++) scanf("%d %d", &u, &v), g[u][v] = g[v][u] = 1;
    printf(bipartite() ? "✅ Bipartite\n" : "❌ Not Bipartite\n");
}
