#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0, n;
    int a, b, c, d, x, y;
    scanf(" %d", &n);
    scanf(" %d %d", &a, &b);
    scanf(" %d %d", &c, &d);
    for (int i = 0; i < n-1; i++) {
        scanf(" %d %d", &x, &y);
        if (c > a && y > d) ans ++;
        else if (a > c && d > y) ans++;
        else if (d > b && x < c) ans++;
        else if (d < b && x > c) ans++;
        a = c;
        b = d;
        c = x;
        d = y;
    }
    printf("%d\n", ans);
    return 0;
}

