#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5+7;
vector<int> adj[N];
int c[N], cur[N], streak[N], n, m, total = 0;

void dfs(int u, int p) {
    if (c[u]) {
        cur[u] = cur[p]+1;
        streak[u] = max(streak[p], cur[u]);
    }
    else {
        cur[u] = 0;
        streak[u] = streak[p];
    }
    for (int x : adj[u]) 
        if (x != p) 
            dfs(x, u);
    if (adj[u].size() == 1 && adj[u][0] == p && streak[u] <= m)
        total++;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf(" %d", &c[i]);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    printf("%d\n", total);
    return 0;
}

