#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6+7;
int f, s, g, u, d;
int seen[N];

int main() {
    scanf(" %d %d %d %d %d", &f, &s, &g, &u, &d);
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    seen[s] = 1;
    while (!q.empty()) {
        pair<int ,int> p = q.front();
        q.pop();
        seen[p.first] = 1;
        if (p.first == g) {
            printf("%d\n", p.second);
            return 0;
        }
        int aux = p.first-d;
        if (aux > 0 && seen[aux] == 0) {
            q.push(make_pair(aux, p.second+1));
            seen[aux] = 1;
        }
        aux = p.first+u;
        if (aux < f+1 && seen[aux] == 0) {
            q.push(make_pair(aux, p.second+1));
            seen[aux] = 1;
        }
    }
    printf("use the stairs\n");
    return 0;
}

