#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5+7;
string s[2];
int z[2][N];
map <int, int> m;

void zf(int x) {
    int n = s[x].size();
    int j = 0;
    for (int i = 1; i < n; i++) {
        z[x][i] = 0;
        if (i > j+z[x][j]-1) {
            j = i;
            while (i+z[x][i] < n && s[x][i+z[x][i]] == s[x][z[x][i]])
                z[x][i]++;
        }
        else {
            if (z[x][i-j] <= j+z[x][j]-1-i) z[x][i] = z[x][i-j];
            else {
                z[x][i] = j+z[x][j]-1-i;
                while (i+z[x][i] < n && s[x][i+z[x][i]] == s[x][z[x][i]])
                    z[x][i]++;
            }
        }
    }
    z[x][0] = s[x].size();
}

int main() {
    cin >> s[0] >> s[1];
    for (int x = 0; x < 2; x++) {
        zf(x);
        for (int i = 0; i < s[x].size(); i++) {
            bool flag = true;
            if (z[x][i] && s[x].size()%z[x][i] == 0) {
                for (int j = 0; j < s[x].size(); j++) {
                    if (s[x][j] != s[x][j%z[x][i]]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    m[z[x][i]]++;
            }
        }
    }
    /*for (int x = 0; x < 2; x++) {
        for (int i = 0; i < s[x].size(); i++)
            printf("%d ", z[x][i]);
        printf("\n");
    }*/
    int ans = 0;
    int k = 0;
    bool f = true;
    for (pair <int, int> p : m) {
        if (p.second == 2) {
            for (int i = k; i < p.first && f; i++)
                if (s[0][i] != s[1][i])
                    f = false;
            if (!f) break;
            ans++;
            k = p.first;
        }
    }
    printf("%d\n", ans);
    return 0;
}
