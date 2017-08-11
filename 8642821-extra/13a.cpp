#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char s[207];
    scanf(" %d %s", &n, s);
    int x, y, ans = 0;
    for(int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            x = y = 0;
            for (int k = i; k <= j; k++) {
                if (s[k] == 'U') y++;
                else if (s[k] == 'D') y--;
                else if (s[k] == 'L') x--;
                else x++;
            }
            if (x == 0 && y == 0) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

