#include <bits/stdc++.h>
using namespace std;

int n, k, s, dp[27][17][162];

int solve(int num, int ele, int sum) {
    if (sum < 0 || ele < 0) return 0;
    if (num == 0) {
        if (sum == 0 && ele == 0) return 1;
        else return 0;
    }
    if (dp[num][ele][sum] != -1) return dp[num][ele][sum];
    int ans = solve(num-1, ele, sum) + solve(num-1, ele-1, sum-num);
    return dp[num][ele][sum] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    while (scanf(" %d %d %d", &n, &k, &s) && n)
        printf("%d\n", solve(n, k, s));
    return 0;
}

