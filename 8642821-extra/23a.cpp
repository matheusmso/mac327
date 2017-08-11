#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    scanf(" %d", &n);
    m = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        m = max(m, a*a+b*b);
    }
    printf("0 0 %.9lf\n", sqrt(m));
    return 0;
}

