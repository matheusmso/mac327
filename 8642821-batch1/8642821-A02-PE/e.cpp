#include <bits/stdc++.h>
using namespace std;

char s[120];

int main() {
    scanf(" %s", &s);
    int len = strlen(s);
    int t = 0;
    bool flag = false;
    for (int i = len-1; i >= 0 && !flag; i--) {
        t = s[i]-'0';
        if (t%8 == 0) {
            printf("YES\n%d\n", t);
            return 0;
        }
        for (int j = i-1; j >= 0 && !flag; j--) {
            int aux = t+(s[j]-'0')*10;
            if (aux%8 == 0) {
                printf("YES\n%d\n", aux);
                return 0;
            }
            for (int k = j-1; k >= 0 && !flag; k--) {
                int aux2 = aux+(s[k]-'0')*100;
                if (aux2%8 == 0) {
                    printf("YES\n%d\n", aux2);
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}
