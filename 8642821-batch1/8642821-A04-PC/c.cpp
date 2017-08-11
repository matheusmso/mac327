#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
lint mod = 1000000007;

lint fexp(lint b, lint p) {
    b %= mod;
    if (p == 0) return 1;
    return (((p&1) ? b : 1)*fexp(b*b, p/2))%mod;
}

int main() {
    lint a, b, n, x;
    scanf(" %lld %lld %lld %lld", &a, &b, &n, &x);
    if (a == 1) {
        printf("%lld\n", ((b*(n%mod))+x)%mod);
        return 0;
    }
    lint f = fexp(a, n);
    lint inva = fexp(a-1, mod-2);
    lint t = (((b*(f-1))%mod)*inva)%mod;
    printf("%lld\n", (t+(f*x)%mod)%mod);
    return 0;
}

