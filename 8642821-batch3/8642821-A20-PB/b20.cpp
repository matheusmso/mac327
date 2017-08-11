#include <bits/stdc++.h>
using namespace std;
const int N = (int) 1e5+7;;
int v[2*N], n, k;

void init() {
    for (int i = n-1; i > 0; i--)
        v[i] = v[2*i]*v[2*i+1];
}

void update(int p, int value) {
    p += n;
    v[p] = value;
    p /= 2;
    while (p) {
        v[p] = v[2*p]*v[2*p+1];
        p /= 2;
    }
}

char query(int l, int r) {
    int ans = 1;
    l += n;
    r += n;
    while (l < r) {
        if (l%2 == 1) ans *= v[l++];
        if (r%2 == 1) ans *= v[--r];
        r /= 2;
        l /= 2;
    }
    if (!ans) return '0';
    else return ans > 0 ? '+' : '-';
}

int main() {
    while(scanf(" %d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf(" %d", &v[n+i]);
            if (v[n+i] > 0) v[n+i] = 1;
            else v[n+i] = -1*(v[n+i] < 0);
        }
        init();
        for (int i = 0; i < k; i++) {
            char c;
            int l, r;
            scanf(" %c %d %d", &c, &l, &r);
            if (c == 'C') {
                if (r > 0) r = 1;
                else r = -1 * (r < 0);
                update(--l, r);
            }
            else
                printf("%c", query(--l, r));
        }
        printf("\n");
    }
    return 0;
}

