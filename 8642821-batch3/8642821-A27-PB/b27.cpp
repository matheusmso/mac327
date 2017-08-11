#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
typedef long long lint;
const lint inf = 2e9+7;

lint n, m, a[N], b[N];

bool f(lint x) {
    int count = 0;
    for (int i = 0, j = 0; i < n && j < m; ) {
        if (abs(a[i]-b[j]) <= x) {
            count++;
            i++;
        }
        else j++;
    }
    return count == n;
}

int main() {
    scanf(" %lld %lld", &n, &m);
    for (int i = 0; i < n; i++)
        scanf(" %lld", a+i);
    for (int i = 0; i < m; i++)
        scanf(" %lld", b+i);
    lint l = 0;
    lint r = inf;
    while (l < r) {
        lint mid = (l+r)/2;
        if (f(mid))
            r = mid;
        else
            l = mid+1;
    }
    printf("%lld\n", l);
    return 0;
}

