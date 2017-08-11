#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e4+7;
char s[N], buffer[N];

int main() {
    scanf(" %s", s);
    int m;
    scanf(" %d", &m);
    while (m--) {
        int l, r, k;
        scanf(" %d %d %d", &l, &r, &k);
        l--;
        r--;
        int size = r-l+1;
        for (int i = 0; i < size; i++) 
            buffer[(i+k)%size] = s[i+l];
        for (int i = l; i <= r; i++)
            s[i] = buffer[i-l];
    }
    printf("%s\n", s);
    return 0;
}

