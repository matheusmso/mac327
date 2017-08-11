#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d;

int main() {
    long long ans = 0;
    scanf(" %d %d %d %d %d", &n, &a, &b, &c, &d);
    for (int i = 1; i <= n; i++) {
        int j = i+b-c;
        int k = i+a-d;
        int l = a+j-d;
        if (j >= 1 && j <= n && k >= 1 && k <= n && l >= 1 && l <= n)
            ans++;
    }
    printf("%lld\n", ans*n);
    return 0;
}

