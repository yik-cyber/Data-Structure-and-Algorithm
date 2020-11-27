#include<bits/stdc++.h>
using namespace std;

const int N = 27;
const int M = 16;
struct Edge{
    public:
    int to, next, w;
}edge[N*M];
bool operator<(Edge a, Edge b){
    return a.w > b.w;
}
int head[N];
bool vis[N];
int n, k;

int tot = 0;
void add(char u, char v, int w){
    int a = u - 'A' + 1, b = v - 'A' + 1;
    edge[++tot].to = b;
    edge[tot].w = w;
    edge[tot].next = head[a];
    head[a] = tot;
}
int prim(){
    Edge t;
    priority_queue<Edge> nq;
    for(int i = head[1]; i != -1; i = edge[i].next){
        t = edge[i];
        nq.push(t);
    }
    vis[1] = true;
    int cnt = 1, sum = 0;
    while(!nq.empty() && cnt < n){
        t = nq.top();
        nq.pop();

        if(vis[t.to]) continue;
        
        sum += t.w;
        cnt++;
        vis[t.to] = true;
        for(int i = head[t.to]; i != -1; i = edge[i].next){
            if(!vis[edge[i].to]) nq.push(edge[i]);
        }
    }
    return sum;
}

int main(){
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    char c, t;
    int w;
    for(int i = 1; i <= n-1; i++){
        getchar();
        scanf("%c %d", &c, &k);
        while(k--){
            getchar();
            scanf("%c %d", &t, &w);
            add(c, t, w);
            add(t, c, w);
        }
    }
    cout << prim();
}
