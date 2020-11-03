#include<bits/stdc++.h>
using namespace std;

const int N = 50000 + 10;
int fa[N];
int get_fa(int x){
    return x == fa[x]? x : fa[x] = get_fa(fa[x]);
}

void merge(int x, int y){
    int p = get_fa(x), q = get_fa(y);
    fa[q] = p;
}

int main(){
    int n, m, t = 1;
    while(scanf("%d %d", &n, &m) && n && m){
        for(int i = 1; i <= n; i++) fa[i] = i;
        
        int x, y, ans = 0;
        while (m--){
            scanf("%d %d", &x, &y);
            merge(x, y);
        }
        for(int i = 1; i <= n; i++){
            if(get_fa(i) == i) ans++;
        }
        printf("Case %d: %d\n", t++, ans);
        
    }
}
