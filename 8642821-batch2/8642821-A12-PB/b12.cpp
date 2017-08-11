#include <bits/stdc++.h>
using namespace std;
const int N = (int) 2e3+7;
int c, n, m, d[N], x[N], y[N], w[N];
const int inf = 999999999;

int main() {
    scanf(" %d", &c);
    while (c--) {
        scanf(" %d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf(" %d %d %d", &x[i], &y[i], &w[i]);
        memset(d, 0, sizeof(d));
        for (int k = 0; k < n-1; k++) 
            for (int i = 0; i < m; i++)
                if (d[x[i]] != inf)
                    d[y[i]] = min(d[y[i]], d[x[i]]+w[i]);
        bool flag = false;
        for (int i = 0; i < m; i++) {
            if (d[x[i]] != inf && d[x[i]]+w[i] < d[y[i]]) {
                flag = true;
                break;
            }
        }
        printf("%s\n", flag ? "possible" : "not possible");
    }
    return 0;
}

