#include <bits/stdc++.h>
using namespace std;

int s, p;
int ans[40];

void go(int k, int pr, int acc) {
    if (k > p) return;
    //printf("%d %d %d\n", k, pr, acc);
    if (k == p && acc == s) {
        for (int i = 0; i < p; i++) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        return;
    }
    if (pr > 1) pr++;
    for (int i = pr; i <= s-acc; i++) {
        int c = 0;
        for (int l = 0; l < k; l++) {
            if (__gcd(ans[l], i) != 1) {
                c++;
                break;
            }
        }
        if (!c) {
            ans[k] = i;
            go(k+1, i, acc+i);
            ans[k] = 0;
        }
    }
}

int main() {
    int t;
    scanf(" %d", &t);
    for (int ta = 1; ta <= t; ta++) {
        scanf(" %d %d", &s, &p);
        printf("Case %d:\n", ta);
        go(0, 1, 0);
    }
    return 0;
}
