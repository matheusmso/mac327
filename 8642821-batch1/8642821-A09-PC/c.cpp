#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e4+7;
vector<int> adj[N];
int n, m, comp[N];

void dfs(int u) {
    for (int x : adj[u]) {
        if (!comp[x]) {
            comp[x] = comp[u];
            dfs(x);
        }
    }
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!comp[i]) {
            comp[i] = ++components;
            dfs(i);
        }
    }
    if (components == 1 && n-1 == m)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}


