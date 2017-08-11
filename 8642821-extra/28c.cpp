#include <bits/stdc++.h>
using namespace std;

const int N = 3e2+7;
int n, p[N], used[N], l[N], cur, comp;
char m[N][N];

void dfs(int k) {
    if (used[p[k]] == 0)
        cur = min(cur, p[k]);
    l[k] = comp;
    for (int i = 0; i < n; i++)
        if (m[k][i] == '1' && l[i] != comp)
            dfs(i);
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", p+i);
    for (int i = 0; i < n; i++)
        scanf(" %s", m[i]);
    for (int i = 0; i < n; i++) {
        comp++;
        cur = n;
        dfs(i);
        used[cur] = 1;
        printf("%d ", cur);
    }
    printf("\n");
    return 0;
}

