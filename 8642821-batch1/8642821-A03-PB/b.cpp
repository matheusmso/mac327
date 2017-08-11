#include <bits/stdc++.h>
using namespace std;

int t;
long long n;
long long ans[100007];

void solve() {
    for (long long k = 1; k < 100001; k++) {
        long long m = k;
        long long r = m;
        for (long long i = 2; i*i <= m; i++) {
            if (m%i == 0)
                r -= r/i;
            while (m%i == 0)
                m /= i;
        }
        if (m > 1)
            r -= r/m;
        ans[k] = ans[k-1]+k-r;
    }
}

int main() {
    solve();
    scanf(" %d", &t);
    for (int k = 1; k <= t; k++) {
        printf("Case %d: ", k);
        scanf(" %lld", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}

