#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e7+7;
int prime[] = {2, 3, 5, 7, 11};
int ans[N];

int main() {
    int n;
    scanf(" %d", &n);
    int r = 1;
    ans[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < r; j++) {
            if (ans[j]*prime[i] <= 2ll*n*n) {
                ans[r] = ans[j]*prime[i];
                r++;
            }
        }
        if (r >= n)
            break;
    }
    //printf("%lld\n", k);
    //for (int i = 0; i < k; i++)
        //printf("%lld ", ans[i]);
    //printf("\n");
    for (int i = r-n; i < r; i++) 
        printf("%d ", ans[i]);
    printf("\n");
}

