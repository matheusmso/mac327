#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6+7;
char s1[N], s2[N];

int main() {
    scanf(" %s", s1);
    scanf(" %s", s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int m1, m2;
    m1 = m2 = 0;
    for (int i = 0; i < n1; i++) {
        if (s1[i] != '0')
            break;
        else
            m1++;
    }
    for (int i = 0; i < n2; i++) {
        if (s2[i] != '0') 
            break;
        else
            m2++;
    }
    int k1 = n1-m1;
    int k2 = n2-m2;
    if (k1 > k2)
        printf(">\n");
    else if (k2 > k1)
        printf("<\n");
    else {
        for (int i = 0; i < min(k1, k2); i++) {
            if (s1[i+m1] > s2[i+m2]) {
                printf(">\n");
                return 0;
            }
            else if (s1[i+m1] < s2[i+m2]) {
                printf("<\n");
                return 0;
            }
        }
        printf("=\n");
    }
    return 0;
}


