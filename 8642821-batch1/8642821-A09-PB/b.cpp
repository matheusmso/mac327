#include <bits/stdc++.h>
using namespace std;

int l, r, c, seen[35][35][35];
char d[35][35][35];

struct node {
    int x, y, l, dist;
    node(int x, int y, int l, int dist):x(x), y(y), l(l), dist(dist) {}
};

bool isIn(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return false;
    if (x >= c || y >= r || z >= l) return false;
    return true;
}

int main() {
    while (scanf(" %d %d %d", &l, &r, &c) != EOF) {
        if (l == 0) break;
        int sx, sy, sl;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    scanf(" %c", &d[j][k][i]);
                    if (d[j][k][i] == 'S') {
                        sx = k;
                        sy = j;
                        sl = i;
                    }
                }
            }
        }
        memset(seen, 0, sizeof(seen));
        bool flag = false;
        queue<node> q;
        q.push(node(sx, sy, sl, 0));
        while (!q.empty()) {
            //printf("%d\n", q.size());
            node t = q.front();
            q.pop();
            if (seen[t.x][t.y][t.l]) continue;
            seen[t.x][t.y][t.l] = 1;
            if (d[t.y][t.x][t.l] == 'E') {
                printf("Escaped in %d minute(s).\n", t.dist);
                flag = true;
                break;
            }
            if (isIn(t.x, t.y+1, t.l) && (d[t.y+1][t.x][t.l] == '.' || d[t.y+1][t.x][t.l] == 'E'))
                q.push(node(t.x, t.y+1, t.l, t.dist+1));
            if (isIn(t.x, t.y-1, t.l) && (d[t.y-1][t.x][t.l] == '.' || d[t.y-1][t.x][t.l] == 'E'))
                q.push(node(t.x, t.y-1, t.l, t.dist+1));
            if (isIn(t.x+1, t.y, t.l) && (d[t.y][t.x+1][t.l] == '.' || d[t.y][t.x+1][t.l] == 'E'))
                q.push(node(t.x+1, t.y, t.l, t.dist+1));
            if (isIn(t.x-1, t.y, t.l) && (d[t.y][t.x-1][t.l] == '.' || d[t.y][t.x-1][t.l] == 'E'))
                q.push(node(t.x-1, t.y, t.l, t.dist+1));
            if (isIn(t.x, t.y, t.l+1) && (d[t.y][t.x][t.l+1] == '.' || d[t.y][t.x][t.l+1] == 'E'))
                q.push(node(t.x, t.y, t.l+1, t.dist+1));
            if (isIn(t.x, t.y, t.l-1) && (d[t.y][t.x][t.l-1] == '.' || d[t.y][t.x][t.l-1] == 'E'))
                q.push(node(t.x, t.y, t.l-1, t.dist+1));
        }
        if (!flag)
            printf("Trapped!\n");
    }
    return 0;
}

