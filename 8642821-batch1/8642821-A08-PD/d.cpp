#include <bits/stdc++.h>
using namespace std;

int n, e, answer;
vector<int> adj[107];
int ans[107];
int sol[107];

void go(int k) {
    if (k == n+1) {
        int r = 0;
        int aux = 0;
        for (int i = 1; i <= n; i++)
            if (ans[i] == 1)
                aux++;
        if (aux > answer) {
            answer = aux;
            for (int i = 1; i <= n; i++) 
                if (ans[i] == 1)
                    sol[r++] = i;
        }
        return;
    }
    vector<int> back;
    if (ans[k] == 0) {
        ans[k] = 1;
        bool flag = true;
        for (int x : adj[k]) {
            if (ans[x] == 1) {
                flag = false;
                break;
            }
            else if (ans[x] == 0){
                ans[x] = -1;
                back.push_back(x);
            }
        }
        if (flag)
            go(k+1);
        for (int x : back)
            ans[x] = 0;
        ans[k] = 0;
        ans[k] = -1;
        go(k+1);
        ans[k] = 0;
    }
    else if (ans[k] == 1) {
        bool flag = true;
        for (int x : adj[k]) {
            if (ans[x] == 1) {
                flag = false;
                break;
            }
            else if (ans[x] == 0) {
                ans[x] = -1;
                back.push_back(x);
            }
        }
        if (flag)
            go(k+1);
        for (int x : back)
            ans[x] = 0;
    }
    else if (ans[k] == -1)
        go(k+1);
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d", &n, &e);
        for (int i = 0; i < 107; i++)
            adj[i].clear();
        memset(ans, 0, sizeof(ans));
        memset(sol, 0, sizeof(sol));
        answer = 0;
        for (int i = 0; i < e; i++) {
            int u, v;
            scanf(" %d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        go(1);
        printf("%d\n", answer);
        for (int i = 0; i < answer; i++) {
            if (i) printf(" ");
            printf("%d", sol[i]);
        }
        printf("\n");
    }
    return 0;
}
