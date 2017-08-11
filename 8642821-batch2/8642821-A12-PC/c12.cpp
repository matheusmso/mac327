#include <bits/stdc++.h>
using namespace std;

int gr[1000], o[4000], d[4000], we[4000], w, h, g, e, dis[1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool isIn(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h;
}

int main() {
    while (scanf(" %d %d", &w, &h) && w) {
        //printf("w, h, %d %d\n", w, h);
        scanf(" %d", &g);
        memset(gr, 0, sizeof(gr));
        for (int i = 0; i < g; i++) {
            int x, y;
            scanf(" %d %d", &x, &y);
            gr[(y*w)+x] = 1;
            //printf("stone %d\n", (y*w)+x);
        }
        scanf(" %d", &e);
        int m = 0;
        for (int i = 0; i < e; i++) {
            int x1, y1, x2, y2, t;
            scanf(" %d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
            gr[(y1*w)+x1] = 2;
            //printf("hole %d to %d\n", (y1*w)+x1, (y2*w)+x2);
            if ((y1*w)+x1 == w*h-1) continue;
            o[m] = (y1*w)+x1;
            d[m] = (y2*w)+x2;
            we[m] = t;
            m++;
        }
        for (int i = 0; i < w*h-1; i++) {
            if (gr[i]) continue;
            int x1 = i%w;
            int y1 = i/w;
            for (int k = 0; k < 4; k++) {
                int x2 = x1+dx[k];
                int y2 = y1+dy[k];
                if (isIn(x2, y2) && gr[(w*y2)+x2] != 1) {
                    o[m] = i;
                    d[m] = (y2*w)+x2;
                    we[m] = 1;
                    m++;
                }
            }
        }
        //for (int i = 0; i < m; i++)
            //printf("%d to %d %d\n", o[i], d[i], we[i]);
        int n = w*h;
        for (int i = 0; i < 1000; i++)
            dis[i] = 999999999;
        dis[0] = 0;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < m; j++) {
                if (o[j] == (w*h)-1 || dis[o[j]] == 999999999) continue;
                dis[d[j]] = min(dis[d[j]], dis[o[j]]+we[j]);
            }
        bool flag= false;
        for (int i = 0; i < m; i++) {
            if (o[i] == (w*h)-1 || dis[o[i]] == 999999999) continue;
            if (dis[d[i]] > dis[o[i]]+we[i]) {
                flag = true;
                break;
            }
        }
        if (flag)
            printf("Never\n");
        else {
            if (dis[(w*h)-1] == 999999999)
                printf("Impossible\n");
            else
                printf("%d\n", dis[(w*h)-1]);
        }
    }
    return 0;
}


    

