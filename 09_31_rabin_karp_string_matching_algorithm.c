#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

void rabinKarp(char *pat, char *txt) {
    int M = strlen(pat), N = strlen(txt);
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < M - 1; i++) h = (h * d) % q;
    for (int i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= N - M; i++) {
        if (p == t && strncmp(txt + i, pat, M) == 0)
            printf("Pattern found at index %d\n", i);
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    char txt[100], pat[100];
    printf("Enter text: "); gets(txt);
    printf("Enter pattern: "); gets(pat);
    rabinKarp(pat, txt);
}
