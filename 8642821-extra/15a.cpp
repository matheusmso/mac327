#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 107;
int test = 1, n, s, t, c, flow, maxflow;
int res[N][N], p[N], seen[N];
vector<int> g[N];

void augment(int v, int medge) {
    if (v == s) {
        flow = medge;
        return;
    }
    else if (p[v] != -1) {
        augment(p[v], min(medge, res[p[v]][v]));
        res[p[v]][v] -= flow;
        res[v][p[v]] += flow;
    }
}

int main() {
    while (scanf(" %d", &n) && n) {
        scanf(" %d %d %d", &s, &t, &c);
        memset(p, 0, sizeof(p));
        memset(res, 0, sizeof(res));
        for (int i = 0; i < N; i++)
            g[i].clear();
        for (int i = 0; i < c; i++) {
            int a, b, cap;
            scanf(" %d %d %d", &a, &b, &cap);
            res[a][b] += cap;
            res[b][a] += cap;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        maxflow = 0;
        while (1) {
            flow = 0;
            memset(seen, 0, sizeof(seen));
            memset(p, -1, sizeof(p));
            queue<int> q;
            q.push(s);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                if (u != t) {
                    for (int i : g[u]) {
                        if (res[u][i] > 0 && !seen[i]) {
                            seen[i] = 1;
                            q.push(i);
                            p[i] = u;
                        }
                    }
                }
                else break;
            }
            augment(t, INF);
            if (flow == 0) break;
            maxflow += flow;
        }
        printf("Network %d\n", test++);
        printf("The bandwidth is %d.\n\n", maxflow);
    }
    return 0;
}

