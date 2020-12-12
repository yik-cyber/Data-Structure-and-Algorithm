#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, m;
int fa[N], gender[N];

int get_fa(int x){
    if(x == fa[x]) return x;
    int t = get_fa(fa[x]);
    gender[x] = gender[x] ^ gender[fa[x]];
    return fa[x] = t;
}

bool merge(int x, int y){
    int p = get_fa(x), q = get_fa(y);
    if(p != q){
        fa[q] = p;
        gender[q] = !(gender[x] ^ gender[y]);
        return true;
    }
    else return (gender[x] ^ gender[y]);
}


int main(){
    int cas;
    scanf("%d", &cas);
    for(int i = 1; i <= cas; i++){
        scanf("%d %d", &n, &m);
        for(int j = 1; j <= n; j++){
            fa[j] = j;
            gender[j] = 0;
        }
        int x, y;
        bool flag = true;
        for(int j = 1; j <= m; j++){
            scanf("%d %d", &x, &y);
            if(!flag) continue;
            if(!merge(x, y)) flag = false;
        }
        printf("Scenario #%d:\n", i);
        if(!flag) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        printf("\n");
    }
}