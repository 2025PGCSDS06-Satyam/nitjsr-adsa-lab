#include <stdio.h>
#include <stdlib.h>

typedef struct { int x, y; } P;
P p0;

int ori(P a, P b, P c) {
    int v = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
    return v ? (v > 0 ? 1 : 2) : 0;
}

int dist(P a, P b) { return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y); }

int cmp(const void *a, const void *b) {
    P p1 = *(P*)a, p2 = *(P*)b;
    int o = ori(p0, p1, p2);
    return o == 0 ? (dist(p0, p2) >= dist(p0, p1) ? -1 : 1) : (o == 2 ? -1 : 1);
}

void hull(P p[], int n) {
    int min = 0;
    for (int i = 1; i < n; i++)
        if (p[i].y < p[min].y || (p[i].y == p[min].y && p[i].x < p[min].x))
            min = i;
    P t = p[0]; p[0] = p[min]; p[min] = t;
    p0 = p[0];
    qsort(p + 1, n - 1, sizeof(P), cmp);

    P s[n]; int top = 2; s[0] = p[0]; s[1] = p[1]; s[2] = p[2];
    for (int i = 3; i < n; i++) {
        while (ori(s[top - 1], s[top], p[i]) != 2) top--;
        s[++top] = p[i];
    }
    printf("Convex Hull:\n");
    for (int i = 0; i <= top; i++) printf("(%d,%d)\n", s[i].x, s[i].y);
}

int main() {
    int n; printf("Enter number of points: "); scanf("%d", &n);
    P p[n]; for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
    hull(p, n);
}
