#include<bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;

char str[N][30];
int t[30*N][30], s[30*N];

int cnt = 1;
void insert(char ch[]){
    int len = strlen(ch);
    int p = 1, k;
    for(int i = 0; i < len; i++){
        k = ch[i] - 'a';
        if(t[p][k] == 0){
            t[p][k] = ++cnt; 
        }
        p = t[p][k];
        s[p]++; //next station
    }
}

void ask(char ch[]){
    int len = strlen(ch);
    int p = 1, k;
    for(int i = 0; i < len; i++){
        if(s[p] == 1) break;
        k = ch[i] - 'a';
        printf("%c", ch[i]);   
        p = t[p][k];
    }
    return;
}

int main(){
    int i = 0;
    while(scanf("%s", str[++i]) != EOF){
        insert(str[i]);
    }
    for(int j = 1; j < i; j++){
        printf("%s ", str[j]);
        ask(str[j]);
        printf("\n");
    }
}