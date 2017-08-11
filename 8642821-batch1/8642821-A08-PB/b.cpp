#include <bits/stdc++.h>
using namespace std;
int n, w;
char trans[300];
char dic[1007][100];
char line[100];
char *word[20];
int size[20];
int used[300];
bool sol;
int sizedic[1007];

void go(int k) {
    //printf("%d\n", k);
    if (k == w) {
        sol = true;
        for (int i = 0; i < w; i++) {
            if (i) printf(" ");
            for (int j = 0; j < size[i]; j++) {
                printf("%c", trans[word[i][j]]);
            }
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (sizedic[i] == size[k]) {
            vector<int> back;
            bool flag = true;
            for (int j = 0; j < size[k]; j++) {
                int c = 0;
                if (trans[word[k][j]] == dic[i][j]);
                else if (trans[word[k][j]] == 0 && used[dic[i][j]] == 0) {
                    trans[word[k][j]] = dic[i][j];
                    used[dic[i][j]] = 1;
                    back.push_back(j);
                }
                else {
                    for (int a : back) {
                        used[dic[i][a]] = 0;
                        trans[word[k][a]] = 0;
                    }
                    flag = false;
                    break;
                }
            }
            if (flag)
                go(k+1);
            if (sol) return;
            for (int a : back) {
                used[dic[i][a]] = 0;
                trans[word[k][a]] = 0;
            }
        }
    }
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %s", dic[i]);
        sizedic[i] = strlen(dic[i]);
    }
    while (scanf(" %[^\n]", line) != EOF) {
        memset(trans, 0, sizeof(trans));
        memset(used, 0, sizeof(used));
        sol = false;
        char *wo = strtok(line, " ");
        w = 0;
        while (wo != NULL) {
            size[w] = strlen(wo);
            word[w++] = wo;
            wo = strtok(NULL, " ");
        }
        go(0);
        if (!sol) {
            for (int i = 0; i < w; i++) {
                if (i) printf(" ");
                for (int j = 0; j < size[i]; j++)
                    printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
