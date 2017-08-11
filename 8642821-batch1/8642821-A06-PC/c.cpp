#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5+7;
char s[N];
int z[N];
int f[N], c[N];

int main() {
    scanf(" %s", s);
    int j = 0;
    int n = strlen(s);
    for (int i = 1; i < n; i++) {
        if (i > j+z[j]-1) {
            j = i;
            while (i+z[i] < n && s[i+z[i]] == s[z[i]])
                z[i]++;
        }
        else {
            if (z[i-j] <= j+z[j]-1-i) z[i] = z[i-j];
            else {
                z[i] = j+z[j]-1-i;
                while (i+z[i] < n && s[i+z[i]] == s[z[i]])
                    z[i]++;
            }
        }
    }
    z[0] = n;
    for (int i = 0; i < n; i++)
        if (z[i])
            f[z[i]]++;
    int t = 0;
    for (int i = 0; i <= n; i++)
        t += f[i];
    for (int i = 0; i <= n; i++) {
        c[i] = t;
        t -= f[i];
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) 
        if (i+z[i] == n)
            ans.push_back(make_pair(z[i], c[z[i]]));
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (pair<int, int> x : ans)
        printf("%d %d\n", x.first, x.second);
    return 0;
}

