#include <stdio.h>

int g[20][20], n, e, m, found = 0;

int isClique(int v[], int size) {
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (!g[v[i]][v[j]]) return 0;
    return 1;
}

void findCliques(int start, int depth, int v[]) {
    if (found) return;
    if (depth == m) { if (isClique(v, m)) found = 1; return; }
    for (int i = start; i < n; i++) {
        v[depth] = i;
        findCliques(i + 1, depth + 1, v);
    }
}

int main() {
    printf("n e: "); scanf("%d %d", &n, &e);
    for (int i = 0, u, v; i < e; i++) scanf("%d %d", &u, &v), g[u][v] = g[v][u] = 1;
    printf("m: "); scanf("%d", &m);
    int vtx[20]; findCliques(0, 0, vtx);
    printf(found ? "Clique of size %d exists.\n" : "No clique of size %d.\n", m);
}
