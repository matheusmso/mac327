#include <bits/stdc++.h>
using namespace std;
const int N = 107;
int n, m, seen[N];
vector<int> adj[N];
map<pair<int, int>, set<int>> ma;

void dfs(int u, int c) {
    seen[u] = 1;
    for (int x : adj[u]) {
        if (seen[x] == 0 && ma[make_pair(u, x)].count(c))
            dfs(x, c);
    }
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf(" %d %d %d", &u, &v, &c);
        adj[u].push_back(v);
        adj[v].push_back(u);
        ma[make_pair(u, v)].insert(c);
        ma[make_pair(v, u)].insert(c);
    }
    int q;
    scanf(" %d", &q);
    while (q--) {
        int u, v, ans = 0;
        scanf(" %d %d", &u, &v);
        for (int i = 1; i <= m; i++) {
            memset(seen, 0, sizeof(seen));
            dfs(u, i);
            if (seen[v])
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

