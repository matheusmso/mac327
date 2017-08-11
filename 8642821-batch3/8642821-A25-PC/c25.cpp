#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
char s[N];

int main() {
    scanf(" %s", s);
    int n = strlen(s);
    int ans = 0;
    stack<char> p;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '{' || c == '(' || c == '<' || c == '[')
            p.push(c);
        else {
            if (p.empty()) {
                printf("Impossible\n");
                return 0;
            }
            else if (p.top()+1 == c || p.top()+2 == c) p.pop();
            else {
                ans++;
                p.pop();
            }
        }
    }
    if (!p.empty()) printf("Impossible\n");
    else printf("%d\n", ans);
    return 0;
}

