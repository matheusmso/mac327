#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int N = 200000;
const lint mod = 1e9+7;

lint suf[N+7], pref[N+7], pot[N+7];

lint fexp(lint b, lint e) {
    b %= mod;
    if (e == 0) return 1;
    return (((e&1) ? b : 1)*fexp(b*b, e/2))%mod;
}

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        lint x;
        scanf(" %lld", &x);
        pot[x]++;
    }
    pref[0] = 1;
    suf[N+1] = 1;
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i-1]*(pot[i]+1)%(mod-1);
    for (int i = N; i >= 1; i--)
        suf[i] = suf[i+1]*(pot[i]+1)%(mod-1);
    lint ans = 1;
    for (int i = 2; i <= N; i++) {
        if (pot[i]) {
            lint allothers = pref[i-1]*suf[i+1]%(mod-1);
            lint contribution = (pot[i]+1)*pot[i]/2%(mod-1);
            ans = ans*fexp(i, allothers*contribution%(mod-1))%mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

