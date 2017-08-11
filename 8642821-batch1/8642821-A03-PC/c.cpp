#include <bits/stdc++.h>
using namespace std;

long long d[100011], t;
long long primes[100011];

void genprime() {
    long long i, j, count;
    primes[0] = 1;
    count = 1;
    for (j = 2; j < 100007; j++) {
        if (!d[j]) {
            primes[count++] = j;
            for (i = j*j; i < 100007; i += j)
                d[i] = 1;
        }
    }
}

int main() {
    genprime();
    scanf(" %lld", &t);
    while (t--) {
        long long n, ans, i, j, k;
        ans = 0;
        scanf(" %lld %lld", &n, &k);
        if (k != 0)
            for (i = 1, j = k; primes[j] <= n && primes[j] != 0; i++, j++)
                ans += (n-primes[j]+1)*(primes[i]-primes[i-1]);
        else 
            ans += (n*(n-1))/2;
        printf("%lld\n", ans);
    }
    return 0;
}

