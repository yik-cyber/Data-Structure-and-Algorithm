#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
int fa[N];
int rel[N];


int get_fa(int x){
    if(x == fa[x]) return x;
    int t = get_fa(fa[x]);
    rel[x] = rel[x] ^ rel[fa[x]];
    fa[x] = t;
    return t;
}

void merge(int x,int y){
    int p = get_fa(x), q = get_fa(y);
    if(p == q) return;
    fa[q] = p;
    rel[q] = !(rel[x] ^ rel[y]);
    return;
}

int query(int x, int y){
    int p = get_fa(x), q = get_fa(y);
    if(p != q){
        return 2; //not known yet
    }
    return (rel[x] ^ rel[y]);
}

void init(int n){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        rel[i] = 0;
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        char cmd;
        int x, y;
        int n, m;
        scanf("%d %d", &n, &m);
        init(n);
        for(int i = 0; i < m; i++){
            getchar();
            scanf("%c %d %d", &cmd, &x, &y);
            if(cmd == 'D'){
                merge(x, y);
            }
            else{
                int ans = query(x, y);
                if(ans == 2){
                    printf("Not sure yet.\n");
                }
                else if(ans == 1){
                    printf("In different gangs.\n");
                }
                else{
                    printf("In the same gang.\n");
                }
            }
        }
    }
}
