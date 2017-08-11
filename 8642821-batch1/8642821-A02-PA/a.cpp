#include <bits/stdc++.h>
using namespace std;

int v[1007];
int n, l;

int main() {
    scanf(" %d %d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i]);
    sort(v, v+n);
    int d = 2*v[0];
    for (int i = 1; i < n; i++)
        d = max(d, v[i]-v[i-1]);
    d = max(d, 2*(l-v[n-1]));
    printf("%.9f\n", (double)d/2);
    return 0;
}

