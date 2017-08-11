#include <bits/stdc++.h>
using namespace std;

int p[10007];
map<int, int> m;

void sieve() {
    for (int i = 2; i*i <= 100000000; i++) {
        if (!p[i]) {
            p[i] = i;
            for (int j = i*i; j <= 10000; j += i)
                p[j] = i;
        }
    }
}

int main() {
    sieve();
    int x;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &x);
        while (x > 1) {
            m[p[x]]++;
            x /= p[x];
        }
    }
    int ans = 1;
    for (pair<int, int> p : m)
        ans *= (p.second+1);
    printf("%d\n", ans%10);
    return 0;
}
