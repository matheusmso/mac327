#include <bits/stdc++.h>
using namespace std;

string s;
int n, l;

int main() {
    cin >> l;
    getline(cin, s);
    while (l--) {
        getline(cin, s);
        n = s.size();
        stack<char> p;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[')
                p.push(s[i]);
            else if (s[i] == ')') {
                if (p.empty() || p.top() != '(') {
                    p.push('0');
                    break;
                }
                p.pop();
            }
            else if (s[i] == ']') {
                if (p.empty() || p.top() != '[') {
                    p.push('0');
                    break;
                }
                p.pop();
            }
        }
        printf("%s\n", p.empty() ? "Yes" : "No");
    }
    return 0;
}

