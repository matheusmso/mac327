#include <bits/stdc++.h>
using namespace std;
const int N = (int) 1e5+7;
int v[N], st[N][20], n, q;

void build() {
    for (int i = n-1; i >= 0; i--) {
        st[i][0] = v[i];
        for (int j = 1; j < 20; j++) {
            if (i + (1<<j)-1 < n)
                st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            else
                break;
        }
    }
}

int query(int l, int r) {
    int size = r-l+1;
    int k = 31-__builtin_clz(size);
    return min(st[l][k], st[r-(1<<k)+1][k]);
}

int main() {
    int t;
    scanf(" %d", &t);
    for (int k = 0; k < t; k++) {
        printf("Scenario #%d:\n\n", k+1);
        scanf(" %d %d", &n, &q);
        for (int i = 0; i < n; i++)
            scanf(" %d", &v[i]);
        build();
        for (int i = 0; i < q; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            printf("%d\n\n", query(--a, --b));
        }
    }
    return 0;
}


