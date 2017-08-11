#include <bits/stdc++.h>
using namespace std;

int n, X, Y;
map<pair<int, int>, int> m;

int main() {
    scanf(" %d", &n);
    scanf(" %d %d", &X, &Y);
    while (n--) {
        int x, y;
        scanf(" %d %d", &x, &y);
        x -= X;
        y -= Y;
        m[make_pair(x/__gcd(x, y), y/__gcd(x, y))]++;
    }
    printf("%d\n", m.size());
    return 0;
}


