#include <bits/stdc++.h>
using namespace std;

int n, k;
char s[100007];

int main() {
    scanf(" %d %d", &n, &k);
    scanf(" %s", &s);
    int m = 0;
    for (int i = 0; i < n; i++)
        m += max(s[i]-'a', 'z'-s[i]);
    if (m < k)
        printf("-1\n");
    else {
        int i = 0;
        while (k) {
            int aux = max(s[i]-'a', 'z'-s[i]);
            if (k >= aux)
                printf("%c", s[i]-aux>='a' ? s[i]-aux : s[i]+aux);
            else 
                printf("%c", s[i]-k>='a' ? s[i]-k : s[i]+k);
            k = max(k-aux, 0);
            i++;
        }
        while (i < n)
            printf("%c", s[i++]);
        printf("\n");
    }
    return 0;
}

