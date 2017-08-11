#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    int ans = 0;
    int cable = 1;
    scanf(" %d %d", &n, &k);
    n--;
    while (cable <= k && n > 0) {
        n -= cable;
        cable *= 2;
        ans++;
    }
    if (n > 0) 
        ans += n/k + (n%k != 0);
    printf("%d\n", ans);
    return 0;
}

