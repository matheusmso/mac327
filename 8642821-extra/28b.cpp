#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
map<int, int> m;
priority_queue<pair<int, int>> pq;
int n, ans[N], t;

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf(" %d", &x);
        m[x]++;
    }
    for (pair<int, int> p : m)
        pq.push(make_pair(p.second, p.first));
    while (pq.size() > 2) {
        pair<int, int> p[3];
        for (int i = 0; i < 3; i++) {
            p[i] = pq.top();
            pq.pop();
        }
        for (int i = 0; i < 3; i++) 
            ans[t++] = p[i].second;
        for (int i = 0; i < 3; i++)
            if (p[i].first > 1) 
                pq.push(make_pair(p[i].first-1, p[i].second));
    }
    printf("%d\n", t/3);
    int i = 0;
    while (i < t) {
        sort(ans+i, ans+i+3);
        printf("%d %d %d\n", ans[i+2], ans[i+1], ans[i]);
        i += 3;
    }
    return 0;
}


