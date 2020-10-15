#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s[N];
int cnext[N];
int n;

int main(){
    int cnt = 0;
    while(scanf("%d", &n) && n){
        scanf("%s", s+1);
        printf("Test case #%d\n", ++cnt);
        cnext[1] = 0;
        for(int i = 2, j = 0; i <= n; i++){
            while (j > 0 && s[i] != s[j+1]) j = cnext[j];
            if(s[i] == s[j+1]) j++;
            cnext[i] = j;
        }
        for(int pre = 2; pre <= n; pre++){
            if(cnext[pre] == 0) continue;
            if(pre == cnext[pre]){
                printf("%d %d\n", pre, pre);
                continue;
            }
            if(cnext[pre] % (pre - cnext[pre]) == 0){
                printf("%d %d\n", pre, cnext[pre] / (pre-cnext[pre]) + 1);
            }
        }
        printf("\n");
        memset(s, '\0', sizeof(s));
        memset(cnext, 0, sizeof(cnext));
    }
}
