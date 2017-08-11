#include <bits/stdc++.h>
using namespace std;

const int N = 2e2+7;
int n, dp[N][N][N], v[N];

int solve(int p, int b, int w) {
    if (p > n) return 0;
    if (dp[p][b][w] != -1) return dp[p][b][w];
    int ans;
    if ((b == 0 || v[p]>v[b]) && (w == 0 || v[p]<v[w]))
        ans = min(solve(p+1,b,p),min(solve(p+1,p,w),1+solve(p+1,b,w)));
    else if (b == 0 || v[p]>v[b])
        ans = min(solve(p+1,p,w), 1+solve(p+1,b,w));
    else if (w == 0 || v[p]<v[w])
        ans = min(solve(p+1,b,p), 1+solve(p+1,b,w));
    else ans = 1+solve(p+1,b,w);
    return dp[p][b][w] = ans;
}

int main() {
    while (scanf(" %d", &n) && n != -1) {
        for (int i = 0; i < n; i++)
            scanf(" %d", v+i+1);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(1, 0, 0));
    }
    return 0;
}

