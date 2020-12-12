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

void merge(int x, int y){
    int p = get_fa(x), q = get_fa(y);
    if(p != q){
        rel[q] = !(rel[x] ^ rel[y]);
        fa[q] = p;
    }
}

int query(int x, int y){
    int p = get_fa(x), q = get_fa(y);
    if(p != q) return 2;
    return rel[x] ^ rel[y];
}
int n, m;
int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            fa[i] = i;
            rel[i] = 0;
        }
        char cmd[3];
        int x, y;
        for(int i = 1; i <= m; i++){
            scanf("%s", cmd);
            scanf("%d %d", &x, &y);
            if(cmd[0] == 'D') merge(x, y);
            else {
                int ans = query(x, y);
                switch(ans){
                    case 0:
                        printf("In the same gang.\n");
                        break;
                    case 1:
                        printf("In different gangs.\n");
                        break;
                    default:
                        printf("Not sure yet.\n");
                }
            }
        }
    }
}