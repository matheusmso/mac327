#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf(" %d", &n);
    string s = "abc";
    if (n == 1) {
        printf("1 : a\n");
        n = 0;
    }
    else if (n == 2) {
        printf("1 : NO\n");
        printf("2 : ab\n");
        n = 0;
    }
    for (int i = 1; i <= n; i++) {
        int k = i-3;
        printf("%d : ", i);
        if (k < 0)
            printf("NO");
        else {
            for (int j = 0; j < k; j++)
                putchar('a');
            for (int j = 0; j < n-k; j++)
                putchar(s[j%3]);
        }
        printf("\n");
    }
    return 0;
}
