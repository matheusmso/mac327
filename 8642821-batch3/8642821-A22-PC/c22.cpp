#include <bits/stdc++.h>
using namespace std;

const int N = (int)7e3;
int t, n, dp[N][N];
char s[N];

int solve(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ans;
    if (s[l] == s[r]) ans = solve(l+1, r-1);
    else ans = 1+min(solve(l+1, r), solve(l, r-1));
    return dp[l][r] = ans;
}

int main() {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %s", s);
        n = strlen(s);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, n-1));
    }
    return 0;
}

