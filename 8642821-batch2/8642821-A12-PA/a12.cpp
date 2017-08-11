#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e2+7;
int n, color[N];
vector<int> adj[N];

void dfs(int u, int c) {
    color[u] = c;
    for (int x : adj[u]) {
        if (color[x] == -1)
            dfs(x, 1-c);
        else if (color[x] == c) {
            printf("-1\n");
            exit(0);
        }
    }
}

int main() {
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        while (scanf(" %d", &x) && x != 0) {
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    for (int i = 0; i <= n; i++)
        color[i] = -1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d", color[i]);
    printf("\n");
    return 0;
}

