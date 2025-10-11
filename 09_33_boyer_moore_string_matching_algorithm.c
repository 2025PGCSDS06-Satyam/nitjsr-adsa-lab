#include <stdio.h>
#include <string.h>
#define CH 256

void BM(char *t, char *p) {
    int n = strlen(t), m = strlen(p), bc[CH];
    for (int i = 0; i < CH; i++) bc[i] = -1;
    for (int i = 0; i < m; i++) bc[(unsigned char)p[i]] = i;

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && p[j] == t[s + j]) j--;
        if (j < 0) {
            printf("Pattern found at index %d\n", s);
            s += (s + m < n) ? m - bc[(unsigned char)t[s + m]] : 1;
        } else s += (j - bc[(unsigned char)t[s + j]] > 1) ? j - bc[(unsigned char)t[s + j]] : 1;
    }
}

int main() {
    char t[100], p[100];
    printf("Enter text: "); gets(t);
    printf("Enter pattern: "); gets(p);
    BM(t, p);
}
