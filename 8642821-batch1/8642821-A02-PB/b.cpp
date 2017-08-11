#include <bits/stdc++.h>
using namespace std;

int v[10007];

int main() {
    int n;
    scanf(" %d", &n);
    while (n > 1) {
        int k = n;
        while (k%2 == 0) {
            v[2]++;
            k /= 2;
        }
        for (int i = 3; i* i <= k; i += 2) {
            while (k%i == 0) {
                v[i]++;
                k /= i;
            }
        }
        if (k > 2)
            v[k]++;
        n--;
    }
    string s = "";
    for (int i = 0; i < 10007; i++) {
        if (v[i])
            s += to_string(i)+"^"+to_string(v[i])+" * ";
    }
    for (int i = 0; i < s.size()-3; i++)
        printf("%c", s[i]);
    printf("\n");
    return 0;
}
