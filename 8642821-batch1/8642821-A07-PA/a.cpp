#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lint;

lint primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
lint ans[100];
lint x;
lint best;
lint bestdiv;

void go(lint n, lint p) {
    //printf("%lld %lld\n", n, p);
    if (p == 0) {
        ans[0]++;
        if (n && primes[0] <= x/n) {
            lint div = 1;
            for (lint i = 0; i < 15; i++)
                div = div*(ans[i]+1);
            if (div > bestdiv) {
                bestdiv = div;
                best = n*primes[0];
            }
            else if (div == bestdiv)
                best = min(best, n*primes[0]);
            go(n*primes[0], 0);
            go(n*primes[0], 1);
        }
        ans[0]--;
    }
    else {
        ans[p]++;
        if (n && primes[p] <= x/n && ans[p] <= ans[p-1]) {
            lint div = 1;
            for (lint i = 0; i < 15; i++)
                div = div*(ans[i]+1);
            if (div > bestdiv) {
                bestdiv = div;
                best = n*primes[p];
            }
            else if (div == bestdiv)
                best = min(best, n*primes[p]);
            go(n*primes[p], p);
            go(n*primes[p], p+1);
        }
        ans[p]--;
    }
}

int main() {
    lint t;
    scanf(" %llu", &t);
    while (t--) {
        best = 1;
        bestdiv = 1;
        scanf(" %llu", &x);
        go(1, 0);
        printf("%llu %llu\n", best, bestdiv);
    }
    return 0;
}

