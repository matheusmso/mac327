#include <bits/stdc++.h>
using namespace std;

int c, t;
long long r[100007];

int main() {
    scanf(" %d %d", &c, &t);
    for (int i = 0; i < c; i++)
        scanf(" %lld", &r[i]);
    long long ans = 0;
    for (int i = 0; i < t; i++) {
        long long x, y;
        scanf(" %lld %lld", &x, &y);
        long long dist = ceil(sqrt(x*x+y*y));
        long long index = lower_bound(r, r+c, dist)-r;
        ans += c-index;
    }
    printf("%lld\n", ans);
    return 0;
}

