#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf(" %d", &n);
    if (n < 10) printf("%d\n", n);
    else if (n < 100) printf("%d\n", 2*(n+1)-11);
    else if (n < 1000) printf("%d\n", 3*(n+1)-111);
    else if (n < 10000) printf("%d\n", 4*(n+1)-1111);
    else if (n < 100000) printf("%d\n", 5*(n+1)-11111);
    else if (n < 1000000) printf("%d\n", 6*(n+1)-111111);
    else if (n < 10000000) printf("%d\n", 7*(n+1)-1111111);
    else if (n < 100000000) printf("%d\n", 8*(n+1)-11111111);
    else if (n < 1000000000) printf("%lld\n", 9ll*(n+1)-111111111);
    else printf("%lld\n", 10ll*(n+1)-1111111111);
    return 0;
}

