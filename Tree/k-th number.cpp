#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int a[N];
int sorted[N];

struct Node{
    public:
    int l, r;
    vector<int> num;
    int mid(){return (l + r) >> 1;}
}t[N << 2];
int n, m;

void build(int p, int l, int r){
    t[p].l = l, t[p].r = r;
    if(l == r){
        t[p].num.push_back(a[l]);
        return;
    }
    int tm = t[p].mid();
    int lc = 2 * p + 1, rc = 2 * p + 2;
    build(lc, l, tm);
    build(rc, tm + 1, r);
    t[p].num.resize(t[lc].num.size() + t[rc].num.size());
    merge(t[lc].num.begin(), t[lc].num.end(), t[rc].num.begin(), t[rc].num.end(),t[p].num.begin());
}

int query(int p, int l, int r, int x){
    if(t[p].l >= l && t[p].r <= r){
        return upper_bound(t[p].num.begin(), t[p].num.end(), x) - t[p].num.begin();
    }
    int tm = t[p].mid();
    int lc = 2 * p + 1, rc = 2 * p + 2;
    if(r <= tm) return query(lc, l, r, x);
    else if(l > tm) return query(rc, l, r, x);
    else return query(lc, l, tm, x) + query(rc, tm + 1, r, x);
}

int ask(int li, int ri, int k){
    int l = 1, r = n + 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(query(1, li, ri, sorted[mid]) >= k) r = mid;
        else l = mid + 1;
    }
    return sorted[l];
}
int main(){
    scanf("%d %d", &n, &m);
    int i, j;
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sorted[i] = a[i];
    }
    sort(sorted + 1, sorted + n + 1);
    build(1, 1, n);
    int ll, rr, kk;
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &ll, &rr, &kk);
        int ans = ask(ll, rr, kk);
        printf("%d\n", ans);
    }
}