#include <bits/stdc++.h>
using namespace std;

int n, v[120];

int main() {
    scanf(" %d", &n);
    int pos, neg;
    pos = neg = 0;
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        if (v[i] > 0)
            pos++;
        else if (v[i] < 0)
            neg++;
    }
    sort(v, v+n);
    if (neg%2 == 1) {
        if (pos) {
            printf("%d ", neg);
            for (int i = 0; i < neg; i++)
                printf("%d ", v[i]);
            printf("\n");
            printf("%d ", pos);
            for (int i = neg+1; i < n; i++)
                printf("%d ", v[i]);
            printf("\n");
            printf("1 0\n");
        }
        else {
            printf("%d ", neg-2);
            for (int i = 2; i < neg; i++)
                printf("%d ", v[i]);
            printf("\n");
            printf("2 ");
            for (int i = 0; i < 2; i++)
                printf("%d ", v[i]);
            printf("\n");
            printf("1 0\n");
        }
    }
    else {
        if (pos) {
            printf("%d ", neg-1);
            for (int i = 1; i < neg; i++)
                printf("%d ", v[i]);
            printf("\n");
            printf("%d ", pos);
            for (int i = neg+1; i < n; i++)
                printf("%d ", v[i]);
            printf("\n");
            printf("2 ");
            printf("%d 0\n", v[0]);
        }
        else {
            printf("%d ", neg-3);
            for (int i = 3; i < neg; i++)
                printf("%d ", v[i]);
            printf("\n");
            printf("2 ");
            printf("%d %d\n", v[0], v[1]);
            printf("2 %d 0\n", v[2]);
        }
    }
    return 0;
}


