#include<bits/stdc++.h>
using namespace std;

const int N = 1010, L = 25;
int t[N*L][27], s[N*L], slen[N];
char str[N][L];

int nt = 1;
void build(int x){
    int len = slen[x], p = 1, c;
    for(int i = 0; i < len; i++){
        c = str[x][i] - 'a';
        if(t[p][c] == 0){
            t[p][c] = ++nt;
        }
        p = t[p][c];
        s[p]++;
    }
}

void find_sp(int x){
    int len = slen[x], p = 1, c;
    for(int i = 0; i < len; i++){
        if(s[p] == 1) break;
        c = str[x][i] - 'a';
        printf("%c", str[x][i]);
        p = t[p][c];
    }
    printf("\n");
}

int cnt = 0;
int main(){
    while(scanf("%s", str[++cnt]) != EOF){
        slen[cnt] = strlen(str[cnt]);
        build(cnt);
    }
    for(int i = 1; i <= cnt; i++){
        printf("%s ", str[i]);
        find_sp(i);
    }
}