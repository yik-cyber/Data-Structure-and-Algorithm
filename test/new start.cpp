#include<bits/stdc++.h>
using namespace std;

const int N = 310;
int g[N][N];
int n,i,j;
int cost[N];
bool vis[N];
struct Node{
    public:
    int u, v, w;
    
};
bool operator<(Node a, Node b){
        return a.w > b.w;
}
int prim(){
    int tot = 0;
    memset(vis, false, sizeof(vis));
    Node t;
    priority_queue<Node> nq;
    t.u = 0, t.v = n + 1, t.w = 0;
    nq.push(t);
    int cnt = 0;
    while(!nq.empty() && cnt < n + 1){
        Node p = nq.top();
        nq.pop();
        if(vis[p.v]) continue;
        tot += p.w;
        cnt++;
        vis[p.v] = true;

        for(i = 1; i <= n + 1; i++){
            if(g[p.v][i] > 0 && !vis[i]){
                t.u = t.v;
                t.v = i;
                t.w = g[p.v][i];
                nq.push(t);
            }
        }
    }
    return tot;
}

int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &g[n+1][i]);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++) scanf("%d", &g[i][j]);
    }
    int ans = prim();
    printf("%d", ans);
}