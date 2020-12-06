#include<bits/stdc++.h>
using namespace std;

const int N = 20000 + 10;
int a[N];
int n;
int nixudui(int s, int e){
    if(s == e) return 0;
    if(s + 1 == e){
        return a[s] > a[e] ? 1 : 0;
    }
    int l, r, k, m;
    m = (s + e) >> 1;
    l = nixudui(s, m);
    r = nixudui(m+1, e);
    sort(a + s, a + m + 1, greater<int>());
    sort(a + m + 1, a + e + 1, greater<int>());
    int i = s, j = m + 1;
    k = 0;
    while(i <= m && j <= e){
        while(j <= e && a[j] >= a[i]) j++;
        k += (e - j + 1);
        i++;
    }
    return l + r + k;
}
int main(){
    while(scanf("%d", &n) && n){
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        printf("%d\n", nixudui(0, n - 1));
    }
}