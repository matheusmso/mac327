#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9+7;
const int N = (int)5e4+7;
int n, a[2], dp[N][2];

int solve(int i, int t) {
    if (i > n) return 0;
    if (i == n) return 1;
    if (dp[i][t] != -1) return dp[i][t];
    int aux = 0;
    for (int k = 1; k <= a[t]; k++)
        aux = (aux+solve(i+k, 1-t))%mod;
    return dp[i][t] = aux;
}

int main() {
    scanf(" %d %d %d", &n, &a[0], &a[1]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", (solve(0, 0)+solve(0, 1))%mod);
    return 0;
}
