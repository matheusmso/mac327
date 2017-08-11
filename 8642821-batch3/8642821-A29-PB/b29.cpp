#include <bits/stdc++.h>
using namespace std;

int primes[] = {4,9,25,49,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main() {
    char s[5];
    for (int i = 0; i < 4; i++) {
        printf("%d\n", primes[i]);
        fflush(stdout);
        scanf(" %s", s);
        if (s[0] == 'y') {
            printf("composite\n");
            return 0;
        }
    }
    int div = 0;
    for (int i = 4; i < 19; i++) {
        printf("%d\n", primes[i]);
        fflush(stdout);
        scanf(" %s", s);
        if (s[0] == 'y') {
            if (div) {
                printf("composite\n");
                return 0;
            }
            div++;
        }
    }
    printf("prime\n");
    return 0;
}
