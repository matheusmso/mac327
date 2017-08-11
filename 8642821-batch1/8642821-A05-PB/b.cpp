#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6+7;
int z[N];
char s[N];

int main() {
    scanf(" %s", s);
    int n = strlen(s);
    int j = 0;
    int m = 0;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        z[i] = 0;
        if (i > j+z[j]-1) {
            j = i;
            while (i+z[i] < n && s[i+z[i]] == s[z[i]]) 
                z[i]++;
        }
        else {
            if (z[i-j] <= j+z[j]-1-i) z[i] = z[i-j];
            else {
                z[i] = j+z[j]-1-i;
                while (i+z[i] < n && s[i+z[i]] == s[z[i]]) 
                    z[i]++;
            }
        }
        if (i+z[i] == n && z[i] <= m) 
            ans = max(ans, z[i]);
        m = max(m, z[i]);
    }
    if (ans) {
        for (int i = 0; i < ans; i++)
            printf("%c", s[i]);
        printf("\n");
    }
    else
        printf("Just a legend\n");
    return 0;
}

