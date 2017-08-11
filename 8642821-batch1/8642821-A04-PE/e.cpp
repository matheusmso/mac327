#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const lint mod = (lint)1e9+7;

lint sum(lint s, lint e) {
    return ((((s+e)%mod)*((e-s+1)%mod))%mod*((mod+1)/2))%mod;
}
int main() {
    lint n, m, ans, lim;
    scanf(" %lld %lld", &n, &m);
    ans = (n%mod)*(m%mod)%mod;
    lim = m = min(m, n);
    for (lint q = 1; q*q <= n; q++) {
        lint l, r;
        l = n/(q+1);
        r = min (m, n/q);
        if (l < r) {
            lint aux = sum(l+1, r);
            aux = (aux*q)%mod;
            ans = (ans+mod-aux)%mod;
            lim = l;
        }
    }
    for (lint i = 1; i <= lim; i++)
        ans = (ans+mod-(i*(n/i))%mod)%mod;
    printf("%lld\n", ans);
    return 0;
}
