#include <bits/stdc++.h>
using namespace std;

int t;
long long n;

int main() {
    scanf(" %d", &t);
    while (t--) {
        scanf(" %lld", &n);
        long long d = ceil(sqrt(8ll*n+1ll))/2ll;
        d--;
        long long pos = (d*d+d)/2;
        if (n-pos == 1)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}

