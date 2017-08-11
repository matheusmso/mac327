#include <bits/stdc++.h>
using namespace std;
#define index hausdha
int v[10007], n, aux[10007], sum;

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i]);
    memset(aux, -1, sizeof(aux));
    aux[0] = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (aux[sum%n] != -1) {
            printf("%d\n", i+1-aux[sum%n]);
            for (int p = aux[sum%n]; p <= i; p++)
                printf("%d\n", v[p]);
            break;
        }
        else
            aux[sum%n] = i+1;
    }
    return 0;
}

