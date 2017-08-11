#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
char s[N];

int main() {
    scanf(" %s", s);
    int n = strlen(s);
    int b = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') b++;
        else if (s[i] == ')')
            if (b > 0) {
                ans++;
                b--;
            }
    }
    printf("%d\n", 2*ans);
    return 0;
}

