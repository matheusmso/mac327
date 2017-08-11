#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = (int)4e3+7;
int n, a, b, c, dp[N];

int solve(int s) {
    if (s < 0) return -inf;
    if (s == 0) return 0;
    if (dp[s] != -1) return dp[s];
    int ans = -inf;
    ans = max(ans, 1+solve(s-a));
    ans = max(ans, 1+solve(s-b));
    ans = max(ans, 1+solve(s-c));
    return dp[s] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf(" %d %d %d %d", &n, &a, &b, &c);
    printf("%d\n", solve(n));
    return 0;
}
