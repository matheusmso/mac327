#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e7+7;

int z[N], ans[N], n;
char t[N];

int main() {
    int test = 0;
    while (scanf(" %d", &n) != EOF) {
        scanf(" %[^\n]", t);
        scanf(" %[^\n]", t+n);
        int m = strlen(t);
        int j = 0;
        int count = 0;
        for (int i = 1; i < m; i++) {
            z[i] = 0;
            if (i > j+z[j]-1) {
                j = i;
                while (i+z[i] < m && t[i+z[i]] == t[z[i]]) 
                    z[i]++;
            }
            else {
                if (z[i-j] <= j+z[j]-1-i) z[i] = z[i-j];
                else {
                    z[i] = j+z[j]-1-i;
                    while (i+z[i] < m && t[i+z[i]] == t[z[i]])
                        z[i]++;
                }
            }
            if (z[i] >= n && i >= n)
                ans[count++] = i-n;
        }
        /*printf("%s\n", t);
        for (int i = 0; i <= m; i++)
            printf("%d", z[i]);
        printf("\n");*/
        if (count) {
            for (int i = 0; i < count; i++)
                printf("%d\n", ans[i]);
            printf("\n");
        }
    }
    return 0;
}

