#include<bits/stdc++.h>
using namespace std;


int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        priority_queue<int, vector<int>, greater<int> > pq;
        int tmp;
        for(int i = 0; i < n; i ++){
            scanf("%d", &tmp);
            pq.push(tmp);
        }
        int ans = 0;
        while(pq.size() > 1){
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();
            ans += (t1 + t2);
            pq.push(t1+t2);
            
        }
        printf("%d\n", ans);
    }
}
