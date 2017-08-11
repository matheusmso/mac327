#include <bits/stdc++.h>
using namespace std;

const int N = 3e4+7;
int a[N];

int main() {
    int n, t;
    scanf(" %d %d", &n, &t);
    for (int i = 0; i < n-1; i++)
        scanf(" %d", a+i);
    for (int i = 0; i < n; ) {
        if (i+1 == t) {
            printf("YES\n");
            return 0;
        }
        else if (i+1 > t) {
            printf("NO\n");
            return 0;
        }
        else
            i += a[i];
    }
    return 0;
}



