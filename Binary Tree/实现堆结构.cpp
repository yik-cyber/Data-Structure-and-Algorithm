#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while (test--){
        int n;
        scanf("%d", &n);
        int cmd, x;
        priority_queue<int, vector<int>, greater<int> > hp;
        while(n--){
            scanf("%d", &cmd);
            if(cmd == 1){
                scanf("%d", &x);
                hp.push(x);
            }
            else{
                printf("%d\n", hp.top());
                hp.pop();
            }
        }
    }
    
}
