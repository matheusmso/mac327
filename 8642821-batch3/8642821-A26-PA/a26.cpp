#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int a[N], b[N], n, m;

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf(" %d", a+i);
    for (int i = 0; i < m; i++)
        scanf(" %d", b+i);
    sort(a, a+n);
    for (int i = 0; i < m; i++)
        printf("%d ", upper_bound(a, a+n, b[i])-a);
    return 0;
}

