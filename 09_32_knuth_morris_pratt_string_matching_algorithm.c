#include <stdio.h>
#include <string.h>

void computeLPS(char *p, int m, int lps[]) {
    int len = 0;
    lps[0] = 0;
    for (int i = 1; i < m;) {
        if (p[i] == p[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
}

void KMP(char *p, char *t) {
    int m = strlen(p), n = strlen(t), lps[m], i = 0, j = 0;
    computeLPS(p, m, lps);
    while (i < n) {
        if (p[j] == t[i]) { i++; j++; }
        if (j == m) { printf("Pattern found at index %d\n", i - j); j = lps[j - 1]; }
        else if (i < n && p[j] != t[i]) j ? (j = lps[j - 1]) : i++;
    }
}

int main() {
    char t[100], p[100];
    printf("Enter text: "); gets(t);
    printf("Enter pattern: "); gets(p);
    KMP(p, t);
}
