#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, t, a[N][N], seen[N][N][1<<11];
int sx, sy, ex, ey;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool isIn(int i, int j) {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= n) return false;
    return true;
}

struct node {
    int x, y, c;
    node(int x, int y, int c):x(x), y(y), c(c) {}
};

void bfs(int i, int j) {
    queue<node> q;
    q.push(node(i, j, 1<<a[i][j]));
    seen[i][j][1<<a[i][j]] = 1;
    while (!q.empty()) {
        node p = q.front();
        q.pop();
        if (p.x == ex && p.y == ey) continue;
        for (int k = 0; k < 4; k++) {
            int x = p.x+dx[k];
            int y = p.y+dy[k];
            int c = p.c;
            if (isIn(x, y)) {
                c |= 1<<a[x][y];
                if (seen[x][y][c] == 0) {
                    q.push(node(x, y, c));
                    seen[x][y][c] = 1;
                }
            }
        }
    }
}

int main() {
    scanf(" %d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(seen, 0, sizeof(seen));
        scanf(" %d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf(" %d", &a[i][j]);
        scanf(" %d %d %d %d", &sx, &sy, &ex, &ey);
        bfs(sx, sy);
        int ans = 11;
        for (int i = 0; i < 1<<10; i++) {
            int aux = 0;
            if (seen[ex][ey][i] == 0) continue;
            for (int j = 0; j < 10; j++) {
                if ((1<<j)&i)
                    aux++;
            }
            ans = min(aux, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}

