#include <bits/stdc++.h>
using namespace std;

int t;

long long fexp(long long b, long long e, long long m) {
    b %= m;
    if (e == 0) return 1;
    return (((e&1) ? b : 1)*fexp(b*b, e/2, m))%m;
}

int main() {
    scanf(" %lld", &t);
    for (int i = 1; i <= t; i++) {
        long long b, e, m;
        scanf(" %lld %lld %lld", &b, &e, &m);
        printf("%d. %lld\n", i, fexp(b, e, m));
    }
    return 0;
}


