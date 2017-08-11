#include <bits/stdc++.h>
using namespace std;

priority_queue<int> p;
int n, limak, ans, o;

int main() {
    scanf(" %d %d", &n, &limak);
    for (int i = 0; i < n-1; i++) {
        int x;
        scanf(" %d", &x);
        p.push(x);
    }
    o = limak;
    while (limak <= p.top()) {
        int aux = p.top();
        p.pop();
        limak++;
        p.push(--aux);
    }
    printf("%d\n", limak-o);
    return 0;
}

