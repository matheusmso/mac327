#include <bits/stdc++.h>
using namespace std;

int t, s, x;

int main() {
    scanf(" %d %d %d", &t, &s, &x);
    if (t > x) printf("NO\n");
    else if (t == x) printf("YES\n");
    else { 
        if ((x-t)%s == 0 || ((x-t)%s == 1 && (x-t)/s >= 1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

