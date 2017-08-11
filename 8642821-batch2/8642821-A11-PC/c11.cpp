#include <bits/stdc++.h>
using namespace std;
typedef long double ldouble;
map<string, int> m;
int n, e;
ldouble d[32][32];

int main() {
    int test = 1;
    while (scanf(" %d", &n) && n) {
        for (int i = 0; i < 32; i++)
            for (int j = 0; j < 32; j++)
                d[i][j] = 0.0;
        m.clear();
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            m[s] = i;
        }
        scanf(" %d", &e);
        for (int i = 0; i < e; i++) {
            ldouble x;
            string u, v;
            cin >> u >> x >> v;
            int a, b;
            a = m[u];
            b = m[v];
            d[a][b] = x;
        }
        for (int k = 0; k < n; k++) 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) 
                    d[i][j] = max(d[i][j], d[i][k]*d[k][j]);
        bool flag = false;
        for (int i = 0; i < n && !flag; i++)
            if (d[i][i] > 1.0)
                flag = true;
        printf("Case %d: ", test++);
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}

