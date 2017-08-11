#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000007;
typedef long long lint;
lint p[maxn], d[maxn];

void sieve() {
    for (lint i = 2; i <= maxn; i++) {
        if(!d[i]) {
            d[i] = i;
            for (lint j = i*i; j <= maxn; j += i)
                d[j] = i;
        }
    }
}

void createp() {
    p[1] = 0;
    lint c;
    for (lint i = 2; i <= maxn; i++) {
        if (d[i] == i)
            p[i] = -1;
        else {
            lint k = i;
            c = 0;
            while (k > 1) {
                k /= d[k];
                c++;
            }
            p[i] = c;
        }
    }
}

int main() {
    int t = 1;
    sieve();
    createp();
    lint l, u;
    while (scanf(" %lld %lld", &l, &u) && l != -1) {
        lint currsum, size, ans;
        ans = -1000000;
        currsum = 0;
        for (lint i = l; i < u+1; i++) {
            currsum = max(0ll, currsum);
            currsum += p[i]-1;
            ans = max(currsum, ans);
        }
        printf("%d. %lld\n", t++, ans);
    }
    return 0;
}

