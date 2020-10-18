#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
char s[N];
int cnext[N];

void find_next(int lens){
    cnext[1] = 0;
    int j = 0;
    for(int i = 2; i <= lens; i++){
        while(j > 0 && s[i] != s[j+1]) j = cnext[j];
        if(s[i] == s[j+1]) j++;
        cnext[i] = j;
    }
}

int main(){
    while(scanf("%s", s+1)){
        if(s[1] == '.') break;
        int len = strlen(s+1);
        find_next(len);
        if(cnext[len] != 0 && (cnext[len] % (len - cnext[len]) == 0)){
            printf("%d\n", len / (len - cnext[len])
            );
            continue;
        }
        printf("1\n");
    }
}
