#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n;
int ans[N];
int used[N];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

void go(int k) {
    if (k == n) {
        if (binary_search(primes, primes+12, ans[k-1]+1)) {
            for (int i = 0; i < n; i++) {
                if (i > 0)
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
            return;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (binary_search(primes, primes+12, i+ans[k-1]) && !used[i]) {
            ans[k] = i;
            used[i] = 1;
            go(k+1);
            ans[k] = 0;
            used[i] = 0;
        }
    }
}

int main() {
    int count = 0;
    while (scanf(" %d", &n) != EOF) {
        if (count)
            printf("\n");
        printf("Case %d:\n", count+1);
        ans[0] = 1;
        used[1] = 1;
        go(1);
        count++;
        memset(ans, 0, sizeof(ans));
        memset(used, 0, sizeof(ans));
    }
    return 0;
}



