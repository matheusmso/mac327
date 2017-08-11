#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

lint d[100007];

lint fexp(lint b, lint e, lint m) {
    b %= m;
    if (e == 0) return 1;
    return ((e&1) ? b : 1)*fexp(b*b, e/2, m)%m;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        lint n, a, b;
        scanf(" %lld", &n);
        for (lint i = 2; i*i <= n; i++) {
            if (n%i == 0) {
                a = n/i;
                b = i;
            }
        }
        lint x = a*fexp(a, b-2, b)%(a*b);
        lint y = b*fexp(b, a-2, a)%(a*b);
        lint ans[4];
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = min(x, y);
        ans[3] = max(x, y);
        for (int i = 0; i < 4; i++)
            printf("%lld ", ans[i]);
        printf("\n");
    }
    return 0;
}
