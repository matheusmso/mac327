#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
int n;
pair<pii, int> p[100000];

int solve(pii i, pii j, pii k) {
    lint a = (lint)(i.first-k.first)*(j.second-i.second);
    lint b = (lint)(i.first-j.first)*(k.second-i.second);
    return a != b;
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d %d", &p[i].first.first, &p[i].first.second);
        p[i].second = i+1;
    }
    sort(p, p+n);
    for (int i = 2; i < n; i++)
        if (solve(p[0].first, p[1].first, p[i].first)) {
            printf("%d %d %d\n", p[0].second, p[1].second, p[i].second);
            return 0;
        }
    return 0;
}

