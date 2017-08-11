#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, m, t[15][15], seen[15][15];
struct node {
    int x, y, d;
    node(int x, int y, int d):x(x), y(y), d(d) {}
};

bool isIn(int i, int j) {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= m) return false;
    return true;
}

int main() {
    int sx, sy;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &t[i][j]);
            if (t[i][j] == 3) {
                sx = i;
                sy = j;
            }
        }
    }
    queue<node> q;
    q.push(node(sx, sy, 0));
    seen[sx][sy] = 1;
    while(!q.empty()) {
        node w = q.front();
        q.pop();
        if (t[w.x][w.y] == 0) {
            printf("%d\n", w.d);
            return 0;
        }
        for (int k = 0; k < 4; k++) {
            if (isIn(w.x+dx[k], w.y+dy[k]) && seen[w.x+dx[k]][w.y+dy[k]] == 0 && t[w.x+dx[k]][w.y+dy[k]] != 2) {
                q.push(node(w.x+dx[k], w.y+dy[k], w.d+1));
                seen[w.x+dx[k]][w.y+dy[k]] = 1;
            }
        }
    }
    return 0;
}