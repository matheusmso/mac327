#include <bits/stdc++.h>
#define move ahsudhasudh
#define debug(args...) fprintf(stderr, args)
using namespace std;


int n;
char ans[100];
int move[] = {-4, 1, 4, -1};
map<vector<int>, int> m;
vector<int> t;

bool solvable(int start) {
    int count = 0;
    for (int i = 0; i < 15; i++)
        for (int j = i+1; j < 16; j++)
            if (t[i] && t[j] && t[i] > t[j])
                count++;
    start = 4-start/4;
    return start%2 != count%2;
}

int dist() {
    int d = 0;
    for (int i = 0; i < 16; i++) {
        if (t[i])
            d += abs((t[i]-1)/4-i/4)+abs((t[i]-1)%4-i%4);
    }
    return d;
}

bool go(int x, int last, int cont) {
    //debug("x = %d, last = %d, cont = %d\n", x, last, cont);
    if (cont > 50) return false;
    //if (m.count(t) && m[t] <= cont) return false;
    int aux = dist();
    if (cont+aux > 50) return false;
    if (x == 15) {
        if (aux == 0) {
            for (int i = 0; i < cont; i++) 
                printf("%c", ans[i]);
            printf("\n");
            return true;
        }
    }
    //m[t] = cont;
    for (int i = 0; i < 4; i++) {
        if (move[i] != -last) {

            if (move[i] == -4 && x/4 != 0) {
                swap(t[x], t[x-4]);
                ans[cont] = 'U';
                if (go(x-4, move[i], cont+1)) return true;
                ans[cont] = 0;
                swap(t[x], t[x-4]);
            }
            else if (move[i] == 4 && x/4 != 3) {
                swap(t[x], t[x+4]);
                ans[cont] = 'D';
                if (go(x+4, move[i], cont+1)) return true;
                ans[cont] = 0;
                swap(t[x], t[x+4]);
            }
            else if (move[i] == 1 && x%4 != 3) {
                swap(t[x], t[x+1]);
                ans[cont] = 'R';
                if (go(x+1, move[i], cont+1)) return true;
                ans[cont] = 0;
                swap(t[x], t[x+1]);
            }
            else if (move[i] == -1 && x%4 != 0) {
                swap(t[x], t[x-1]);
                ans[cont] = 'L';
                if (go(x-1, move[i], cont+1)) return true;
                ans[cont] = 0;
                swap(t[x], t[x-1]);
            }
        }
    }
    return false;
}

int main() {
    scanf(" %d", &n);
    while (n--) {
        int start;
        for (int i = 0; i < 16; i++) {
            int x;
            scanf(" %d", &x);
            t.push_back(x);
            if (!t[i])
                start = i;
        }
        if (!solvable(start))
            printf("This puzzle is not solvable.\n");
        else if (!go(start, 0, 0))
            printf("This puzzle is not solvable.\n");
        m.clear();
        t.clear();
        memset(ans, 0, sizeof(ans));
    }
    return 0;
}

