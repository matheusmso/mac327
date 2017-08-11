#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, d;

int main() {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d %d %d", &a, &b, &c, &d);
        int x = abs(c-a);
        int y = abs(d-b);
        printf("%d\n", __gcd(x, y)+1);
    }
    return 0;
}

