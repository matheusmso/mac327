#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
char s[5007];
int dp[5007];
int n;

lint solve(int i) {
    if (i > n) return 0;
    if (i == n) return 1;
    if (dp[i] != -1) return dp[i];
    lint ans = 0;
    if (s[i] == '0') return 0;
    if (i < n-1 && s[i] == '1') ans += solve(i+2);
    else if (s[i] == '2' && i < n-1 && s[i+1] <= '6') ans += solve(i+2);
    ans += solve(i+1);
    return dp[i] = ans;
}

int main() {
    while (scanf(" %s", s) && s[0] != '0') {
        n = strlen(s);
        s[n] = '9';
        s[n+1] = '\0';
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(0));
    }
    return 0;
}


