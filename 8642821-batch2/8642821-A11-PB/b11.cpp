#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5+7;
int n;
vector<int> adj[N];
vector<int> ans;

void dfs(int u) {
    while(adj[u].size()) {
        int t = adj[u].back();
        adj[u].pop_back();
        dfs(t);
    }
    ans.push_back(u);
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf(" %d", &m);
        int u, v;
        scanf(" %d", &u);
        for (int j = 0; j < m; j++) {
            scanf(" %d", &v);
            adj[u].push_back(v);
            u = v;
        }
    }
    dfs(1);
    reverse(ans.begin(), ans.end());
    printf("%d ", ans.size()-1);
    for (int x : ans)
        printf("%d ", x);
    printf("\n");
    return 0;
}

