#include <bits/stdc++.h>
using namespace std;

char s[150];
int n;
map<char, int> m;

int main() {
    scanf(" %d", &n);
    scanf(" %s", &s);
    for (int i = 0; i < n; i++)
        m[tolower(s[i])]++;
    if (m.size() == 26)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

