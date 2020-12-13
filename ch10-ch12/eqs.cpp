#include<bits/stdc++.h>
using namespace std;
const int N = 99991;
int a1, a2, a3, a4, a5;
long long num[10000000 + 10];
int head[N + 10], cnext[N + 10];

int cnt = 0;
void add_hash(long long x){
    int p = x % N;
    num[++cnt] = x;
    cnext[cnt] = head[p];
    head[p] = cnt;
}
int ans = 0;
void find_hash(int p, long long x){
    for(int i = head[p]; i != -1; i = cnext[i]){
        if(num[i] == x) ans++;
    }
}

int main(){
    scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
    memset(head, -1, sizeof(head));
    memset(cnext, -1, sizeof(cnext));
    for(int i = -50; i <= 50; i++){
        if(i == 0) continue;
        for(int j = -50; j <= 50; j++){
            if(j == 0) continue;
            long long x = a1*(i*i*i) + a2*(j*j*j);
            x < 0? add_hash(-x): add_hash(x);
        }
    }
    
    for(int i = -50; i <= 50; i++){
        if(i == 0) continue;
        for(int j = -50; j <= 50; j++){
            if(j == 0) continue;
            for(int k = -50; k <= 50; k++){
                if(k == 0) continue;
                long long x = a3*(i*i*i) + a4*(j*j*j) + a5*(k*k*k);
                find_hash(x < 0 ? (-x) % N: x % N, -x);
            }
        }
    }
    printf("%d", ans);
}