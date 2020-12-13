#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int fa[N];
bool sign[N];

int get_fa(int x){
    if(x == fa[x]) return x;
    int t = get_fa(fa[x]);
    sign[x] = (sign[x] ^ sign[fa[x]]);
    return fa[x] = t;
}

bool merge(int x,int y, bool s){
    int p = get_fa(x), q = get_fa(y); // x < y
    if(p != q){
        fa[q] = p;
        sign[q] = sign[x] ^ sign[y] ^ s;
        return true;        
    }
    else return ((sign[x] ^ sign[y]) == s);
}
int n, m;
map<int, int> mp;
int main(){
    int u, v, cnt = 0;
    char ch[10];
    bool f;
    scanf("%d", &n);
    for(int i = 1; i <= N; i++){
        fa[i] = i;
        sign[i] = false;
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %s", &u, &v, ch);
        if(u > v) swap(u, v);
        f = (ch[0] == 'o' ? true : false);
        if(mp.find(u-1) == mp.end()) mp[u-1] = ++cnt;
        if(mp.find(v) == mp.end()) mp[v] = ++cnt;
        if(!merge(mp[u-1], mp[v], f)){
            printf("%d", i - 1);
            return 0;
        }
    }
    printf("%d", m);
}