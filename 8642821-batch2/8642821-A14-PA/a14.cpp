#include <bits/stdc++.h>
using namespace std;

char b[5], e[5];

int main() {
    for (int i = 0; i < 4; i++)
        scanf(" %c", &b[i]);
    for (int i = 0; i < 4; i++)
        scanf(" %c", &e[i]);
    swap(e[2], e[3]);
    swap(b[2], b[3]);
    int k = 0;
    int i;
    if (e[k] == 'X') k++;
    for (i = 0; i < 3; i++) {
        if (b[i] == 'X') continue;
        if (e[k] == b[i])
            break;
    }
    //printf("%s %s %d %d\n", b, e, i, k);
    for (int p = 0; p < 3; p++) {
        if (b[i] == 'X') i = (i+1)%4;
        if (e[k] == 'X') k = (k+1)%4;
        if (b[i] != e[k]) {
            printf("NO\n");
            return 0;
        }
        k = (k+1)%4;
        i = (i+1)%4;
    }
    printf("YES\n");
    return 0;
}

