#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5+7;
const int inf = 0x3f3f3f3f;
int n, cubes[57], dp[57][N];

int solve(int i, int rem) {
    if (rem == 0) return 0;
    if (rem < 0) return inf;
    if (i*i*i > rem) return inf;
    if (dp[i][rem] != -1) return dp[i][rem];
    int ans = min (solve(i+1, rem), 1+solve(i, rem-(i*i*i)));
    return dp[i][rem] = ans;
}

int main() {
    int c = 1;
    memset(dp, -1, sizeof(dp));
    while (scanf(" %d", &n) != EOF) 
        printf("Case #%d: %d\n", c++,solve(1, n));
    return 0;
}

