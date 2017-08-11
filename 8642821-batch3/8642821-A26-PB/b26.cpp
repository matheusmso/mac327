#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
typedef long long lint;
map<lint, lint> m;
int n;
lint ans = 0;

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        lint x;
        scanf(" %lld", &x);
        for (int k = 0; k < 32; k++) {
            lint a = 1<<k;
            a -= x;
            ans += m[a];
        }
        m[x]++;
    }
    printf("%lld", ans);
    return 0;
}

