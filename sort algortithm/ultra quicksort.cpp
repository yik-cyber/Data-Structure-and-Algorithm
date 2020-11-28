#include<bits/stdc++.h>
using namespace std;

const int N = 500000 + 10;
long long a[N];
long long cal(int s, int e){
    if(s == e) return 0;
    if(e - s == 1){
        return a[s] > a[e] ? 1 : 0;
    }
    int m = (s + e) >> 1;
    long long l = cal(s, m);
    long long r = cal(m + 1, e);
    sort(a + s, a + m + 1, greater<long long>());
    sort(a + m + 1, a + e + 1, greater<long long>());
    long long tot = 0;
    int i = s, j = m + 1;
    while(i <= m && j <= e){
        while(j <= e && a[i] <= a[j]) j++;
        if(j <= e) tot += (e - j + 1);
        i++;
    }
    return tot + l + r;
}

int main(){
    int t;
    long long ans = 0;
    while(scanf("%d", &t) && t){
        memset(a, 0, sizeof(0));
        for(int i = 0; i < t; i++){
            scanf("%d", &a[i]);
        }
        ans = cal(0, t - 1);
        printf("%d\n", ans);
    }
}