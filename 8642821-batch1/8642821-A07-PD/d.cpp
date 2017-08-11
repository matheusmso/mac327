#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int t[N][N], n, usedcol[N][N], usedline[N][N], usedsq[N][N][N];
bool cont = true;
void go(int x, int y) {
    if (cont) {
    if (y == n*n) {
        if (x < n*n-1)
            go(x+1, 0);
        else {
            for (int i = 0; i < n*n; i++) {
                for (int j = 0; j < n*n; j++) {
                    if (j) printf(" ");
                    printf("%d", t[i][j]);
                }
                printf("\n");
            }
            cont = false;
            return;
        }
    }
    if (t[x][y] == 0) {
        for (int i = 1; i <= n*n; i++) {
            if (usedline[x][i] == 0 && usedcol[y][i] == 0 
                    && usedsq[x/n][y/n][i] == 0) {
                usedline[x][i] = 1;
                usedcol[y][i] = 1;
                usedsq[x/n][y/n][i] = 1;
                t[x][y] = i;
                go(x, y+1);
                t[x][y] = 0;
                usedline[x][i] = 0;
                usedcol[y][i] = 0;
                usedsq[x/n][y/n][i] = 0;
            }
        }
    }
    else {
        go(x, y+1);
    }
    }
}



int main() {
    int count = 0;
    while (scanf(" %d", &n) != EOF) {
        cont = true;
        if (count) printf("\n");
        memset(usedline, 0, sizeof(usedline));
        memset(usedcol, 0, sizeof(usedcol));
        memset(usedsq, 0, sizeof(usedsq));
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n*n; i++) {
            for (int j = 0; j < n*n; j++) {
                scanf(" %d", &t[i][j]);
                usedline[i][t[i][j]]++;
                usedcol[j][t[i][j]]++;
                usedsq[i/n][j/n][t[i][j]]++;
            }
        }
        bool flag = true;
        for (int i = 0; i < n*n; i++)
            for (int j = 1; j <= n*n; j++)
                if (usedline[i][j] > 1 || usedcol[i][j] > 1)
                    flag = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 1; k <= n*n; k++)
                    if (usedsq[i][j][k] > 1)
                        flag = false;
        if (flag) {
            go(0, 0);
            if (cont)
                printf("NO SOLUTION\n");
        }
        else
            printf("NO SOLUTION\n");
        count++;
    }
    return 0;
}
