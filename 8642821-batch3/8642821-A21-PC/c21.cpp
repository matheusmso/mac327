#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e3+7;
const int inf = 0x3f3f3f3f;
int n, v[N], dp[N][N];

int solve(int i, int r) {
    if (r < 0) return inf;
    if (i == n) return r == 0 ? 0 : inf;
    if (dp[i][r] != -1) return dp[i][r];
    int ans = min(solve(i+1, r+v[i]), 1+solve(i+1, r-v[i]));
    return dp[i][r] = ans;
}

int main() {
    char s[2007];
    int c = 1;
    while (scanf(" %s", s) && s[0] != '-') {
        n = strlen(s);
        for (int i = 0; i < n; i++)
            v[i] = (s[i] == '{') ? 1 : -1;
        memset(dp, -1, sizeof(dp));
        printf("%d. %d\n", c++, solve(0, 0));
    }
    return 0;
}
