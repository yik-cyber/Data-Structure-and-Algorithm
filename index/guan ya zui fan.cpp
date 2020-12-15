#include<bits/stdc++.h>
using namespace std;

const int N = 20000 + 10;
const int M = 100000 + 10;
struct Edge{
    public:
    int u, v, w;
}edge[M << 1];
bool operator<(Edge a, Edge b){
    return a.w >= b.w;
}
int fa[N << 1];
int get_fa(int x){
    return x == fa[x]? x : fa[x] = get_fa(fa[x]);
}
int n, m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= (n << 1); i++) fa[i] = i;
    int x, y, w;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &x, &y, &w);
        edge[i].u = x; edge[i].v = y; edge[i].w = w;
    }
    sort(edge + 1, edge + m + 1);
    for(int i = 1; i <= m; i++){
        int u = edge[i].u, v = edge[i].v;
        int p = get_fa(u), q = get_fa(v);
        if(p == q){
            printf("%d", edge[i].w);
            return 0;
        }
        fa[p] = get_fa(v + n);
        fa[q] = get_fa(u + n);
    }
    printf("0");
    
}
