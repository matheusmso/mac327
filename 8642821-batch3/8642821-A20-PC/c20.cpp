#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint N = (lint) 3e5+7;
lint b, p, l, n;
lint v[N], s[N], f[N];

lint fexp(lint b, lint e) {
    b %= p;
    if (e == 0) return 1;
    return (((e&1) ? b : 1) * fexp(b*b, e/2))%p;
}

void update(lint pos, lint value) {
    lint id = l-pos-1;
    pos += l;
    v[pos] = value*fexp(b, id)%p;
    pos /= 2;
    while (pos) {
        v[pos] = (v[2*pos]+v[2*pos+1])%p;
        pos /= 2;
    }
}

lint query(lint e, lint d) {
    lint ans = 0;
    e += l;
    d += l;
    while (e < d) {
        if (e&1)
            ans = (ans+v[e++])%p;
        if (d&1) 
            ans = (ans+v[--d])%p;
        e /= 2;
        d /= 2;
    }
    return ans;
}

int main() {
    while (scanf(" %lld %lld %lld %lld", &b, &p, &l, &n) && b != 0) {
        memset(v, 0, sizeof(v));
        for (lint i = 0; i < n; i++) {
            char c;
            lint e, d;
            scanf(" %c %lld %lld", &c, &e, &d);
            if (c == 'E') update(--e, d);
            else {
                lint k = fexp(b, p-2);
                lint g = fexp(k, l-d);
                printf("%lld\n", g*query(--e, d)%p);
            }
        }
        //for (int i = 0; i < 2*l; i++) 
            //printf("i %d val %d\n", i, v[i]);
        //printf("\n");
        printf("-\n");
    }
    return 0;
}

