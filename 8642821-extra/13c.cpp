#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<string> d[7];
set<string> s;

void go(string k, int t) {
    if (t == 0) {
        s.insert(k);
        return;
    }
    for (int i = 0; i < d[k[0]-'a'].size(); i++)
        go(d[k[0]-'a'][i]+k, t-1);
}

int main() {
    scanf(" %d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        d[s2[0]-'a'].push_back(s1);
    }
    go("a", n-1);
    printf("%d\n", s.size());
    return 0;
}

