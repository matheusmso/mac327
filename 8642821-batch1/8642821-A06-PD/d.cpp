#include <bits/stdc++.h>
using namespace std;

const int N = 2000000;
int z[N], ans[N];
char s[N];

int main() {
    int n, t;
    scanf(" %d", &t);
    for (int k = 1; k <= t; k++) {
        scanf(" %d", &n);
        scanf(" %s", s);
        printf("Test case #%d\n", k);
        int j = 0;
        for (int i = 1; i < n; i++) {
            z[i] = 0;
            int p = i+z[i];
            int c = 0;
            if (i > j+z[j]-1) {
                j = i;
                while (p+c < n && s[p+c] == s[p+c-i])
                    c++;
                z[i] = c;
            }
            else {
                if (z[i-j] <= j+z[j]-1-i) z[i] = z[i-j];
                else {
                    z[i] = j+z[j]-1-i;
                    p = i+z[i];
                    while (p+c < n && s[p+c] == s[p+c-i])
                        c++;
                    z[i] += c;
                }
            }
        }
        /*int l = 0, r = 0;
          for (int i = 1; i < n; i++) {
          z[i] = 0;
          if (i > r) {
          l = r = i;
          while (r < n && s[r-l] == s[r]) r++;
          z[i] = r-l;
          r--;
          }
          else if (z[i-l] < r-i+1) 
          z[i] = min (z[i-l], n-i);
          else {
          l = i;
          while (r < n && s[r-l] == s[r]) r++;
          z[i] = r-l; 
          r--;
          }
          }*/
        for (int i = 0; i < n; i++)
            ans[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j += (i+1)) {
                if (z[j] >= i+1)
                    ans[j+i] = max((i+j+1)/(i+1), ans[j+i]);
                else
                    break;
            }
        }
        for (int i = 0; i < n; i++)
            if (ans[i] > 1) 
                printf("%d %d\n", i+1, ans[i]);
        printf("\n");
    }
    return 0;
}

