#include <bits/stdc++.h>
using namespace std;
const int N = 2007;
const int inf = 999999999;
int cap, n, s[N], v[N], dp[N][N];

int solve(int i, int c) {
    if (c < 0) return -inf;
    if (i >= n) return 0;
    if (dp[i][c] != -1) return dp[i][c];
    return dp[i][c] = max(solve(i+1, c-s[i])+v[i], solve(i+1, c));
}

int main() {
    scanf(" %d %d", &cap, &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &s[i]);
        scanf(" %d", &v[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, cap));
    return 0;
}

