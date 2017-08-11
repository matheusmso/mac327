#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int t[N][N], n, m, seen[N][N], total;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool isIn(int i, int j) {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= m) return false;
    return true;
}

int bfs(int i, int j) {
    int ans = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    seen[i][j] = 1;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        ans++;
        for (int k = 0; k < 4; k++) {
            int x = p.first+dy[k];
            int y = p.second+dx[k];
            if (isIn(x, y) && seen[x][y] == 0 && t[x][y] == 1) {
                q.push(make_pair(x, y));
                seen[x][y] = 1;
            }
        }
    }
    return ans;
}

int main() {
    while (scanf(" %d %d", &n, &m) != EOF && n) {
        map<int, int> ma;
        memset(seen, 0, sizeof(seen));
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf(" %d", &t[i][j]);
        total = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (seen[i][j] == 0 && t[i][j] == 1) {
                    ma[bfs(i, j)]++;
                    total++;
                }
        printf("%d\n", total);
        for (pair<int, int> p : ma)
            printf("%d %d\n", p.first, p.second);
    }
    return 0;
}

