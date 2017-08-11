#include <stdio.h>
#include <string.h>

const int inf = 0x3f3f3f3f;
int t, h, w, v[107][107], dp[107][107];

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int i, int j) {
    if (j >= w || j < 0) return -inf;
    if (i == h-1) return v[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    int ans = v[i][j] + max(solve(i+1, j), max(solve(i+1, j-1), solve(i+1, j+1)));
    return dp[i][j] = ans;
}

int main() {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d", &h, &w);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                scanf(" %d", &v[i][j]);
        int ans = -inf;
        for (int i = 0; i < w; i++)
            ans = max(ans, solve(0, i));
        printf("%d\n", ans);
    }
    return 0;
}
