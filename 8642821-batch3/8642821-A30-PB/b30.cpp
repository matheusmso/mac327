#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
map<string, int> m;
int n;
string d[N];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = n-1; i > -1; i--) {
        if (m[d[i]] == 0) {
            cout << d[i] << endl;
            m[d[i]]++;
        }
    }
    return 0;
}

