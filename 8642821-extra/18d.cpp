#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int dp[N], n, m;

int main() {
    scanf(" %d", &n);
    while (n--) {
        int t;
        scanf(" %d", &t);
        dp[t]++;
        for (int i = 2*t; i < N-6; i += t)
            dp[i] = max(dp[t], dp[i]);
    }
    for (int i = 0; i < N-6; i++)
        m = max(dp[i], m);
    printf("%d\n", m);
    return 0;
}

