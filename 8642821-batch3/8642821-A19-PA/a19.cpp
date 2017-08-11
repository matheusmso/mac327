#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5+7;
int n, v[2*N], t = 1;

void init() {
    for (int i = n-1; i > 0; i--)
        v[i] = v[2*i]+v[2*i+1];
}

void update(int p, int value) {
    p += n;
    v[p] = value;
    p /= 2;
    while (p) {
        v[p] = v[2*p]+v[2*p+1];
        p /= 2;
    }
}

int query(int l, int r) {
    int ans = 0;
    l += n;
    r += n;
    while (l < r) {
        if (l&1) ans += v[l++];
        if (r&1) ans += v[--r];
        l /= 2;
        r /= 2;
    }
    return ans;
}

int main() {
    while (scanf(" %d", &n) && n != 0) {
        if (t != 1) printf("\n");
        printf("Case %d:\n", t++);
        for (int i = 0; i < n; i++)
            scanf(" %d", &v[i+n]);
        init();
        char s[5];
        while (scanf(" %s", s) && s[0] != 'E') {
            int l, r;
            scanf(" %d %d", &l, &r);
            if (s[0] == 'M')
                printf("%d\n", query(--l, r));
            else
                update(--l, r);
        }
    }
    return 0;
}
