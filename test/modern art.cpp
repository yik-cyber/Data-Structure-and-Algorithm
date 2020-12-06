#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 100000 + 10;
int a[N];
int tot[N], cnt[N];
int n, top, i, ans;
int st[N];

int main(){
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        tot[a[i]]++;
    }
    top = -1, ans = -1;
    for(i = 0; i < n; i++){
        if(!a[i]){
            if(top >= 0){
                printf("-1");
                return 0;
            }
        }
        else{
            if((++cnt[a[i]]) == 1){
                st[++top] = a[i];
                ans = max(ans, top);
            }
            if(cnt[a[i]] == tot[a[i]]){
                if(st[top] != a[i]){
                    printf("-1");
                    return 0;
                }
                else top--; 
            }
        }
    }
    printf("%d", ans + 1);
}
