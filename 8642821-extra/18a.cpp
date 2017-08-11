#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+7;
const int INF = 0x3f3f3f3f;
int n, m, dp[N][107], v[107];

int solve(int k, int i) {
    if (k < 0) return INF;
    if (k == 0) return 0;
    if (i >= n && k > 0) return INF;
    if (dp[k][i] != -1) return dp[k][i];
    int ans = min(solve(k, i+1), 1+solve(k-v[i], i));
    return dp[k][i] = ans;
}

int main() {
    while (scanf(" %d", &m) && m) {
        scanf(" %d", &n);
        for (int i = 0; i < n; i++)
            scanf(" %d", &v[i]);
        memset(dp, -1, sizeof(dp));
        int ans = solve(m, 0);
        if (ans == INF)
            printf("Impossivel\n");
        else printf("%d\n", ans);
    }
    return 0;
}
