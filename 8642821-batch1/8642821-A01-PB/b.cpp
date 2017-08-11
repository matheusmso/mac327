#include <bits/stdc++.h>
using namespace std;

char s[100];
int v[6] = {1, 3, 2, -1, -3, -2};

int main() {
        scanf(" %s", &s);
        int ans = 0;
        int j = 0;
        for (int i = strlen(s)-1; i >= 0; i--) {
                ans += v[j%6]*(s[i]-'0');
                j++;
        }
        printf("%d\n", ((ans%7)+7)%7);
        return 0;
}

