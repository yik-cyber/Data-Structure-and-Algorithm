#include<bits/stdc++.h>
using namespace std;

const int N = 210;
struct Node{
    public:
    int u, v;
    double w;
};
bool operator<(Node a, Node b){
    return a.w < b.w;
}
int n;
double xp[N], yp[N];
int fa[N];
vector<Node> edges;

int get_fa(int x){
    return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
bool merge(int x, int y){
    int p = get_fa(x), q = get_fa(y);
    if(p == q) return false;
    else fa[q] = p;
    return true;
}
int main(){
    int cas = 0;
    while(scanf("%d", &n) && n != 0){
        for(int i = 1; i <= n; i++){
            fa[i] = i;
            scanf("%lf %lf", &xp[i], &yp[i]);
        }
        Node tn;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                double t = sqrt(pow((xp[i]-xp[j]), 2) + pow(yp[i] - yp[j], 2));
                tn.u = i, tn.v = j, tn.w = t;
                edges.push_back(tn);
            }
        }
        double minmaxj = 0;
        sort(edges.begin(), edges.end());
        for(int i = 0; i < edges.size(); i++){
            tn = edges[i];
            if(merge(tn.u, tn.v)){
                if(minmaxj < tn.w) minmaxj = tn.w;
            }
            if(get_fa(1) == get_fa(2)) break;
        }
        if(cas) printf("\n");
        printf("Scenario #%d\nFrog Distance = %.3lf\n", ++cas, minmaxj);
        edges.clear();
    }
}