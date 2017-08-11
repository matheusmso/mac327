#include <bits/stdc++.h>
using namespace std;

typedef long long lint;
int v[8][3];
int h[] = {12, 12, 4};
map<lint, int> m;
lint dist(lint i, lint j, lint k, lint m, lint n, lint o) {
    return (i-m)*(i-m) + (j-n)*(j-n) + (k-o)*(k-o);
}

int check() {
    if (m.size() == 3) {
        int i = 0;
        for (pair<lint, int> p : m) {
            if (p.second != h[i++])
                return 0;
        }
        return 1;
    }
    return 0;   
}

int solve (int l) {
    if (l == 8) {
        if (check()) {
            printf("YES\n");
            for (int i = 0; i < 8; i++)
                printf("%d %d %d\n", v[i][0], v[i][1], v[i][2]);
            return 1;
        }
        else return 0;
    }
    sort(v[l], v[l]+3);
    do {
        for (int i = l-1; i > -1; i--) m[dist(v[i][0], v[i][1], v[i][2],
                v[l][0], v[l][1], v[l][2])]++;
        if (m.size() < 4 && solve(l+1)) return 1;
        for (int i = l-1; i > -1; i--) {
            lint aux = dist(v[i][0], v[i][1], v[i][2],
                    v[l][0], v[l][1], v[l][2]);
            m[aux]--;
            if (m[aux] == 0) m.erase(aux);
        }
    } while (next_permutation(v[l], v[l]+3));
            return 0;
}

int main() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 3; j++)
            scanf(" %d", &v[i][j]);
    if (!solve(0)) printf("NO\n");
    return 0;
}

