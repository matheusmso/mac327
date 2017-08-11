#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int N = (int) 5e2+7;
lint d[N][N], ans[N], lol[N][N];
int n, v[N];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf(" %lld", &d[i][j]);
            lol[i][j] = d[i][j];
        }
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[n-i-1]);
        v[n-i-1]--;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[v[i]][v[j]] = min(d[v[i]][v[j]], d[v[i]][v[k]]+d[v[k]][v[j]]);
        for (int i = 0; i <= k; i++) 
            for (int j = 0; j <= k; j++) 
                ans[n-k-1] += d[v[i]][v[j]];
    }
    for (int i = 0; i < n; i++)
            printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}

