#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int N = 1e5+7;
lint dp[N], freq[N], m = -1;
int n;

lint solve(int i) {
    if (i > m) return 0;
    if (dp[i] != -1) return dp[i];
    lint ans = -1;
    if (freq[i] > 0)
        ans = max(ans, i*freq[i] + solve(i+2));
    ans = max(ans , solve(i+1));
    return dp[i] = ans;
}

int main() {
    scanf(" %d", &n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        lint aux;
        scanf(" %lld", &aux);
        freq[aux]++;
        m = max(m, aux);
    }
    printf("%lld\n", solve(0));
    return 0;
}

